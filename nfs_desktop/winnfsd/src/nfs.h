#pragma once

#include "RPCServer.h"
#include "PortmapProg.h"
#include "NFSProg.h"
#include "MountProg.h"
#include "ServerSocket.h"
#include "DatagramSocket.h"
#include <stdio.h>
#include <direct.h>
#include <iostream>
#include <fstream>
#include <vector>


#define SOCKET_NUM 3
enum
{
   PORTMAP_PORT = 111,
   MOUNT_PORT = 1058,
   NFS_PORT = 2049
};
enum
{
   PROG_PORTMAP = 100000,
   PROG_NFS = 100003,
   PROG_MOUNT = 100005
};


class nfs :
   virtual public ::object
{
public:

   hostent * m_localHost;
   std::vector<std::vector<std::string>> pPaths;
   char * pPath = NULL;
   bool pathFile = false;
   //unsigned int m_nUID, m_nGID;
   bool m_bLogOn;
   char * m_sFileName;
   CRPCServer m_RPCServer;
   CPortmapProg m_PortmapProg;
   CNFSProg m_NFSProg;
   CMountProg m_MountProg;
   //nfs * m_pnfs;
   //const char * m_sInAddr;
   CDatagramSocket DatagramSockets[SOCKET_NUM];
   CServerSocket ServerSockets[SOCKET_NUM];


   WSADATA m_wsaData;



   ::string_array m_straLog;
   ::string m_strBuffer;
   ::file_pointer                                 m_pfileLog;


   //nfs_server * m_pnfsserver = nullptr;

   nfs();
   ~nfs() override;

   virtual void Print(const ::scoped_string & scopedstr);


   bool include_hostname_in_configuration_path() override;

   virtual ::string get_bind_address() const;
   virtual void set_bind_address(const ::scoped_string & scopedstrBindAddress);

   virtual int get_user_id() const;
   virtual void set_user_id(int iUserId);

   virtual int get_group_id() const;
   virtual void set_group_id(int iUserId);


   virtual ::file::path get_mount_path(int iIndex) const;
   virtual void set_mount_path(int iIndex, const ::file::path & path);

   virtual ::string get_mount_alias(int iIndex) const;
   virtual void set_mount_alias(int iIndex, const ::scoped_string & scopedstrAlias);

   virtual int get_mount_count();

   void printAbout();
   void printUsage(char * pFile);

   int main(int argc, char * argv[]);

   //-id 1001 1001 - addr 192.168.0.89 - pathFile C : / Dropbox / winnfsd.txt

   void netnode_from_ini_configuration();
   void run_netnode();

   void main_start(std::vector<std::vector<std::string>> paths);

   void start(std::vector<std::vector<std::string>> paths);
   void inputCommand();
   void printLine();
   void printHelp();
   void printList();
   void printCount();
   void printConfirmQuit();

   virtual int PrintLog(const char * format, ...);


   void mountPaths(std::vector<std::vector<std::string>> paths);

};



