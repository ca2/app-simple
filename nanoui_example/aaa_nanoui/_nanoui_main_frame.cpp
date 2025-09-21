#include "framework.h"



nanoui_main_frame::nanoui_main_frame()
{


}


nanoui_main_frame::~nanoui_main_frame()
{


}


void nanoui_main_frame::install_message_routing(::channel * psender)
{

   ::simple_main_frame::install_message_routing(psender);

   USER_MESSAGE_LINK(::user::e_message_create, psender, this, &nanoui_main_frame::on_message_create);

}


void nanoui_main_frame::on_message_create(::message::message * pmessage)
{

   _nanoui_to_main_frame();

}


void nanoui_main_frame::_nanoui_to_main_frame()
{



}


