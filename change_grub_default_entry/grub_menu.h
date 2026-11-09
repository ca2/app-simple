#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <cctype>

namespace app_simple_change_grub_default_entry::grub_menu
{
   inline std::string shell_quote(const std::string & text)
   {
      std::string quoted = "'";
      for (char c : text) quoted += c == '\'' ? "'\"'\"'" : std::string(1, c);
      return quoted + "'";
   }

   struct entry
   {
      std::string title, id, index, title_path;

      std::string display_title() const
      {
         std::string label;
         for (char c : index) if (c == '>') label += "     ";
         return label + title;
      }
   };

   // Split GRUB shell headers without treating quoted titles or ${variables}
   // as commands or block boundaries.
   inline std::vector<std::string> tokens(const std::string & line)
   {
      std::vector<std::string> result;
      std::string word;
      char quote = 0;
      int variable = 0;
      auto flush = [&] { if (!word.empty()) { result.push_back(word); word.clear(); } };
      for (size_t i = 0; i < line.size(); ++i)
      {
         char c = line[i];
         if (c == '\\' && quote != '\'' && i + 1 < line.size()) { word += line[++i]; continue; }
         if (quote) { if (c == quote) quote = 0; else word += c; continue; }
         if (c == '\'' || c == '"') { quote = c; continue; }
         if (c == '#' && word.empty()) break;
         if (c == '{' && !word.empty() && word.back() == '$') { ++variable; word += c; continue; }
         if (variable) { if (c == '}') --variable; word += c; continue; }
         if (c == '{' || c == '}') { flush(); result.emplace_back(1, c); }
         else if (std::isspace(static_cast<unsigned char>(c))) flush();
         else word += c;
      }
      flush();
      return result;
   }

   inline std::vector<entry> parse(const std::string & config)
   {
      struct submenu { int depth; std::string id, index, title; size_t next = 0; };
      std::vector<submenu> parents;
      std::vector<entry> entries;
      std::istringstream input(config);
      std::string line;
      int depth = 0;
      size_t next = 0;
      while (std::getline(input, line))
      {
         auto words = tokens(line);
         if (words.empty()) continue;
         if ((words[0] == "menuentry" || words[0] == "submenu") && words.size() > 1)
         {
            const auto & title = words[1];
            std::string id = title;
            for (size_t i = 2; i < words.size(); ++i)
            {
               if ((words[i] == "--id" || words[i] == "$menuentry_id_option"
                  || words[i] == "${menuentry_id_option}") && i + 1 < words.size()) id = words[++i];
               else if (words[i].compare(0, 5, "--id=") == 0) id = words[i].substr(5);
            }
            auto index = std::to_string(parents.empty() ? next++ : parents.back().next++);
            auto id_path = parents.empty() ? id : parents.back().id + ">" + id;
            auto title_path = parents.empty() ? title : parents.back().title + ">" + title;
            auto index_path = parents.empty() ? index : parents.back().index + ">" + index;
            if (words[0] == "submenu") parents.push_back({depth + 1, id_path, index_path, title_path});
            else entries.push_back({title, id_path, index_path, title_path});
         }
         char quote = 0;
         for (size_t i = 0; i < line.size(); ++i)
         {
            char c = line[i];
            if (c == '\\' && quote != '\'' && i + 1 < line.size()) { ++i; continue; }
            if (quote) { if (c == quote) quote = 0; continue; }
            if (c == '\'' || c == '"') { quote = c; continue; }
            if (c == '#' && (i == 0 || std::isspace(static_cast<unsigned char>(line[i - 1])))) break;
            if (c == '{') ++depth;
            else if (c == '}') --depth;
         }
         while (!parents.empty() && depth < parents.back().depth) parents.pop_back();
      }
      return entries;
   }

   inline std::string default_entry(const std::string & config, const std::string & environment)
   {
      std::string saved, next, line;
      std::istringstream env(environment);
      while (std::getline(env, line))
      {
         if (!line.empty() && line.back() == '\r') line.pop_back();
         if (line.compare(0, 12, "saved_entry=") == 0) saved = line.substr(12);
         if (line.compare(0, 11, "next_entry=") == 0) next = line.substr(11);
      }
      if (!next.empty()) return next;
      std::string fallback = "0";
      std::istringstream cfg(config);
      while (std::getline(cfg, line))
      {
         auto words = tokens(line);
         if (words.size() < 2 || words[0] != "set" || words[1].compare(0, 8, "default=") != 0) continue;
         auto value = words[1].substr(8);
         if (value == "${saved_entry}" || value == "$saved_entry") return saved.empty() ? "0" : saved;
         // Skip the one-shot branch: next_entry was handled above.
         if (!value.empty() && value[0] != '$') fallback = value;
      }
      return fallback;
   }
}
