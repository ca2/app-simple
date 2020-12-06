// cs<3tbs!! 2020-11-28 21:16 BRT
#include "framework.h"
#include "_webserver.h"


namespace simple_video
{


   socket::socket(::sockets::base_socket_handler & h) :
      ::object(&h),
      base_socket(h),
      ::sockets::socket(h),
      stream_socket(h),
      tcp_socket(h),
      http_base_socket(h),
      http_socket(h),
      ::sockets::httpd_socket(h),
      ::netserver::socket(h)
   {

   }


   socket::~socket()
   {

   }


   void socket::on_send_response()
   {

      string strHtml;

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
      strHtml += "<h4><a href=\"https://ca2.cc/camilo\">cs</a><a href=\"https://ca2.io\">&lt;3</a><a href=\"https://thomasbs.com/\">tbs</a>!!</h4>";
      strHtml += "&lt;3TBS - ∞ - "+System.datetime().international().get_gmt_date_time() +"- +∞ - CA2(THWOASONE)";
      strHtml += "</body>";
      strHtml += "</html>";

      response().file()->write(strHtml);


   }


} // namespace simple_video



