// Created by camilo on 2025-04-12 23:11 <3ThomasBorregaardSorensen!!
#include "framework.h"
//#include "nfs_server_application.h"
//#include "nfs_server.h"
//#include "acme/parallelization/synchronous_lock.h"
//#include "acme/filesystem/filesystem/file_context.h"
//#include "acme/filesystem/filesystem/directory_system.h"
//
////
////nfs_server_application::nfs_server_application()
////{
////
////   m_pnfsserver = new nfs_server(this);
////
////}
////
////
////nfs_server_application::~nfs_server_application()
////{
////
////   delete m_pnfsserver;
////
////}
//
////
////void nfs_server_application::read_ini()
////{
////
////   m_set = file_system()->parse_ini("dropbox-app://configuration.ini");
////
////}
////
////
////void nfs_server_application::write_ini()
////{
////
////   file_system()->set_ini("dropbox-app://configuration.ini", m_set);
////
////}
//
//
//::string nfs_server_application::get_bind_address() const
//{
//
//   return m_set["bind-address"].as_string();
//
//}
//
//
//void nfs_server_application::set_bind_address(const ::scoped_string & scopedstrBindAddress)
//{
//
//   m_set["bind-address"] = scopedstrBindAddress;
//
//}
//
//
//
//
//void nfs_server_application::Print(const ::scoped_string & scopedstr)
//{
//
//   synchronous_lock synchronouslock(synchronization(), DEFAULT_SYNCHRONOUS_LOCK_SUFFIX);
//
//   m_strBuffer += scopedstr;
//
//   ::collection::index iFind = -1;
//
//   while (( iFind = m_strBuffer.find_index('\n')) >= 0)
//   {
//      
//      m_straLog.add(m_strBuffer.substr(0, iFind));
//
//      m_strBuffer = m_strBuffer.substr(iFind + 1);
//
//   }
//
//   try
//   {
//      
//      if (!m_pfileLog)
//      {
//
//         ::file::path pathFolder = directory_system()->home();
//
//         ::file::path path = pathFolder / "nfs_log.txt";
//
//         m_pfileLog = file()->get_file(path, ::file::e_open_create | ::file::e_open_write | ::file::e_open_no_truncate | ::file::e_open_share_deny_none); 
//
//      }
//      
//      m_pfileLog->translate(0, ::e_seek_from_end);
//      
//      m_pfileLog->write(scopedstr, scopedstr.size());
//
//   }
//   catch (...)
//   {
//
//      m_pfileLog.release();
//
//   }
//
//}
//
//
//
//
