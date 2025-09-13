#include "framework.h"
#include "Socket.h"
#include "nfs.h"
#include "acme/filesystem/filesystem/directory_system.h"
#include "acme/filesystem/filesystem/file_context.h"
#include "acme/parallelization/synchronous_lock.h"


nfs::nfs() :
   DatagramSockets{ {this},{this}, {this} },
   ServerSockets{ {this},{this}, {this} },
   m_bLogOn(true), m_sFileName(NULL) ,
   m_PortmapProg(this),
   m_NFSProg(this),
   m_MountProg(this)

{
   //m_pfiletable = new CFileTable();

}

nfs::~nfs()
{
   for (int i = 0; i < SOCKET_NUM; i++) 
   {
      DatagramSockets[i].Close();
      ServerSockets[i].Close();
   }

   //delete m_pfiletable;
}


bool nfs::include_hostname_in_configuration_path()
{

   return true;

}


::string nfs::get_bind_address() const
{

   return property("bind_address").as_string();

}


void nfs::set_bind_address(const ::scoped_string & scopedstrBindAddress)
{

   property("bind_address") = scopedstrBindAddress;

}


int nfs::get_user_id() const
{

   return property("user_id").as_int();

}


void nfs::set_user_id(int iUserId)
{

   property("user_id") = iUserId;

}


int nfs::get_group_id() const
{

   return property("group_id").as_int();

}


void nfs::set_group_id(int iUserId)
{

   property("group_id") = iUserId;

}



::file::path nfs::get_mount_path(int iIndex) const
{
   
   ::string strMountPath;

   strMountPath.formatf("mount_path_%d", iIndex + 1);

   return property(strMountPath).as_file_path();

}


void nfs::set_mount_path(int iIndex, const ::file::path & path)
{

   ::string strMountPath;

   strMountPath.formatf("mount_path_%d", iIndex + 1);

   property(strMountPath) = path;

}


::string nfs::get_mount_alias(int iIndex) const
{

   ::string strMountAlias;

   strMountAlias.formatf("mount_alias_%d", iIndex + 1);

   return property(strMountAlias).as_string();

}


void nfs::set_mount_alias(int iIndex, const ::scoped_string & scopedstrAlias)
{

   ::string strMountAlias;

   strMountAlias.formatf("mount_alias_%d", iIndex + 1);

   property(strMountAlias) = scopedstrAlias;

}


int nfs::get_mount_count()
{

   int iCount = 0;

   while (get_mount_path(iCount).has_character()
      && get_mount_alias(iCount).has_character())
   {

      iCount++;

   }

   return iCount;

}



void nfs::Print(const ::scoped_string & scopedstr)
{

   synchronous_lock synchronouslock(synchronization(), DEFAULT_SYNCHRONOUS_LOCK_SUFFIX);

   m_strBuffer += scopedstr;

   ::collection::index iFind = -1;

   while ((iFind = m_strBuffer.find_index('\n')) >= 0)
   {

      m_straLog.add(m_strBuffer.substr(0, iFind));

      m_strBuffer = m_strBuffer.substr(iFind + 1);

   }

   try
   {

      if (!m_pfileLog)
      {

         ::file::path pathFolder = directory_system()->home();

         ::file::path path = pathFolder / "nfs_log.txt";

         m_pfileLog = file()->get_file(path, ::file::e_open_create | ::file::e_open_write | ::file::e_open_no_truncate | ::file::e_open_share_deny_none);

      }

      m_pfileLog->translate(0, ::e_seek_from_end);

      m_pfileLog->write(scopedstr, scopedstr.size());

   }
   catch (...)
   {

      m_pfileLog.release();

   }

}




void nfs::printUsage(char *pExe)
{
    printf("\n");
    printf("Usage: %s [-id <uid> <gid>] [-log on | off] [-pathFile <file>] [-addr <ip>] [export path] [alias path]\n\n", pExe);
    printf("At least a file or a path is needed\n");
    printf("For example:\n");
    printf("On Windows> %s d:\\work\n", pExe);
    printf("On Linux> mount -t nfs 192.168.12.34:/d/work mount\n\n");
    printf("For another example:\n");
    printf("On Windows> %s d:\\work /exports\n", pExe);
    printf("On Linux> mount -t nfs 192.168.12.34:/exports\n\n");
    printf("Another example where WinNFSd is only bound to a specific interface:\n");
    printf("On Windows> %s -addr 192.168.12.34 d:\\work /exports\n", pExe);
    printf("On Linux> mount - t nfs 192.168.12.34: / exports\n\n");
    printf("Use \".\" to export the current directory (works also for -filePath):\n");
    printf("On Windows> %s . /exports\n", pExe);
}

void nfs::printLine(void)
{
    printf("=====================================================\n");
}

void nfs::printAbout(void)
{
    printLine();
    printf("WinNFSd {{VERSION}} [{{HASH}}]\n");
    printf("Network File System server for Windows\n");
    printf("Copyright (C) 2005 Ming-Yang Kao\n");
    printf("Edited in 2011 by ZeWaren\n");
    printf("Edited in 2013 by Alexander Schneider (Jankowfsky AG)\n");
	printf("Edited in 2014 2015 by Yann Schepens\n");
	printf("Edited in 2016 by Peter Philipp (Cando Image GmbH), Marc Harding\n");
    printLine();
}

void nfs::printHelp(void)
{
    printLine();
    printf("Commands:\n");
    printf("about: display messages about this program\n");
    printf("help: display help\n");
    printf("log on/off: display log messages or not\n");
    printf("list_base: list_base mounted clients\n");
    printf("refresh: refresh the mounted folders\n");
    printf("reset: reset the service\n");
    printf("quit: quit this program\n");
    printLine();
}

void nfs::printCount()
{
    int nNum;

    nNum = m_MountProg.GetMountNumber();

    if (nNum == 0) {
        printf("There is no client mounted.\n");
    } else if (nNum == 1) {
        printf("There is 1 client mounted.\n");
    } else {
        printf("There are %d clients mounted.\n", nNum);
    }
}

void nfs::printList(void)
{
    int i, nNum;

    printLine();
    nNum = m_MountProg.GetMountNumber();

    for (i = 0; i < nNum; i++) {
        printf("%s\n", m_MountProg.GetClientAddr(i));
    }

    printCount();
    printLine();
}

void nfs::printConfirmQuit(void)
{
    printf("\n");
    printCount();
    printf("Are you sure to quit? (y/N): ");
}

void nfs::mountPaths(std::vector<std::vector<::string>> paths)
{
	int i;
	int numberOfElements = paths.size();

	for (i = 0; i < numberOfElements; i++) {
		char *pPath = (char*)paths[i][0].c_str();
		char *pPathAlias = (char*)paths[i][1].c_str();
		m_MountProg.Export(pPath, pPathAlias);  //export path for mount
	}
}

void nfs::inputCommand(void)
{
	char command[20];

	printf("Type 'help' to see help\n\n");

	while (true) {
		fgets(command, 20, stdin);

		if (command[strlen(command) - 1] == '\n') {
			command[strlen(command) - 1] = '\0';
		}

		if (_stricmp(command, "about") == 0) {
			printAbout();
		} else if (_stricmp(command, "help") == 0) {
			printHelp();
		} else if (_stricmp(command, "log on") == 0) {
			m_RPCServer.SetLogOn(true);
		} else if (_stricmp(command, "log off") == 0) {
			m_RPCServer.SetLogOn(false);
		} else if (_stricmp(command, "list_base") == 0) {
			printList();
		} else if (_stricmp(command, "quit") == 0) {
			if (m_MountProg.GetMountNumber() == 0) {
				break;
			} else {
				printConfirmQuit();
				fgets(command, 20, stdin);

				if (command[0] == 'y' || command[0] == 'Y') {
					break;
				}
			}
		} else if (_stricmp(command, "refresh") == 0) {
			m_MountProg.Refresh();
		} else if (_stricmp(command, "reset") == 0) {
			m_RPCServer.Set(PROG_NFS, NULL);
		} else if (strcmp(command, "") != 0) {
			printf("Unknown command: '%s'\n", command);
			printf("Type 'help' to see help\n");
		}
	}
}


int nfs::PrintLog(const_char_pointer format, ...)
{

   va_list vargs;

   int nResult;

   nResult = 0;

   if (m_bLogOn) 
   {

      va_start(vargs, format);

      ::string str;

      str.formatf_arguments(format, vargs);

      Print(str);

      va_end(vargs);

   }

   return 0;

}


void nfs::start(std::vector<std::vector<::string>> paths)
{

	bool bRESULT_SUCCESS;

	m_PortmapProg.Set(PROG_MOUNT, MOUNT_PORT);  //map_base port for mount
	m_PortmapProg.Set(PROG_NFS, NFS_PORT);  //map_base port for nfs
	m_NFSProg.SetUserID(get_user_id(), get_group_id());  //set uid and gid of files

	mountPaths(paths);

	m_RPCServer.Set(PROG_PORTMAP, &m_PortmapProg);  //program for portmap
	m_RPCServer.Set(PROG_NFS, &m_NFSProg);  //program for nfs
	m_RPCServer.Set(PROG_MOUNT, &m_MountProg);  //program for mount
	m_RPCServer.SetLogOn(m_bLogOn);

	for (int i = 0; i < SOCKET_NUM; i++) {
		DatagramSockets[i].SetListener(&m_RPCServer);
		ServerSockets[i].SetListener(&m_RPCServer);
	}

	bRESULT_SUCCESS = false;

	if (ServerSockets[0].Open(PORTMAP_PORT, 3) && DatagramSockets[0].Open(PORTMAP_PORT)) { //start portmap daemon
		PrintLog("Portmap daemon started\n");

		if (ServerSockets[1].Open(NFS_PORT, 10) && DatagramSockets[1].Open(NFS_PORT)) { //start nfs daemon
         PrintLog("NFS daemon started\n");

			if (ServerSockets[2].Open(MOUNT_PORT, 3) && DatagramSockets[2].Open(MOUNT_PORT)) { //start mount daemon
            PrintLog("Mount daemon started\n");
				bRESULT_SUCCESS = true;  //all daemon started
			} else {
            PrintLog("Mount daemon starts failed (check if port 1058 is not already in use ;) ).\n");
			}
		} else {
         PrintLog("NFS daemon starts failed.\n");
		}
	} else {
      PrintLog("Portmap daemon starts failed.\n");
	}

	if (bRESULT_SUCCESS) 
   {

      m_localHost = gethostbyname("");

      PrintLog("User ID %d\n", get_user_id());

      PrintLog("Group ID %d\n", get_group_id());

      PrintLog("Listening on %s\n", get_bind_address().c_str());  //local address
		//inputCommand();  //wait for commands
	}

}






int nfs::main(int argc, char * argv[])
{
   std::vector<std::vector<::string>> pPaths;
   char * pPath = NULL;
   bool pathFile = false;


   printAbout();

   if (argc < 2) {
      pPath = strrchr(argv[0], '\\');
      pPath = pPath == NULL ? argv[0] : pPath + 1;
      printUsage(pPath);
      return 1;
   }
   
   m_bLogOn = true;
   m_sFileName = NULL;

   set_user_id(0);
   set_group_id(0);
   set_bind_address("0.0.0.0");

   for (int i = 1; i < argc; i++) {//parse parameters
      if (_stricmp(argv[i], "-id") == 0) {
         set_user_id(atoi(argv[++i]));
         set_group_id(atoi(argv[++i]));
      }
      else if (_stricmp(argv[i], "-log") == 0) {
         m_bLogOn = _stricmp(argv[++i], "off") != 0;
      }
      else if (_stricmp(argv[i], "-addr") == 0) {
         set_bind_address(argv[++i]);
      }
      //else if (_stricmp(argv[i], "-pathFile") == 0) {
      //   m_sFileName = argv[++i];

      //   if (m_MountProg.SetPathFile(m_sFileName) == false) {
      //      printf("Can't open file %s.\n", m_sFileName);
      //      return 1;
      //   }
      //   else {
      //      m_MountProg.Refresh();
      //      pathFile = true;
      //   }
      //}
      else if (i == argc - 2) {
         pPath = argv[argc - 2];  //path is before the last parameter

         char * pCurPathAlias = argv[argc - 1]; //path alias is the last parameter

         if (pPath != NULL || pCurPathAlias != NULL) {
            std::vector<::string> pCurPaths;
            pCurPaths.push_back(::string(pPath));
            pCurPaths.push_back(::string(pCurPathAlias));
            pPaths.push_back(pCurPaths);
         }

         break;
      }
      else if (i == argc - 1) {
         char * pPath = argv[argc - 1];  //path is the last parameter

         if (pPath != NULL) {
            char curPathAlias[MAXPATHLEN];
            strcpy_s(curPathAlias, pPath);
            char * pCurPathAlias = curPathAlias;

            std::vector<::string> pCurPaths;
            pCurPaths.push_back(::string(pPath));
            pCurPaths.push_back(::string(pCurPathAlias));
            pPaths.push_back(pCurPaths);
         }

         break;
      }
   }




   if (pPaths.size() <= 0 && !pathFile) {
      printf("No paths to mount\n");
      return 1;
   }
   main_start(pPaths);

   return 0;
}


void nfs::netnode_from_ini_configuration()
{

   read_ini_configuration();

   run_netnode();

}


void nfs::run_netnode()
{

   // minimal configuration example:
   // user_id=1001
   // group_id=1001
   // bind_address=1001
   // mount_path_1=C:\Dropbox
   // mount_alias_1=/dropbox

   
   //m_nUID = iUsr;
   
   //m_nGID = iGrp;
   
   //set_bind_address(pAddr);

   std::vector<std::vector<::string>> paths;

   int iCount = get_mount_count();

   for (int i = 0; i < iCount; i++)
   {

      auto path = get_mount_path(i);

      auto alias = get_mount_alias(i);

      paths.push_back({ path.c_str(), alias.c_str() });

   }

   main_start(paths);

}


void nfs::main_start(std::vector<std::vector<::string>> paths)
{

   //AllocConsole();

   HWND console = GetConsoleWindow();

   if (m_bLogOn == false && IsWindow(console)) {
      ShowWindow(console, SW_HIDE); // hides the window
   }


   //WSADATA wsaData;

   //WSAStartup(0x0101, &wsaData);
   start(paths);
   //WSACleanup();

}