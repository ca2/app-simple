#pragma once


//#define TABLE_SIZE 1024

#include "tree_path_item.h"
#include "OutputStream.h"
class nfs_fh3;
struct FILE_ITEM
{
   ::string m_strName;
   FILE_ITEM(const ::scoped_string & scopedstr):
      m_strName(scopedstr)
   {

   }
   ::string name() const
   {

      return m_strName;
   }
    unsigned int nPathLen;
    file_handle handle;
    bool bCached;
    class ::time m_timeLastFileAttribute;
    unsigned int m_uLastFileAttributes;
    class ::time m_timeLastFile;
    FILE * m_pLastFile = nullptr;
} ;


class CFileTree  :
   public tree_path_item<FILE_ITEM>
{
public:

    //* m_pitemTop = nullptr;
   //tree<FILE_ITEM>::iterator m_pnodeTop;
   CFileTree() :
      tree_path_item<FILE_ITEM>(nullptr, "")
   {

   }

   bool const debug = false;
   //tree_path_item<FILE_ITEM> * add_item(const ::scoped_string & scopedstr);
   //void erase_item(const ::scoped_string & scopedstrAbsolutePath);
   //void rename_item(const ::scoped_string & scopedstrFrom, const ::scoped_string & scopedstrTo);

   //tree_path_item<FILE_ITEM> * find_item(const ::scoped_string & scopedstrAbsolutePath);

   

   //tree_path_item<FILE_ITEM> * findNodeFromRootWithPath(const ::scoped_string & scopedstr);
   //tree_path_item<FILE_ITEM> * findNodeWithPathFromNode(const ::scoped_string & scopedstr, tree_path_item<FILE_ITEM> * node);
   //tree_path_item<FILE_ITEM> * findParentNodeFromRootForPath(const ::scoped_string & scopedstr);
};
extern void DisplayTree(tree_path_item<FILE_ITEM> * node, int level);

//typedef struct _FILE_TABLE
//{
//	 tree_path_item<FILE_ITEM>* pItems[TABLE_SIZE];
//    _FILE_TABLE *pNext;
//} FILE_TABLE;

//typedef struct _CACHE_LIST
//{
//    FILE_ITEM *pItem;
//    _CACHE_LIST *pNext;
//} CACHE_LIST;

class CFileTable :
   public CFileTree
{
public:



   CFileTable();
   ~CFileTable();

   virtual tree_path_item <FILE_ITEM> * create_new_tree_path_item(tree_path_item<FILE_ITEM> * pitemParent, const ::scoped_string & scopedstr) override;


   //file_handle get_file_handle(const_char_pointer path);
   ::string get_path_by_handle(unsigned long handle);
   tree_path_item<FILE_ITEM>* find_item_by_path(const ::scoped_string & scopedstr);
   bool _EraseItem(const ::scoped_string & scopedstr);
   void _RenameItem(const::scoped_string & scopedstrFrom, const ::scoped_string & scopedstrTo);

   tree_path_item<FILE_ITEM>* get_item(const ::scoped_string & scopedstr);


   ::array < tree_path_item < FILE_ITEM > * > m_treenodea;
   //FILE_TABLE *m_pFirstTable, *m_pLastTable;
   // unsigned int m_nTableSize;
   // CACHE_LIST *m_pCacheList;

   tree_path_item<FILE_ITEM>* get_item_by_handle(unsigned long handle);
   //void PutItemInCache(FILE_ITEM *pItem);


   bool FileExists(const ::scoped_string & scopedstr);
   tree_path_item<FILE_ITEM> * get_item_by_path(const ::scoped_string & scopedstr);
   //unsigned long get_file_handle(const ::scoped_string & scopedstr);
   file_handle get_file_handle(const ::scoped_string & scopedstr);
   ::file::path GetFilePath(file_handle handle);
   int RenameFile(const ::scoped_string & scopedstrFrom, const ::scoped_string & scopedstrTo);
   int RenameDirectory(const ::scoped_string & scopedstrFrom, const ::scoped_string & scopedstrTo);
   int EraseFolder(const ::scoped_string & scopedstr);
   bool EraseFile(const::scoped_string & scopedstr);

};

class CFileTableAccessor
{
public:

   CFileTable * m_pfiletable;

   CFileTableAccessor(CFileTable * pfiletable) :
      m_pfiletable(pfiletable)
   {


   }

   bool FileExists(const ::scoped_string & scopedstr)
   {

      return m_pfiletable->FileExists(scopedstr);

   }
   tree_path_item<FILE_ITEM >* get_item_by_path(const ::scoped_string & scopedstr)
   {
      return m_pfiletable->get_item_by_path(scopedstr);

   }
   file_handle get_file_handle(const ::scoped_string & scopedstr)
   {

      return m_pfiletable->get_file_handle(scopedstr);
   }
   ::file::path GetFilePath(file_handle handle)
   {

      return m_pfiletable->GetFilePath(handle);
   }
   ::file::path GetFilePath(const nfs_fh3 & filehandle);
   int RenameFile(const ::scoped_string & scopedstrFrom, const ::scoped_string & scopedstrTo)
   {

      return m_pfiletable->RenameFile(scopedstrFrom, scopedstrTo);
   }
   int RenameDirectory(const ::scoped_string & scopedstrFrom, const ::scoped_string & scopedstrTo)
   {

      return m_pfiletable->RenameDirectory(scopedstrFrom, scopedstrTo);
   }
   int EraseFolder(const ::scoped_string & scopedstr)
   {
      return m_pfiletable->EraseFolder(scopedstr);

   }
   bool EraseFile(const ::scoped_string & scopedstr)
   {
      return m_pfiletable->EraseFile(scopedstr);

   }


};
