#include "framework.h"
#include "document.h"
#include "impact.h"
#include "application.h"


namespace app_simple_application
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
      
      auto papp = get_app();
      
      auto & file = papp->file();
      
      file.get_lines(m_straLine, "dropbox-app://application.txt");

      if (m_straLine.is_empty())
      {

         file.get_lines(m_straLine, "document://app_simple_application.txt");

      }

      return true;
      //return ::user::document::on_new_document();

   }


   bool document::on_open_document(const ::payload & payloadFile)
   {

      impact * pimpact = get_type_impact < impact >();

      if(pimpact == NULL)
      {

         return true;

      }

      return true;

   }


#ifdef _DEBUG


   int64_t document::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return  ::user::document::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


   int64_t document::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return  ::user::document::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


#endif


   stream& document::write(::stream& stream) const
   {

      return stream;

   }


} // namespace simple_application



