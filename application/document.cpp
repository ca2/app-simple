#include "framework.h"
#include "document.h"
#include "impact.h"
#include "application.h"
#include "acme/filesystem/filesystem/file_context.h"


namespace app_simple_application
{


   document::document()
   {

   }


   document::~document()
   {

   }


//   void document::assert_ok() const
//   {
//
//      ::user::document::assert_ok();
//
//   }
//
//
//   void document::dump(dump_context & dumpcontext) const
//   {
//
//      ::user::document::dump(dumpcontext);
//
//   }


   bool document::on_new_document()
   {

      ::file::path path;
      
      ::pointer < ::app_simple_application::application > papp = application();
      
      path = papp->m_pathApplicationText;

      //const char * pszPath = path.c_str();
      
      file()->get_lines(m_straLine, path);

      if (m_straLine.is_empty())
      {

         file()->get_lines(m_straLine, "document://application/app-simple/application/application.txt");

      }

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


   int64_t document::increment_reference_count()
   {

      return  ::user::document::increment_reference_count();

   }


   int64_t document::decrement_reference_count()
   {

      return  ::user::document::decrement_reference_count();

   }


#endif


} // namespace app_simple_application



