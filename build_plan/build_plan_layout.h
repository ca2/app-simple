// Created by camilo on 2026-07-06 01:53 <3ThomasBorregaardSorensen!!
#pragma once


#include "acme/graphics/draw2d/color_array.h"
#include "apex/platform/app_consumer.h"
#include "berg/user/user/form_handler.h"
#include "berg/user/user/impact.h"


namespace app_simple_build_plan
{


   class CLASS_DECL_APP_SIMPLE_BUILD_PLAN build_plan_layout
       : virtual public app_consumer<application, ::user::line_layout, berg::form_handler>

   {
   public:


      //::pointer<render>          m_prender;

      ::string m_strId;


      class string_column : virtual public ::particle
      {
      public:
         ::pointer_array<string_array> m_str2a;
         ::index_array m_iaCurrent;
         ::color_array m_coloraBackground;
         ::color_array m_coloraText;
         void add_row(::collection::index iLine, berg::form_handler *pformhandler, ::user::line_layout *plinelayout,
                      const ::scoped_string &scopedstr, const ::procedure &procedureUpdate, bool bStatus,
                      bool bSimplified);

         ::string get_row_payload(int iLine);
      };

      ::pointer<string_column> m_pcolumnDateStart;
      ::pointer<string_column> m_pcolumnDateEnd;
      ::pointer<string_column> m_pcolumnStatus;
      ::pointer_array<::user::plain_edit> m_editaComment;

      build_plan_layout();
      ~build_plan_layout() override;


      //      // void assert_ok() const override;
      //      // void dump(dump_context & dumpcontext) const override;



      virtual void update_build_plan_from_storage();

      virtual void send_build_plan_to_storage();


   };


} // namespace app_simple_build_plan
