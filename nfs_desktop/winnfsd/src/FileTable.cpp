#include "framework.h"
#include "FileTable.h"
//#include "FileTree.h"
#include "NFS3Prog.h"
#include <string.h>
#include <io.h>
#include <stdio.h>
#include <windows.h>
#include <sys/stat.h>
#include "tree_path_item.h"


::string NfsProcessPath(const_char_pointer path)
{

   ::string strPath(path);

   bool bChanged = false;

   do
   {

      bChanged = strPath.ends_eat("\\.");

      if (!bChanged)
      {

         bChanged = strPath.ends_eat("\\..");

         if (bChanged)
         {

            auto iFind1 = strPath.rear_find_index('\\');

            auto iFind2 = strPath.rear_find_index('/');

            auto iFind = maximum(iFind1, iFind2);

            if (iFind >= 0)
            {

               strPath.truncate(iFind);

            }

         }

      }

      if (!bChanged)
      {

         if(strPath.contains("\\.\\"))
         {
            
            strPath.find_replace("\\.\\", "\\");
            
            bChanged = true;

         }

      }

      if (!bChanged)
      {

         if (strPath.contains("/./"))
         {

            strPath.find_replace("/./", "/");

            bChanged = true;

         }

      }

      if (!bChanged)
      {

         auto iFind = strPath.find_index("\\..\\");

         if (iFind == 0)
         {

            strPath = strPath.substr(3);

         }
         else if(iFind > 0)
         {

            auto iFind1 = strPath.rear_find_index('\\', iFind);

            auto iFind2 = strPath.rear_find_index('/', iFind);

            auto iFind3 = maximum(iFind1, iFind2);

            if (iFind3 < iFind)
            {

               strPath = strPath.left(iFind3 + 1) + strPath.substr(iFind + 3);

               bChanged = true;

            }

         }

      }

      if (!bChanged)
      {

         auto iFind = strPath.find_index("/../");

         if (iFind == 0)
         {

            strPath = strPath.substr(3);

         }
         else if (iFind > 0)
         {

            auto iFind1 = strPath.rear_find_index('\\', iFind);

            auto iFind2 = strPath.rear_find_index('/', iFind);

            auto iFind3 = maximum(iFind1, iFind2);

            if (iFind3 < iFind)
            {

               strPath = strPath.left(iFind3 + 1) + strPath.substr(iFind + 3);

               bChanged = true;

            }

         }

      }

   } while (bChanged);

   return strPath;

}


#define FHSIZE 32
#define NFS3_FHSIZE 64

//static CFileTable g_FileTable;
//static CFileTree m_tree;

CFileTable::CFileTable()
{
    //m_pLastTable = m_pFirstTable = new FILE_TABLE;
    //memset(m_pFirstTable, 0, sizeof(FILE_TABLE));
    //m_nTableSize = 0;
    //m_pCacheList = NULL;
   m_treenodea.add(this);
}

CFileTable::~CFileTable()
{
    //FILE_TABLE *pTable, *pTemp;
    //unsigned int i;
    //CACHE_LIST *pPrev;

    //pTable = m_pFirstTable;

    //while (pTable != NULL) { //free file table
    //    for (i = 0; i < TABLE_SIZE; i++) {
    //        if (!pTable->pItems[i]) {
    //            delete[] pTable->pItems[i];
    //        }
    //    }

    //    pTemp = pTable;
    //    pTable = pTable->pNext;
    //    delete pTemp;
    //}

    //while (m_pCacheList != NULL) { //free cache
    //    pPrev = m_pCacheList;
    //    m_pCacheList = m_pCacheList->pNext;
    //    delete pPrev;
    //}
}

//unsigned long CFileTable::GetIDByPath(const_char_pointer path)
//{
//    unsigned char *handle;
//
//    handle = GetHandleByPath(path);
//	if (handle == NULL)
//	{
//		//printf("Can't find id for path %s\n", path);
//		return 0;
//	}
//    return *(unsigned long *)handle;
//}

file_handle CFileTable::get_file_handle(const ::scoped_string & scopedstr)
{

	auto pitem = get_item(scopedstr);

	//if (ptreelistitem == NULL) 
 //  {
	//	//printf("Add file for path %s\n", path);
 //     ptreelistitem = add_item(path);
	//	//ptreelistitem = m_tree.find_item(path);
	//	//if (ptreelistitem == NULL || ptreelistitem->data.handle == NULL)
	//	//{
	//	//	//printf("Missing handle for path %s\n", path);
	//	//}
 //   }
   if (pitem == NULL)
   {
      return{};
	}

	return pitem->m_t.handle;
}

tree_path_item <FILE_ITEM> * CFileTable::create_new_tree_path_item(tree_path_item * pitemParent, const ::scoped_string & scopedstr)
{

   auto pitem = new tree_path_item <FILE_ITEM>(pitemParent, scopedstr);

   pitem->m_t.handle.m_ll = m_treenodea.size();

   m_treenodea.add(pitem);

   return pitem;

}


::string CFileTable::get_path_by_handle(unsigned long handle)
{

	auto pitem = get_item_by_handle(handle);
	
   return pitem->path();

}


tree_path_item<FILE_ITEM>* CFileTable::find_item_by_path(const ::scoped_string & scopedstr)
{
	tree_path_item<FILE_ITEM>* ptreelistitem= NULL;/*
    CACHE_LIST *pCurr;

    unsigned int i, j, nPathLen;
    FILE_TABLE *pTable;

    nPathLen = strlen(path);
    pItem = NULL;

    pCurr = m_pCacheList;

    while (pCurr != NULL) { //search in cache
        if (nPathLen == pCurr->pItem->nPathLen) { //comparing path length is faster than comparing path
            if (strcmp(path, pCurr->pItem->path) == 0) { //compare path
                pItem = pCurr->pItem;  //path matched
                break;
            }
        }

        pCurr = pCurr->pNext;
    }

    if (pItem == NULL) { //not found in cache
        pTable = m_pFirstTable;

        for (i = 0; i < m_nTableSize; i += TABLE_SIZE) { //search in file table
            for (j = 0; j < TABLE_SIZE; j++) {
                if (i + j >= m_nTableSize) { //all items in file table are compared
                    return NULL;
                }

                if (nPathLen == pTable->pItems[j].nPathLen) { //comparing path length is faster than comparing path
                    if (strcmp(path, pTable->pItems[j].path) == 0) { //compare path
                        pItem = pTable->pItems + j;  //path matched
                        break;
                    }
                }
            }

            if (pItem != NULL) {
                break;
            }

            pTable = pTable->pNext;
        }
    }

    if (pItem != NULL) {
        //TODO IMPLEMENTED CACHE RIGHT
        //PutItemInCache(pItem);  //put the found item in cache
    }
	*/
	return ptreelistitem;
}

tree_path_item<FILE_ITEM>* CFileTable::get_item(const ::scoped_string & scopedstr)
{
   
   auto ptreelistitem = CFileTree::get_item(scopedstr);

   return ptreelistitem;

 //   FILE_ITEM item;
	//tree_path_item<FILE_ITEM>* ptreelistitem;
 //   unsigned int nIndex;

	//item.path = new char[strlen(path) + 1];
	//strcpy_s(item.path, (strlen(path) + 1), path);  //path
	//item.nPathLen = strlen(item.path);  //path length
	//item.handle = new unsigned char[NFS3_FHSIZE];
	//memset(item.handle, 0, NFS3_FHSIZE * sizeof(unsigned char));
	//*(unsigned int *)item.handle = m_nTableSize;  //let its handle equal the index
	//item.bCached = false;  //not in the cache

 //   if (m_nTableSize > 0 && (m_nTableSize & (TABLE_SIZE - 1)) == 0) {
 //       m_pLastTable->pNext = new FILE_TABLE;
 //       m_pLastTable = m_pLastTable->pNext;
 //       memset(m_pLastTable, 0, sizeof(FILE_TABLE));
 //   }

	////printf("\nAdd file %s for handle %i\n", path, *(unsigned int *)item.handle);

	//m_tree.AddItem(path, item.handle);
	//ptreelistitem = m_tree.find_item(path);
	//if (ptreelistitem == NULL) {
	//	//printf("Can't find ptreelistitem just added %s\n", path);
	//}

	//m_pLastTable->pItems[nIndex = m_nTableSize & (TABLE_SIZE - 1)] = ptreelistitem;  //add the new item in the file table
 //   ++m_nTableSize;

	//return ptreelistitem;  //return the pointer to the new item
}

tree_path_item<FILE_ITEM>* CFileTable::get_item_by_handle(unsigned long handle)
{
   if (handle < 0 || handle >= m_treenodea.size())
   {

      return nullptr;

   }


   return m_treenodea[handle];
	//FILE_TABLE *pTable;
	//unsigned int i;

	//if (nID >= m_nTableSize) {
	//	return NULL;
	//}

	//pTable = m_pFirstTable;

	//for (i = TABLE_SIZE; i <= nID; i += TABLE_SIZE) {
	//	pTable = pTable->pNext;
	//}

	//return pTable->pItems[nID + TABLE_SIZE - i];
}

//void CFileTable::PutItemInCache(FILE_ITEM *pItem)
//{
//    CACHE_LIST *pPrev, *pCurr;
//    int nCount;
//
//    pPrev = NULL;
//    pCurr = m_pCacheList;
//
//    if (pItem->bCached) { //item is already in the cache
//        while (pCurr != NULL) {
//            if (pItem == pCurr->pItem) {
//                if (pCurr == m_pCacheList) {  //at the first
//                    return;
//                }
//                else {  //move to the first
//                    pPrev->pNext = pCurr->pNext;
//                    pCurr->pNext = m_pCacheList;
//                    m_pCacheList = pCurr;
//                    return;
//                }
//            }
//
//            pPrev = pCurr;
//            pCurr = pCurr->pNext;
//        }
//    }
//    else {
//        pItem->bCached = true;
//
//        for (nCount = 0; nCount < 9 && pCurr != NULL; nCount++) { //seek to the end of the cache
//            pPrev = pCurr;
//            pCurr = pCurr->pNext;
//        }
//
//        if (nCount == 9 && pCurr != NULL) { //there are 10 items in the cache
//            pPrev->pNext = NULL;  //remove the last
//            pCurr->pItem->bCached = false;
//        }
//        else {
//            pCurr = new CACHE_LIST;
//        }
//
//        pCurr->pItem = pItem;
//        pCurr->pNext = m_pCacheList;
//        m_pCacheList = pCurr;  //insert to the first
//    }
//}

bool CFileTable::_EraseItem(const ::scoped_string & scopedstr) {
   /* CACHE_LIST *pCurr;
    FILE_ITEM *pItem;
    unsigned int i, j, nPathLen;
    FILE_TABLE *pTable;
    int pItemIndex;

    nPathLen = strlen(path);
    pItem = NULL;

    bool foundDeletedItem = false;

    pTable = m_pFirstTable;

    for (i = 0; i < m_nTableSize; i += TABLE_SIZE) { //search in file table
        for (j = 0; j < TABLE_SIZE; j++) {
            if (i + j >= m_nTableSize) { //all items in file table are compared
                break;
            }

            if (!foundDeletedItem)
            {
                if (nPathLen == pTable->pItems[j].nPathLen) { //comparing path length is faster than comparing path
                    if (strcmp(path, pTable->pItems[j].path) == 0) { //compare path
                        foundDeletedItem = true;
                        memset(&(pTable->pItems[j]), 0, sizeof(FILE_ITEM));
                    }
                }
            }
        }

        pTable = pTable->pNext;
    }

    if (foundDeletedItem) {
		// we should not uncrement table size, because new file handle base on it
        //--m_nTableSize;
    }*/

   ::file::path path(scopedstr);
	tree_path_item<FILE_ITEM>* foundDeletedItem;
	foundDeletedItem = CFileTree::find_item(path);
	if (foundDeletedItem != NULL) {
		// Remove from table
		//FILE_TABLE *pTable;
		//unsigned int i;
		unsigned long handle = (unsigned long) foundDeletedItem->m_t.handle.m_ll;

      m_treenodea[handle] = nullptr;

      CFileTree::erase_item(foundDeletedItem);
		//if (handle >= m_nTableSize) {
		//	//printf("File handle not found to remove : %s", path);
		//	return false;
		//} else {

		//	pTable = m_pFirstTable;

		//	for (i = TABLE_SIZE; i <= handle; i += TABLE_SIZE) {
		//		pTable = pTable->pNext;
		//	}

		//	pTable->pItems[handle + TABLE_SIZE - i] = NULL;
		//}
		//// Remove from table end

		return true;
	}
	else {
		//printf("File not found to remove : %s", path);
	}
    return false;
}

void CFileTable::_RenameItem(const ::scoped_string & scopedstrFrom, const ::scoped_string & scopedstrTo)
{
	/*FILE_ITEM *pItem;

	pItem = g_FileTable.get_item_by_handle(pathFrom);

	if (pItem == NULL) {
	} else {
		delete[] pItem->path;
		pItem->nPathLen = strlen(pathTo);
		pItem->path = new char[pItem->nPathLen + 1];
		strcpy_s(pItem->path, (pItem->nPathLen + 1), pathTo);  //replace the path by new one
	}
	*/
	CFileTree::__rename_item(scopedstrFrom, scopedstrTo);
}


bool CFileTable::FileExists(const ::scoped_string & path)
{
    bool bExists = false;

    {
       struct _finddata_t fileinfo {};

       auto strPath = NfsProcessPath(path);

       auto handle = _findfirst(strPath, &fileinfo);
       if (handle == -1) {
          return false;
       }
       auto p1 = fileinfo.name;

       auto p2 = strrchr(strPath, '/');

       bExists = strcmp(p1, p2 + 1) == 0;

       _findclose(handle);

    }

    return bExists;  //filename must match case

}

tree_path_item<FILE_ITEM> * CFileTable::get_item_by_path(const ::scoped_string & scopedstr)
{

   auto ptreelistitem = CFileTree::find_item(scopedstr);

   if (!ptreelistitem)
   {

      return nullptr;

   }

   return ptreelistitem;

}

//unsigned long CFileTable::get_file_handle(const ::scoped_string & scopedstr)
//{
//
//   auto strPath = NfsProcessPath(path);
//    return g_FileTable.GetIDByPath(strPath);
//}
//
//file_handle CFileTable::get_file_handle(const ::scoped_string & scopedstr)
//{
//   auto strPath = NfsProcessPath(scopedstr);
//    return find_item(strPath);
//}
//
::file::path CFileTable::GetFilePath(file_handle handle)
{

   if (handle.m_ll < 0 || handle.m_ll >= (unsigned long) m_treenodea.size())
   {

      return {};

   }

   auto pitem = m_treenodea[handle.m_ll];

   if (!pitem)
   {

      return {};

   }
    return pitem->path();

}

int CFileTable::RenameFile(const ::scoped_string & scopedstrFrom, const ::scoped_string & scopedstrTo)
{
	tree_path_item<FILE_ITEM>* ptreelistitem;
    FILE_ITEM *pItem;

    auto strPathFrom = NfsProcessPath(scopedstrFrom);
	ptreelistitem = get_item_by_path(strPathFrom);
    pItem = &(ptreelistitem->m_t);

    if (pItem == NULL) {
        return false;
    }
    auto strPathTo = NfsProcessPath(scopedstrTo);
    errno_t errorNumber = rename(strPathFrom, strPathTo);

    if (errorNumber == 0) { //RESULT_SUCCESS
		_RenameItem(strPathFrom, strPathTo);
        return errorNumber;
    }
    else {
        return errorNumber;
    }
}

int CFileTable::RenameDirectory(const ::scoped_string & scopedstrFrom, const ::scoped_string & scopedstrTo)
{
   throw "todo";
	//errno_t errorNumber = RenameFile(scopedstrFrom, scopedstrTo);

	//const_char_pointer dotFile = "\\.";
	//const_char_pointer backFile = "\\..";

	//char* dotDirectoryPathFrom;
	//char* dotDirectoryPathTo;
	//char* backDirectoryPathFrom;
	//char* backDirectoryPathTo;
	//dotDirectoryPathFrom = (char *)malloc(strlen(pathFrom) + 1 + 3);
	//strcpy_s(dotDirectoryPathFrom, (strlen(pathFrom) + 1), pathFrom);
	//strcat_s(dotDirectoryPathFrom, (strlen(pathFrom) + 5), dotFile);

	//dotDirectoryPathTo = (char *)malloc(strlen(pathTo) + 1 + 3);
	//strcpy_s(dotDirectoryPathTo, (strlen(pathTo) + 1), pathTo);
	//strcat_s(dotDirectoryPathTo, (strlen(pathTo) + 5), dotFile);

	//backDirectoryPathFrom = (char *)malloc(strlen(pathFrom) + 1 + 4);
	//strcpy_s(backDirectoryPathFrom, (strlen(pathFrom) + 1), pathFrom);
	//strcat_s(backDirectoryPathFrom, (strlen(pathFrom) + 6), backFile);

	//backDirectoryPathTo = (char *)malloc(strlen(pathTo) + 1 + 4);
	//strcpy_s(backDirectoryPathTo, (strlen(pathTo) + 1), pathTo);
	//strcat_s(backDirectoryPathTo, (strlen(pathTo) + 6), backFile);

	//_RenameItem(dotDirectoryPathFrom, dotDirectoryPathTo);
	//_RenameItem(backDirectoryPathFrom, backDirectoryPathTo);
	//return errorNumber;

   return -1;


}

bool CFileTable::EraseFile(const ::scoped_string & scopedstr)
{

   ::string path(scopedstr);
	int nMode = 0;
	nMode |= S_IREAD;
	nMode |= S_IWRITE;
	_chmod(path, nMode);

    if (remove(path) == 0){
        _EraseItem(path);
        return true;
    }
    return false;
}

int CFileTable::EraseFolder(const ::scoped_string &scopedstr)
{
   ::string path(scopedstr);
	int nMode = 0;
	unsigned long errorCode = 0;
	nMode |= S_IREAD;
	nMode |= S_IWRITE;
	_chmod(path, nMode);

    if (RemoveDirectoryA(path) != 0) {
       throw "todo";
        //const_char_pointer dotFile = "\\.";
        //const_char_pointer backFile = "\\..";

        //char* dotDirectoryPath;
        //char* backDirectoryPath;
        //dotDirectoryPath = (char *)malloc(strlen(path) + 1 + 3);
        //strcpy_s(dotDirectoryPath, (strlen(path) + 1), path);
        //strcat_s(dotDirectoryPath, (strlen(path) + 5), dotFile);
        //backDirectoryPath = (char *)malloc(strlen(path) + 1 + 4);
        //strcpy_s(backDirectoryPath, (strlen(path) + 1), path);
        //strcat_s(backDirectoryPath, (strlen(path) + 6), backFile);

        //_EraseItem(dotDirectoryPath);
        //_EraseItem(backDirectoryPath);
		_EraseItem(path);
        return 0;
    }
    errorCode = GetLastError();
    return errorCode;
}

//void CFileTable::RemovePathFromFileTable(const ::scoped_string & scopedstr)
//{
//   auto strPath = NfsProcessPath(scopedstr);
//    _EraseItem(strPath);
//}


::file::path CFileTableAccessor::GetFilePath(const nfs_fh3 & filehandle)
{
   file_handle handle;
   handle.m_ll = *((unsigned long *)filehandle.contents);
   return GetFilePath(handle);
}
