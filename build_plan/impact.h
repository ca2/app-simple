#pragma once


#include "berg/user/user/impact.h"
#include "apex/platform/app_consumer.h"
#include "berg/user/user/form_handler.h"
#include "acme/graphics/draw2d/color_array.h"


namespace app_simple_build_plan
{


   class CLASS_DECL_APP_SIMPLE_BUILD_PLAN impact :
      virtual public app_consumer < application, ::user::impact, berg::form_handler >
                                                      
   {
   public:


      //::pointer<render>          m_prender;


      class string_column :
         virtual public ::particle
      {
      public:
         ::pointer_array<string_array> m_str2a;
         ::index_array m_iaCurrent;
         ::color_array m_coloraBackground;
         ::color_array m_coloraText;
         void add_row(::collection::index iLine, berg::form_handler * pformhandler, ::user::line_layout *plinelayout,
                      const ::scoped_string &scopedstr, const ::procedure & procedureUpdate, bool bStatus, bool bSimplified);

         ::string get_row_payload(int iLine);
      };
      
      ::pointer<string_column> m_pcolumnDateStart;
      ::pointer<string_column> m_pcolumnDateEnd;
      ::pointer<string_column> m_pcolumnStatus;
      ::pointer_array<::user::plain_edit> m_editaComment;

      impact();
      ~impact() override;

      
//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;


#ifdef _DEBUG
      ::i64 increment_reference_count() override;
      ::i64 decrement_reference_count() override;
#endif


      void on_property_changed(::data::property_change & change) override;


      virtual void initialize_simple_build_plan(const ::scoped_string &scopedstr);
      virtual void install_message_routing(::channel * psender) override;

      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;

      ::user::document * get_document();

      //virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);

   };


} // namespace simple_build_plan


