#include "framework.h"
#include "RPCProg.h"
#include "nfs.h"
#include <stdarg.h>
#include <stdio.h>

CRPCProg::CRPCProg(nfs * pnfs) :
   m_pnfs(pnfs),
   CFileTableAccessor(&pnfs->m_filetable)
{
   m_bLogOn = true;
}

CRPCProg::~CRPCProg()
{
}

void CRPCProg::SetLogOn(bool bLogOn)
{
   m_bLogOn = bLogOn;
}

int CRPCProg::PrintLog(const char * format, ...)
{
   va_list vargs;
   int nResult;

   nResult = 0;

   if (m_bLogOn)
   {

      va_start(vargs, format);

      ::string str;

      str.formatf_arguments(format, vargs);

      m_pnfs->Print(str);

      va_end(vargs);

   }

   return 0;

}
