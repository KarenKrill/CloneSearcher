#pragma once

#include <Windows.h>

#define uchar unsigned char
#define ushort unsigned short
#define uint unsigned int
#define ulong unsigned __int64
#define uint8 unsigned __int8
#define uint16 unsigned __int16
#define uint32 unsigned __int32
#define uint64 unsigned __int64

#include "Hash.h"
#include "Algorithms.h"

class File;
class Folder
{
	wchar_t *name;
	uint nameLength;
	SAL::List<Folder*> subFolders;
	SAL::List<File*> files;
	const Folder* parentFolder;
	bool scanned;
public:
	Folder();
	Folder(const wchar_t* path, const Folder* parent=NULL);
	~Folder();
	SAL::String GetFullName() const;
	void AddFolder(Folder *folder);
	void AddFile(File *file);
	void SetScanned(bool mark=true);
	bool IsScanned();
};
class File
{
	wchar_t *name;
	uint nameLength;
	const wchar_t* extension;
	uint64 byteSize;
	const Folder* folder;
	bool deletionMark;
	bool hashed;
public:
	File();
	File(const wchar_t* fileName, uint64 size, Folder* parent);
	~File();
	const wchar_t* GetName() const;
	const wchar_t* GetExtension() const;
	SAL::String GetFullName() const;
	SAL::String GetFolderFullName() const;
	uint64 GetByteSize() const;
	void MarkForDeletion();
	void UnmarkForDeletion();
	bool GetDeletionMark() const;
	bool IsHashed() const;
	void SetHashed();
	bool Delete(bool recycleBin=true);
};

class VirtualFile
{
	uint64 byteSize; //FileSize < 16 EB (exabytes)
	Hash *hash;
	SAL::List<File*> fileInstances;
	uint deletionMarksNumber;
public:
	const wchar_t *name, *extension;
public:
	VirtualFile();
	~VirtualFile();
	uint64 GetByteSize() const;
	Hash* GetHash() const;
	void AddFileInstance(File *instance, Hash *h);
	bool RemFileInstance(uint i);
	uint GetInstancesNumber() const;
	File* GetFileInstance(uint i);
	void MarkToDeletion(uint fileID, bool mark = true);
	uint GetDeletionMarksNumber();
};

enum SortTypes
{
	None = 0x0,
	ByName = 0x1,
	ByExtension = 0x2,
	BySize = 0x4,
	ByInstNumber = 0x8,
	ByMarksNumber = 0x16,
};
class Filter
{
public:
	wchar_t *data;
	bool state;
	Filter();
	Filter(const wchar_t* Data, bool State);
	~Filter();
};
class CloneSearcher
{
	SAL::List<Folder*> foldersToScan;
	SAL::List<File*> files;
	uint64 filesSize;
	SAL::List<VirtualFile*> virtualFiles;
	SAL::RedBlackTree<uint64, SAL::RedBlackTree<Hash, VirtualFile*>*> *sizeHashTree;
	bool rescanMark;
	//tools:
	SAL::List<Filter*> filters;
	SAL::List<uint64> *filteringIndices;
	static bool FilterLess(Filter* filter1, Filter* filter2);
	//options:
	bool scanSystemFiles, scanHiddenFiles;
	uint64 minFileSize, maxFileSize;
	bool deleteToRecycleBin;
public:
	CloneSearcher();
	~CloneSearcher();
	bool AddFolder(LPCWSTR folder);
	bool RemFolder(uint i);
	void RescanCleaning();
	void MarkToRescan();
	bool GetMarkToRescan();
	void ScanFolders();
	bool ScanFolder(Folder *folder);
	uint GetFoldersNumber() const;
	SAL::String GetFolderPath(uint i);
	bool FolderIsScanned(uint i);

	bool AddFile(LPCWSTR fileName, uint64 size, Folder *folder);
	uint GetFilesNumber() const;
	uint GetVFilesNumber() const;
	uint64 GetFilesSize() const;
	uint64 GetVFilesSize();
	uint64 GetFileSize(uint i);
	SAL::String GetFileName(uint i);
	bool ProcessFile(uint i);
	bool DetectClones();
	void RedetectClones();

	VirtualFile* GetVFile(uint vFileID);
	bool DeleteMarkedFile(uint vFileID, uint fileID);

private:
	static bool InstNumbComparing(VirtualFile *file1, VirtualFile *file2);
	static bool NamesComparing(VirtualFile *file1, VirtualFile *file2);
	static bool ExtComparing(VirtualFile *file1, VirtualFile *file2);
	static bool SizeComparing(VirtualFile *file1, VirtualFile *file2);
	static bool MarksNumberComparing(VirtualFile *file1, VirtualFile *file2);
public:
	void Sort(SortTypes type, bool reverse=false);
	void UpdateFilters();
	void UpdateFiltersStates();
	uint GetFiltersNumber() const;
	const wchar_t* GetFilter(uint i);
	bool GetFilterState(uint i);
	void SetFilterState(uint i, bool state=true);
	//options:
	void ScanSystemFiles(bool state);
	void ScanHiddenFiles(bool state = true);
	void DeleteToRecycleBin(bool state = true);
	void SetMinFileSize(uint16 size); //0 - 65 536 MB
	void SetMaxFileSize(uint16 size); //0 - 65 536 MB
	bool IsScanSystemFiles() const;
	bool IsScanHiddenFiles() const;
	bool IsDeleteToRecycleBin() const;
	uint16 GetMinFileSize() const;
	uint16 GetMaxFileSize() const;
	void SetMemoryForHashing(uint16 memorySize); //1-4095 MB
	uint16 GetMemorySizeForHashing() const;
};