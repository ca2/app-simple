#include "framework.h"
#include "application.h"
#include "document.h"
#include "edit_impact.h"
#include "main_impact.h"
#include "frame.h"
#include "main_frame.h"
#include "main_document.h"
#include "impact.h"
#include "tab_impact.h"
//#include "incoming_socket.h"
//#include "incoming_socket_thread.h"
//#include "socket.h"
#include "acme/filesystem/filesystem/file_system.h"
#include "acme/handler/request.h"
#include "berg/user/user/multiple_document_template.h"
#include "berg/user/user/single_document_template.h"
#include "app-simple/nfs_desktop/winnfsd/src/nfs.h"


__IMPLEMENT_APPLICATION_RELEASE_TIME(app_simple_nfs_desktop);
IMPLEMENT_APPLICATION_FACTORY(app_simple_nfs_desktop);


namespace app_simple_nfs_desktop
{


   // __IMPLEMENT_APPLICATION_RELEASE_TIME1(app_simple_nfs_desktop));


   application::application()
   {

      //m_ptemplateSimpleDrawingMain = nullptr;

      m_ptabimpact = nullptr;

      m_strAppId = "app-simple/nfs_desktop";

      m_strBaseSupportId = "ca2_flag";

      m_strAppName = "Nfs Desktop Application";

      m_bLicense = false;

      m_bEnableAutoStartOption = true;

   }


   application::~application()
   {

   }


   ::type_atom application::get_pane_impact_type() const
   {

      return ::type < tab_impact >();

   }


   void application::init_instance()
   {

      factory()->add_factory_item <::app_simple_nfs_desktop::document >();
      factory()->add_factory_item <::app_simple_nfs_desktop::frame >();
      factory()->add_factory_item <::app_simple_nfs_desktop::main_frame >();
      factory()->add_factory_item <::app_simple_nfs_desktop::tab_impact >();
      factory()->add_factory_item <::app_simple_nfs_desktop::main_document >();
      factory()->add_factory_item <::app_simple_nfs_desktop::edit_impact >();
      factory()->add_factory_item <::app_simple_nfs_desktop::main_impact >();

      factory()->add_factory_item <::app_simple_nfs_desktop::document >();
      factory()->add_factory_item <::app_simple_nfs_desktop::impact >();

      //factory()->add_factory_item <::app_simple_nfs_desktop::incoming_socket >();
      //factory()->add_factory_item <::app_simple_nfs_desktop::socket >();

      //default_toggle_check_handling("simple_checkbox");

      //default_toggle_check_handling("no_client_frame");

      ::berg::application::init_instance();

      //if (!::berg::application::init_instance())
      //{

      //   return false;

      //}
      add_impact_system("main", __initialize_new ::user::single_document_template(
                               "main",
                               ::type < ::app_simple_nfs_desktop::main_document >(),
                               ::type < ::app_simple_nfs_desktop::main_frame >(),
                               get_pane_impact_type()));

      //m_ptemplateSimpleDrawingMain = pdoctemplate;

      //add_document_template(pdoctemplate);

      //add_impact_system("impact", __initialize_new ::user::multiple_document_template(
      //   "command",
      //   ::type < main_document >(),
      //   ::type < main_frame >(),
      //   ::type < impact >()));

      //m_ptemplateCommand = pdoctemplate2;

      //add_document_template(pdoctemplate2);

      //default_data_save_handling("simple_checkbox");

      //default_data_save_handling("no_client_frame");

      //default_data_save_handling("simple_text");

      //ødefer_construct_new(m_pincomingsocketthread);

      //return true;

      //read_ini_configuration();

   }


   void application::term_application()
   {

      ::berg::application::term_application();

   }


   void application::on_request(::request * prequest)
   {

#if 0

#ifdef _DEBUG

      informationf("_DEBUG build? (basis)");

      ASSERT(false);

#else

      informationf("RELEASE build? (stage)");

      ASSERT(false);

#endif

#endif

      if (impact_system("main")->get_document_count() == 0)
      {

         if(prequest->m_egraphicsoutputpurpose & ::graphics::e_output_purpose_screen)
         {

            information() << "pcreate->m_bMakeVisible";

         }
         else
         {

            information() << "NOT pcreate->m_bMakeVisible";

         }

         impact_system("main")->request(prequest);

         return;

      }

      if (is_true("wfi_maximize"))
      {

         prequest->payload("document").cast < document >()->get_typed_impact < ::user::tab_impact >()->top_level_frame()->design_window_maximize();

      }


      //if (prequest->has_file())
      //{

      //   m_ptabimpact->add_tab(prequest->m_payloadFile.as_file_path().name(), prequest->m_payloadFile.as_file_path());
      //   m_ptabimpact->set_current_tab_by_id(prequest->m_payloadFile.as_file_path());

      //}

      informationf("----> finished simple_webserver::on_request");

   }




   void application::create_options_body(::user::interaction * pparent)
   {

      auto pstillBindAddress = create_label<::user::still>(pparent, "Bind Address");

      auto peditBindAddress = create_edit<::user::plain_edit>(pparent);

      peditBindAddress->set_size({ 300, 25 });

      ::string strBindAddress;
      
      strBindAddress = m_pnfs->get_bind_address();

      peditBindAddress->set_text(strBindAddress, ::e_source_initialize);

      peditBindAddress->m_callbackOnAfterChangeText = [this](::user::plain_edit * pedit, const ::action_context & actioncontext)
         {

            if (actioncontext.is_user_source())
            {

               ::string strBindAddress = pedit->get_text();

               m_pnfs->set_bind_address(strBindAddress);

            }

         };


      auto pstillUserId = create_label<::user::still>(pparent, "User Id");

      auto peditUserId = create_edit<::user::plain_edit>(pparent);

      peditUserId->set_size({ 300, 25 });

      int iUserId;

      iUserId = m_pnfs->get_user_id();

      peditUserId->set_text(::as_string(iUserId), ::e_source_initialize);

      peditUserId->m_callbackOnAfterChangeText = [this](::user::plain_edit * pedit, const ::action_context & actioncontext)
         {

            if (actioncontext.is_user_source())
            {

               ::string strUserId = pedit->get_text();

               m_pnfs->set_user_id(atoi(strUserId));

            }

         };

      auto pstillGroupId = create_label<::user::still>(pparent, "Group Id");

      auto peditGroupId = create_edit<::user::plain_edit>(pparent);

      peditGroupId->set_size({ 300, 25 });

      int iGroupId;

      iGroupId = m_pnfs->get_group_id();

      peditGroupId->set_text(::as_string(iGroupId), ::e_source_initialize);

      peditGroupId->m_callbackOnAfterChangeText = [this](::user::plain_edit * pedit, const ::action_context & actioncontext)
         {

            if (actioncontext.is_user_source())
            {

               ::string strGroupId = pedit->get_text();

               m_pnfs->set_group_id(atoi(strGroupId));

            }

         };


      for (int iIndex = 0; iIndex < 10; iIndex++)
      {

         auto pline = create_line_layout(pparent, e_orientation_horizontal);

         ::string strLabelMountPath;

         strLabelMountPath.formatf("Mount Path %d:", iIndex + 1);

         auto pstillMountPathd = create_label<::user::still>(pline, strLabelMountPath);

         auto peditMountPath = create_edit<::user::plain_edit>(pline);

         peditMountPath->set_size({ 300, 25 });

         ::string strMountPath = m_pnfs->get_mount_path(iIndex);

         peditMountPath->set_text(strMountPath, ::e_source_initialize);

         peditMountPath->m_callbackOnAfterChangeText = [this, iIndex](::user::plain_edit * pedit, const ::action_context & actioncontext)
            {

               if (actioncontext.is_user_source())
               {

                  ::string strMountPath = pedit->get_text();

                  m_pnfs->set_mount_path(iIndex, strMountPath);

               }

            };

         ::string strLabelMountAlias;

         strLabelMountAlias.formatf("Mount Alias %d:", iIndex + 1);

         auto pstillMountAlias = create_label<::user::still>(pline, strLabelMountAlias);

         auto peditMountAlias = create_edit<::user::plain_edit>(pline);

         peditMountAlias->set_size({ 300, 25 });

         ::string strMountAlias = m_pnfs->get_mount_alias(iIndex);

         peditMountAlias->set_text(strMountAlias, ::e_source_initialize);

         peditMountAlias->m_callbackOnAfterChangeText = [this, iIndex](::user::plain_edit * pedit, const ::action_context & actioncontext)
            {

               if (actioncontext.is_user_source())
               {

                  ::string strMountAlias = pedit->get_text();

                  m_pnfs->set_mount_alias(iIndex, strMountAlias);

               }

            };

      }

      auto pbuttonSave = create_button<::user::button>(pparent, "Save Configuration");

      pbuttonSave->m_callbackOnClick = [this](::user::interaction *, ::item *, ::user::activation_token * puseractivationtoken)
         {

            m_pnfs->write_ini_configuration();

            return true;

         };

      //auto pstill = øallocate ::user::still();

      //øconstruct_new(m_pedit);

      //øconstruct_new(m_pbuttonClear);

      //øconstruct_new(m_pbuttonSend);

      //øconstruct_new(m_pstillReceiver);

      //m_pstill->create_control(this, "still");

      //m_pedit->create_control(this, "edit");

      //m_pedit->add_handler(this);

      //m_pbuttonClear->create_control(this, "clear_button");

      //m_pbuttonClear->add_handler(this);

      //m_pbuttonSend->create_control(this, "send_button");

      //m_pbuttonSend->add_handler(this);

      //m_pstill->set_window_text("Enter ___new text:");

      //m_pstillReceiver->create_control(this, "still");

      //m_pstillReceiver->set_window_text("(Waiting to receive...)");

      //m_pedit->m_strEmtpyText = "Enter New Text Here";

      //string strInitialText;

      //auto papp = get_app();

      //papp->datastream()->get("last_text", strInitialText);

      //m_pedit->set_text(strInitialText, ::e_source_initialize);

      //m_pbuttonClear->set_window_text("Clear");

      //m_pbuttonSend->set_window_text("Send");

   }



   string application::preferred_experience()
   {

      return ::aura::application::preferred_experience();

   }


#ifdef _DEBUG


   long long application::increment_reference_count()
   {

      return ::object::increment_reference_count();

   }


   long long application::decrement_reference_count()
   {

      return ::object::decrement_reference_count();

   }


#endif


   //::pointer<impact> application::create_simple_drawing_impact(::user::impact* pimpactParent, ::user::impact_data * pimpactdata)
   //{

   //   return pimpactParent->create_impact < impact >(pimpactdata);

   //}


} // namespace app_simple_nfs_desktop



