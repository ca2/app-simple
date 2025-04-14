#include "framework.h"
//#include "NFSProg.h"
//#include "acme/filesystem/file/memory_file.h"
//#include "acme/constant/filesystem.h"
//#include "nfs_server_application.h"
//
//#define BUFFER_SIZE 1024
//
//#define PRINT_EXTRA_LOG 9
//
//
//nfsstat3 CNFS3Prog::ProcedureWRITE(void)
//{
//   std::string path;
//   offset3 offset;
//   count3 count;
//   stable_how stable;
//   opaque data;
//   wcc_data file_wcc;
//   writeverf3 verf;
//   nfsstat3 stat;
//
//   PrintLog("WRITE");
//   bool validHandle = GetPath(path);
//   const char * cStr = validHandle ? path.c_str() : NULL;
//   Read(&offset);
//   Read(&count);
//   Read(&stable);
//#if PRINT_EXTRA_LOG > 6
//   {
//      ::string strExtraLog;
//      strExtraLog.formatf("[0x%016llx, 0x%08x](%lld, %d) %d valid_handle=%d", offset, count, offset, count, stable, validHandle);
//      PrintLog(strExtraLog);
//   }
//#endif
//   Read(&data);
//   stat = CheckFile(cStr);
//
//   if (stat == NFS3_OK) {
//
//      if (stable == UNSTABLE) {
//         ::pointer < ::memory_file >  pfile;
//
//         nfs_fh3 handle;
//         GetFileHandle(cStr, &handle);
//         int handleId = *(unsigned int *)handle.contents;
//
//         if (unstableStorageFile.count(handleId) == 0) {
//            m_papplication->__construct_new(pfile);
//            if (pfile) {
//               unstableStorageFile.insert(std::make_pair(handleId, pfile));
//            }
//         }
//         else {
//            pfile = unstableStorageFile[handleId];
//         }
//
//         file_wcc.before.attributes_follow = GetUnstableFileAttributesForNFS(pfile, cStr, &file_wcc.before.attributes);
//
//         if (pfile != NULL) {
//            //_fseeki64(pFile, offset, SEEK_SET);
//            //count = fwrite(data.contents, sizeof(char), data.length, pFile);
//            pfile->translate(offset, ::e_seek_set);
//            pfile->write(data.contents, data.length);
//         }
//         else {
//            //char buffer[BUFFER_SIZE];
//            //errno_t errorNumber = errno;
//            //strerror_s(buffer, BUFFER_SIZE, errorNumber);
//            //PrintLog(buffer);
//
//            //if (errorNumber == 13) {
//            //   stat = NFS3ERR_ACCES;
//            //}
//            //else {
//            //   stat = NFS3ERR_IO;
//            //}
//         }
//         // this should not be zero but a timestamp (process start time) instead
//         verf = system()->m_timeStart.m_iSecond;
//         // we can reuse this, because no physical write has happend
//         //file_wcc.after.attributes_follow = file_wcc.before.attributes_follow;
//         file_wcc.after.attributes_follow = GetUnstableFileAttributesForNFS(pfile, cStr, &file_wcc.after.attributes);
//      }
//      else {
//         FILE * pFile;
//
//         file_wcc.before.attributes_follow = GetFileAttributesForNFS(cStr, &file_wcc.before.attributes);
//
//
//         pFile = _fsopen(cStr, "r+b", _SH_DENYWR);
//
//         if (pFile != NULL) {
//            _fseeki64(pFile, offset, SEEK_SET);
//            count = fwrite(data.contents, sizeof(char), data.length, pFile);
//            fclose(pFile);
//         }
//         else {
//            char buffer[BUFFER_SIZE];
//            errno_t errorNumber = errno;
//            strerror_s(buffer, BUFFER_SIZE, errorNumber);
//            PrintLog(buffer);
//
//            if (errorNumber == 13) {
//               stat = NFS3ERR_ACCES;
//            }
//            else {
//               stat = NFS3ERR_IO;
//            }
//         }
//
//         stable = FILE_SYNC;
//         verf = system()->m_timeStart.m_iSecond;
//
//         file_wcc.after.attributes_follow = GetFileAttributesForNFS(cStr, &file_wcc.after.attributes);
//      }
//   }
//
//   Write(&stat);
//   Write(&file_wcc);
//
//   if (stat == NFS3_OK) {
//      Write(&count);
//      Write(&stable);
//      Write(&verf);
//   }
//
//   return stat;
//}
//
