#include "framework.h"



namespace app_simple_nanoui_example
{


   document::document()
   {

   }


   document::~document()
   {

   }


   void document::assert_ok() const
   {

      ::user::document::assert_ok();

   }


   void document::dump(dump_context & dumpcontext) const
   {

      ::user::document::dump(dumpcontext);

   }


   bool document::on_new_document()
   {
      
      //auto papp = get_app();
      
      //auto & file = papp->file();
      
      return true;
      //return ::user::document::on_new_document();

   }


   bool document::on_open_document(const ::payload & payloadFile)
   {

      impact * pimpact = get_typed_impact < impact >();

      if(pimpact == NULL)
      {

         return true;

      }

      return true;

   }


#ifdef _DEBUG


   long long document::increment_reference_count()
   {

      return  ::user::document::increment_reference_count();

   }


   long long document::decrement_reference_count()
   {

      return  ::user::document::decrement_reference_count();

   }


#endif


   stream& document::write(::stream& stream) const
   {

      return stream;

   }


} // namespace simple_application



