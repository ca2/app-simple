#include "framework.h"
#include "document.h"
#include "impact.h"
#include "application.h"
#include "acme/filesystem/filesystem/file_context.h"


namespace app_simple_box
{


   document::document()
   {

   }


   document::~document()
   {

   }


   //void document::assert_ok() const
   //{

   //   ::user::document::assert_ok();

   //}


   //void document::dump(dump_context & dumpcontext) const
   //{

   //   ::user::document::dump(dumpcontext);

   //}


   bool document::on_new_document()
   {
      
      auto papp = get_app();
      
      auto pfile = papp->file();
      
      pfile->lines(m_straLine, "dropbox://app_simple_application.txt");

      if (m_straLine.is_empty())
      {

         pfile->lines(m_straLine, "document://app_simple_application.txt");

      }

      return true;

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


   //stream& document::write(::stream& stream) const
   //{

   //   return stream;

   //}


} // namespace app_simple_box



