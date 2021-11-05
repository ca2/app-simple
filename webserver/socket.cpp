// cs<3tbs!! 2020-11-28 21:16 BRT
#include "framework.h"
#include "_webserver.h"


namespace simple_webserver
{


   socket::socket() 
   {

   }


   socket::~socket()
   {

   }


   void socket::on_send_response()
   {

      string strHtml;

      auto psystem = m_psystem;

      auto pdatetime = psystem->datetime();

      strHtml += "<html>";
      strHtml += "<head>";
      strHtml += "<meta charset=\"UTF-8\">";
      // <from https://thomasbs.com/ <3tbs!!>
      strHtml += "<link href=\"https://fonts.googleapis.com/css?family=Fira+Code&display=swap\" rel=\"stylesheet\">";
      // </from https://thomasbs.com/ <3tbs!!>
      strHtml += "</head>";
      strHtml += "<body style=\"font-family:'Fira Code', monospace;\">";
      strHtml += "<h1>";
      strHtml += "🌌 🌍 [ ca2/C++/Windows ] Creating Simple Local Webserver";
      strHtml += "</h1>";
      strHtml += "<h4><a href=\"https://ca2.software/camilo\">cs</a><a href=\"https://ca2.io\">&lt;3</a><a href=\"https://thomasbs.com/\">tbs</a>!!</h4>";
      strHtml += "&lt;3TBS - ∞ - "+pdatetime->international().get_date_time() +"- +∞ - CA2(THWOASONE)";
      strHtml += "</body>";
      strHtml += "</html>";

      response().file()->write(strHtml);


   }


} // namespace simple_webserver



