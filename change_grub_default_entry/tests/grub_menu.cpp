#include "../grub_menu.h"
#include <cassert>

int main()
{
   using namespace app_simple_change_grub_default_entry::grub_menu;
   const std::string config = R"GRUB(
if [ "${next_entry}" ]; then
 set default="${next_entry}"
else
 set default="${saved_entry}"
fi
menuentry 'Linux main' --class linux $menuentry_id_option 'linux-id' {
 echo "quoted } brace"
 linux /vmlinuz root=${root}
}
submenu 'Advanced options' $menuentry_id_option 'advanced-id' {
  menuentry 'Linux recovery' --id recovery-id {
    if test x; then
      echo '{'
    fi
  }
  submenu 'Older' --id=older-id {
    menuentry "Old kernel" --id old-id { }
  }
}
menuentry 'Firmware settings' { }
)GRUB";
   auto entries = parse(config);
   assert(entries.size() == 4);
   assert(entries[0].display_title() == "Linux main");
   assert(entries[1].display_title() == "     Linux recovery");
   assert(entries[2].display_title() == "          Old kernel");
   assert(entries[0].id == "linux-id" && entries[0].index == "0");
   assert(entries[1].id == "advanced-id>recovery-id" && entries[1].index == "1>0");
   assert(entries[2].id == "advanced-id>older-id>old-id" && entries[2].index == "1>1>0");
   assert(entries[2].title_path == "Advanced options>Older>Old kernel");
   assert(entries[3].id == "Firmware settings" && entries[3].index == "2");
   assert(default_entry(config, "saved_entry=linux-id\n###") == "linux-id");
   assert(default_entry(config, "saved_entry=linux-id\nnext_entry=advanced-id>recovery-id\n") == entries[1].id);
   assert(default_entry("set default=\"1>0\"", "saved_entry=unused\n") == "1>0");
   assert(default_entry("set default='Firmware settings'", "") == "Firmware settings");
   assert(default_entry("", "") == "0");
   assert(parse("# menuentry 'comment' {}\n").empty());
   assert(tokens("menuentry 'Bob\\s Linux' --id=x { # comment").size() == 4);
}
