// Created by camilo on 2022/03/18 03:14 AM <3ThomasBorregaardS�rensen!! (Thomas Like number 5)
#pragma once
//Mummi at office during dawn
//youngmatti_
//VerFX
//strager
//j_blow
//rw_grim
//nanoui freelancing client


class nanoui_main_frame :
   virtual public simple_main_frame
{
public:


   nanoui_main_frame();
   ~nanoui_main_frame();

   
   void install_message_routing(::channel * psender) override;


   DECLARE_MESSAGE_HANDLER(on_message_create);


   virtual void _nanoui_to_main_frame();


};

