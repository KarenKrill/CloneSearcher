#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <set>

Folder::Folder()
{
	name = NULL;
	nameLength = 0;
	parentFolder = NULL;
	scanned = false;
}
Folder::Folder(const wchar_t* path, const Folder* parent)
{
	nameLength = 0;
	while (path[nameLength]) { nameLength++; }
	name = new wchar_t[nameLength+1];
	memcpy(name, path, nameLength*sizeof(path[0]));
	name[nameLength] = 0;
	parentFolder = parent;
	scanned = false;
}
Folder::~Folder()
{
	if (name)
	{
		delete [] name;
		name = NULL;
	}
	nameLength = 0;
	parentFolder = NULL;
	for (uint i = 0; i < subFolders.Size(); i++)
	{
		if (subFolders[i]) delete subFolders[i];
	}
	subFolders.Clear();
	files.Clear();
}
SAL::String Folder::GetFullName() const
{
	SAL::String fullName;
	SAL::List<const wchar_t*> folderNames;
	const Folder* currFolder=this;
	do
	{
		folderNames.PushFront(currFolder->name);
		currFolder = currFolder->parentFolder;
	} while (currFolder);
	for (uint i = 0; i < folderNames.Size(); i++)
	{
		fullName += folderNames[i];
		if (i < folderNames.Size() - 1) fullName += L"\\";
	}
	return fullName;
}
void Folder::AddFolder(Folder *folder)
{
	folder->parentFolder = this;
	subFolders.Push(folder);
}
void Folder::AddFile(File *file){files.Push(file);}
void Folder::SetScanned(bool mark){ scanned = mark; }
bool Folder::IsScanned(){ return scanned; }
File::File()
{
	name = NULL;
	extension = NULL;
	nameLength = 0;
	folder = NULL;
	deletionMark = false;
	byteSize = 0;
	hashed = false;
}
File::File(const wchar_t* fileName, uint64 size, Folder* parent)
{
	extension = NULL;
	nameLength = 0;
	while (fileName[nameLength])
	{
		if (fileName[nameLength] == L'.') extension = (wchar_t*)nameLength;
		nameLength++;
	}
	name = new wchar_t[nameLength + 1];
	memcpy(name, fileName, nameLength*sizeof(fileName[0]));
	name[nameLength] = 0;
	if (extension && (uint)extension + 1 != nameLength)
	{
		extension = name + (uint)extension;
	}
	parent->AddFile(this);
	folder = parent;
	deletionMark = false;
	byteSize = size;
	hashed = false;
}
File::~File()
{
	extension = NULL;
	if (name)
	{
		delete name;
		name = NULL;
	}
	nameLength = 0;
	folder = NULL;
	deletionMark = false;
	byteSize = 0;
	hashed = false;
}
const wchar_t* File::GetName() const { return name; }
const wchar_t* File::GetExtension() const { return extension; }
SAL::String File::GetFullName() const
{
	SAL::String fullName;
	fullName += folder->GetFullName();
	fullName += "\\";
	fullName += name;
	return fullName;
}
SAL::String File::GetFolderFullName() const
{
	if (!folder) return SAL::String();
	else return folder->GetFullName();
}
uint64 File::GetByteSize() const { return byteSize; }
void File::MarkForDeletion()
{
	this->deletionMark = true;
}
void File::UnmarkForDeletion()
{
	this->deletionMark = false;
}
bool File::GetDeletionMark() const { return deletionMark; }
bool File::IsHashed() const{ return hashed; }
void File::SetHashed(){ hashed = true; }
bool File::Delete(bool recycleBin)
{
	if (deletionMark)
	{
		SAL::String fullName = GetFullName();
		DWORD attributes = GetFileAttributesW(fullName.str);
		DWORD removableAttributes = 0;
		if (attributes&FILE_ATTRIBUTE_READONLY) removableAttributes |= FILE_ATTRIBUTE_READONLY;
		if (attributes&FILE_ATTRIBUTE_SYSTEM) removableAttributes |= FILE_ATTRIBUTE_SYSTEM;
		SetFileAttributesW(fullName.str, attributes^removableAttributes);

		SHFILEOPSTRUCTW fileOp;
		fileOp.hwnd = NULL;

		//wchar_t *path;
		//const wchar_t* cpath;// = files[fileNumber].GetFullName();
		//uint pathLength=0;
		//while(cpath[pathLength]) pathLength++;
		//if (!pathLength) return false;
		//path = new wchar_t[pathLength + 2];
		//memcpy((void*)path, (const void*)cpath, sizeof(path[0])*pathLength);
		//path[pathLength] = 0;
		//path[pathLength + 1] = 0;
		
		fullName += L"xx"; //for double-null terminated
		fullName.str[fullName.size - 1] = 0;
		fullName.str[fullName.size - 2] = 0;
		fileOp.pFrom = (const wchar_t*)fullName.str;

		fileOp.pTo = NULL;
		fileOp.wFunc = FO_DELETE;
		fileOp.hNameMappings = NULL;
		fileOp.fAnyOperationsAborted = false;
		fileOp.fFlags = FOF_SILENT | FOF_NOERRORUI | FOF_NOCONFIRMATION | FOF_FILESONLY;
		if (recycleBin) fileOp.fFlags |= FOF_ALLOWUNDO;

		int error;
		if ((error = SHFileOperationW(&fileOp)) == 0) return true;
		else
		{
			//LOG
			std::wofstream file;
			file.imbue(std::locale("Russian_Russia.1251"));
			file.open("errors.log", std::ios::out | std::ios::app);
			if (file.is_open())
			{
				file << SAL::String::IntToStr(error) << L" ";
				file << fileOp.pFrom;
				file << L"\r\n";
			}
			file.close();
		}
	}
	return false;
}
VirtualFile::VirtualFile()
{
	hash = NULL;
	byteSize = 0;
	name = extension = NULL;
	deletionMarksNumber = 0;
}
VirtualFile::~VirtualFile()
{
	if (hash)
	{
		delete hash;
		hash = NULL;
	}
	byteSize = 0;
	fileInstances.Clear();
	name = extension = NULL;
	deletionMarksNumber = 0;
}
uint64 VirtualFile::GetByteSize() const { return byteSize; }
Hash* VirtualFile::GetHash() const { return hash; }
void VirtualFile::AddFileInstance(File *instance, Hash *h)
{
	fileInstances.Push(instance);
	if(!byteSize) byteSize = instance->GetByteSize();
	if(!hash) hash=h;
	if (!name) name = instance->GetName();
	if (!extension) extension = instance->GetExtension();
}
bool VirtualFile::RemFileInstance(uint i)
{
	if (i >= fileInstances.Size()) return false;
	if (fileInstances[i]->GetDeletionMark()) deletionMarksNumber--;
	if (fileInstances.Remove(i)) return true;
	else return false;
}
uint VirtualFile::GetInstancesNumber() const { return fileInstances.Size(); }
File* VirtualFile::GetFileInstance(uint i)
{
	if (i >= fileInstances.Size()) return NULL;
	return fileInstances[i];
}
void VirtualFile::MarkToDeletion(uint fileID, bool mark)
{
	if (fileID >= fileInstances.Size()) return;
	bool currentMark = fileInstances[fileID]->GetDeletionMark();
	if (mark)
	{
		if (currentMark != mark) deletionMarksNumber++;
		fileInstances[fileID]->MarkForDeletion();
	}
	else
	{
		if (currentMark != mark) deletionMarksNumber--;
		fileInstances[fileID]->UnmarkForDeletion();
	}
}
uint VirtualFile::GetDeletionMarksNumber(){ return deletionMarksNumber; }

Filter::Filter(){ data = NULL; state = true; }
Filter::Filter(const wchar_t* Data, bool State)
{
	uint length=SAL::String::StrLength(Data);
	state = State;
	if (length)
	{
		data = new wchar_t[length+1];
		memcpy(data, Data, length*sizeof(data[0]));
		data[length] = 0;
	}
	else data = NULL;
}
Filter::~Filter()
{
	if (data)
	{
		delete[] data;
		data = NULL;
	}
	state = false;
}
CloneSearcher::CloneSearcher()
{
	sizeHashTree = NULL;
	rescanMark=false;

	scanSystemFiles = scanHiddenFiles = true;
	minFileSize = 0x1; maxFileSize = 0x800000000; //1B - 32 GB
	deleteToRecycleBin = true;
	filesSize = 0;
	filteringIndices = NULL;
}
CloneSearcher::~CloneSearcher()
{
	for (uint i = 0; i < files.Size(); i++)
	{
		if (files[i]) delete files[i];
	}
	files.Clear();
	for (uint i = 0; i < foldersToScan.Size(); i++)
	{
		if (foldersToScan[i]) delete foldersToScan[i];
	}
	foldersToScan.Clear();
	for (uint i = 0; i < virtualFiles.Size(); i++)
	{
		if (virtualFiles[i]) delete virtualFiles[i];
	}
	for (uint i = 0; i < filters.Size(); i++)
	{
		if (filters[i]) delete filters[i];
	}
	filters.Clear();
	if (filteringIndices) { filteringIndices->Clear(); delete filteringIndices; filteringIndices = NULL; }
	virtualFiles.Clear();
	if (sizeHashTree)
	{
		sizeHashTree->Clear();
		delete sizeHashTree;
		sizeHashTree = NULL;
	}
	filesSize = 0;
}
bool CloneSearcher::AddFolder(LPCWSTR folder)
{
	uint folderPathSize=0;
	while (folder[folderPathSize]) { folderPathSize++; }
	if (!folderPathSize || folderPathSize >= MAX_SIZE) return false;
	SAL::String fullName;
	for (uint i = 0; i < foldersToScan.Size();)
	{
		fullName = foldersToScan[i]->GetFullName();
		//C:\Users\User\Desktop >= C:\Users\User
		if (folder >= fullName && (folder[fullName.size] == L'\\' || folder[fullName.size] == L'\0')) return false;
		//D:\ <= D:\Games
		if (folder <= fullName && (fullName[folderPathSize] == L'\\' || fullName[folderPathSize] == L'\0'))
		{
			if (foldersToScan[i]->IsScanned()) rescanMark = true;
			RemFolder(i);
		}
		else i++;
	}
	Folder* newFolder;
	newFolder = new Folder(folder);
	foldersToScan.Push(newFolder);
	return true;
}
bool CloneSearcher::RemFolder(uint i)
{
	if (i>=foldersToScan.Size()) return false;
	if (foldersToScan[i])
	{
		delete foldersToScan[i];
		if (foldersToScan[i]->IsScanned()) rescanMark = true;
	}
	foldersToScan.Remove(i);
	return true;
}
void CloneSearcher::RescanCleaning()
{ 
	uint sizeHashTreeSize = 0;
	if (sizeHashTree) sizeHashTreeSize = sizeHashTree->GetSize();
	if (sizeHashTreeSize)
	{
		SAL::RBTreeNode<uint64, SAL::RedBlackTree<Hash, VirtualFile*>*> *sizeNode;
		sizeNode = sizeHashTree->Min(sizeHashTree->GetRoot());
		for (uint i = 0; i < sizeHashTreeSize; i++)
		{
			if (!sizeNode || !sizeNode->data) continue;
			delete sizeNode->data;
			sizeNode = sizeHashTree->Next(sizeNode);
		}
		sizeHashTree->Clear();
	}
	for (uint i = 0; i < virtualFiles.Size(); i++){ delete virtualFiles[i]; }
	virtualFiles.Clear();
	for (uint i = 0; i < files.Size(); i++){ delete files[i]; }
	files.Clear();
	for (uint i = 0; i < foldersToScan.Size(); i++){ foldersToScan[i]->SetScanned(false); }
}
void CloneSearcher::MarkToRescan(){ rescanMark = true; }
bool CloneSearcher::GetMarkToRescan(){ return rescanMark; }
void CloneSearcher::ScanFolders()
{
	if (rescanMark)
	{
		RescanCleaning();
		rescanMark=false;
	}
	for (uint i = 0; i < foldersToScan.Size(); i++)
	{
		if (foldersToScan[i]->IsScanned()) continue;
		ScanFolder(foldersToScan[i]);
		foldersToScan[i]->SetScanned();
	}
	//UpdateFilters();
}
bool CloneSearcher::ScanFolder(Folder *folder)
{
	if (!folder) return false;
	WIN32_FIND_DATAW data;
	SAL::String fullName;
	fullName = folder->GetFullName();
	uint folderNameSize = fullName.size;
	if (folderNameSize + 1 > MAX_PATH + 1) return false;
	fullName += L"\\*";
	HANDLE hFile = FindFirstFileW(fullName.str, &data); //current dir (".")
	if (hFile == INVALID_HANDLE_VALUE) return false;
	FindNextFileW(hFile, &data); //parent dir ("..")
	while(FindNextFileW(hFile, &data))
	{
		//if ((data.cFileName[0] == L'.' && data.cFileName[1] == 0) || (data.cFileName[0] == L'.' && data.cFileName[1] == L'.' && data.cFileName[2] == 0)) continue;
		if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			Folder* subFolder;
			subFolder = new Folder(data.cFileName, folder);
			folder->AddFolder(subFolder);
			ScanFolder(subFolder);
			continue;
		}
		if (!scanSystemFiles && data.dwFileAttributes&FILE_ATTRIBUTE_SYSTEM) continue;
		if (!scanHiddenFiles && data.dwFileAttributes&FILE_ATTRIBUTE_HIDDEN) continue;
		if (data.nFileSizeHigh == data.nFileSizeLow && data.nFileSizeLow == 0) continue;
		if (((((uint64)data.nFileSizeHigh) << 32) | ((uint64)data.nFileSizeLow))<minFileSize) continue;
		if (((((uint64)data.nFileSizeHigh) << 32) | ((uint64)data.nFileSizeLow))>maxFileSize) continue;
		AddFile(data.cFileName, (((uint64)data.nFileSizeHigh) << 32) | ((uint64)data.nFileSizeLow), folder);
	}
	FindClose(hFile);
	folder->SetScanned();
	return true;
}
uint CloneSearcher::GetFoldersNumber() const { return foldersToScan.Size(); }
SAL::String CloneSearcher::GetFolderPath(uint i)
{
	if (i >= foldersToScan.Size()) return SAL::String();
	return foldersToScan[i]->GetFullName();
}
bool CloneSearcher::FolderIsScanned(uint i){ return (i < foldersToScan.Size()) ? foldersToScan[i]->IsScanned() : false; }

bool CloneSearcher::AddFile(LPCWSTR fileName, uint64 size, Folder *folder)
{
	File* newFile;
	newFile = new File(fileName, size, folder);
	files.Push(newFile);
	filesSize += size;
	return true;
}
uint CloneSearcher::GetFilesNumber() const { return files.Size(); }
uint64 CloneSearcher::GetFilesSize() const { return filesSize; }
uint64 CloneSearcher::GetFileSize(uint i) { return files[i]->GetByteSize(); }
SAL::String CloneSearcher::GetFileName(uint i)
{
	if (i >= files.Size()) return SAL::String();
	return files[i]->GetFullName();
}
bool CloneSearcher::ProcessFile(uint i)
{
	if (i >= files.Size() || files[i]->IsHashed()) return false;
	uint64 fileSize=0;
	Hash* hash = MD5(files[i]->GetFullName().str, fileSize);
	if (hash)
	{
		files[i]->SetHashed();
		SAL::RBTreeNode<uint64, SAL::RedBlackTree<Hash, VirtualFile*>*> *sizeTreeNode;
		if (!sizeHashTree) sizeHashTree = new SAL::RedBlackTree<uint64, SAL::RedBlackTree<Hash, VirtualFile*>*>();
		sizeTreeNode = sizeHashTree->Search(fileSize);
		if (sizeTreeNode)
		{
			SAL::RBTreeNode<Hash, VirtualFile*> *hashTreeNode;
			hashTreeNode = sizeTreeNode->data->Search(*hash);
			if (hashTreeNode)
			{
				hashTreeNode->data->AddFileInstance(files[i], hash);
			}
			else
			{
				VirtualFile *vfile;
				vfile = new VirtualFile();
				vfile->AddFileInstance(files[i], hash);
				sizeTreeNode->data->Insert(*hash, vfile);
				virtualFiles.Push(vfile);
			}
		}
		else
		{
			VirtualFile *vfile;
			vfile = new VirtualFile();
			vfile->AddFileInstance(files[i], hash);
			SAL::RedBlackTree<Hash, VirtualFile*> *hashTree;
			hashTree = new SAL::RedBlackTree<Hash, VirtualFile*>();
			hashTree->Insert(*hash, vfile);
			sizeHashTree->Insert(fileSize, hashTree);
			virtualFiles.Push(vfile);
		}
	}
	else return false;
	return true;
}
bool CloneSearcher::DetectClones()
{
	for (uint i = 0; i < virtualFiles.Size();)
	{
		if (virtualFiles[i]->GetInstancesNumber() <= 1) virtualFiles.Remove(i);
		else i++;
	}
	UpdateFilters();
	if (virtualFiles.Size()) return true;
	else return false;
}
void CloneSearcher::RedetectClones()
{
	VirtualFile *vFile;
	File *file;
	std::wifstream checkedFile;
	for (uint i = 0; i < virtualFiles.Size();)
	{
		vFile = virtualFiles[i];
		if (!vFile) virtualFiles.Remove(i);
		else
		{
			for (uint j = 0; j < vFile->GetInstancesNumber();)
			{
				file = vFile->GetFileInstance(j);
				if (!file) vFile->RemFileInstance(j);
				else if (file->GetDeletionMark())
				{
					checkedFile.open(file->GetFullName().str, std::ios::in|std::ios::_Nocreate);
					if (!checkedFile) vFile->RemFileInstance(j);
					else { checkedFile.close();  j++; }
				}
				else j++;
			}
			if (vFile->GetInstancesNumber() <= 1)
			{
				virtualFiles.Remove(i);
			}
			else i++;
		}
	}
	UpdateFilters();
}

uint CloneSearcher::GetVFilesNumber() const
{
	if (!filteringIndices || filteringIndices->Size() == virtualFiles.Size() || filteringIndices->Size() == 0) return virtualFiles.Size();
	else return filteringIndices->Size();
}
uint64 CloneSearcher::GetVFilesSize()
{
	uint64 byteSize=0;
	uint instancesNumber;
	for (uint i = 0; i < virtualFiles.Size(); i++)
	{
		instancesNumber = virtualFiles[i]->GetInstancesNumber();
		if (instancesNumber) byteSize += virtualFiles[i]->GetByteSize()*(instancesNumber-1);
	}
	return byteSize;
}
VirtualFile* CloneSearcher::GetVFile(uint vFileID)
{
	if (!filteringIndices || filteringIndices->Size() == virtualFiles.Size() || filteringIndices->Size() == 0)
	{
		if (vFileID >= virtualFiles.Size()) return NULL;
		else return virtualFiles[vFileID];
	}
	else
	{
		if (vFileID >= filteringIndices->Size()) return NULL;
		else return virtualFiles[(uint)((*filteringIndices)[vFileID])];
	}
}
bool CloneSearcher::DeleteMarkedFile(uint vFileID, uint fileID)
{
	VirtualFile *vFile;
	if (!filteringIndices || filteringIndices->Size() == virtualFiles.Size() || filteringIndices->Size() == 0)
	{
		if (vFileID >= virtualFiles.Size()) return false;
		vFile = virtualFiles[vFileID];
	}
	else
	{
		if (vFileID >= filteringIndices->Size()) return false;
		vFile = virtualFiles[(uint)((*filteringIndices)[vFileID])];
	}
	if (!vFile) return false;
	if (fileID >= vFile->GetInstancesNumber()) return false;
	File *file = vFile->GetFileInstance(fileID);
	if (!file) return false;
	if (!file->Delete(this->deleteToRecycleBin)) return false;
	else this->rescanMark = true;
	return true;
}

bool CloneSearcher::InstNumbComparing(VirtualFile *file1, VirtualFile *file2)
{
	if (file1->GetInstancesNumber() < file2->GetInstancesNumber()) return true;
	else return false;
}
bool CloneSearcher::NamesComparing(VirtualFile *file1, VirtualFile *file2)
{
	if (!file1->name || !file2->name) return false;
	setlocale(LC_ALL, "ru");
	//if (_wcscoll_l(file1->name, file2->name, _get_current_locale()) < 0) return true;
	if (wcscoll(file1->name, file2->name) < 0) return true;
	else return false;
}
bool CloneSearcher::ExtComparing(VirtualFile *file1, VirtualFile *file2)
{
	if (!file1->extension || !file2->extension) return false;
	setlocale(LC_ALL, "ru");
	if (wcscoll(file1->extension, file2->extension) < 0) return true;
	else return false;
}
bool CloneSearcher::SizeComparing(VirtualFile *file1, VirtualFile *file2)
{
	if(file1->GetByteSize()<file2->GetByteSize()) return true;
	else return false;
}
bool CloneSearcher::MarksNumberComparing(VirtualFile *file1, VirtualFile *file2)
{
	if (file1->GetDeletionMarksNumber() < file2->GetDeletionMarksNumber()) return true;
	else return false;
}
void CloneSearcher::Sort(SortTypes type, bool reverse)
{
	bool(*lessRelation)(VirtualFile*, VirtualFile*);
	lessRelation = NULL;
	switch (type)
	{
	case SortTypes::None: { lessRelation = NULL; break; }
	case SortTypes::ByExtension: { lessRelation = &ExtComparing; break; }
	case SortTypes::ByInstNumber: { lessRelation = &InstNumbComparing; break; }
	case SortTypes::ByMarksNumber: { lessRelation = &MarksNumberComparing; break; }
	case SortTypes::ByName: { lessRelation = &NamesComparing; break; }
	case SortTypes::BySize: { lessRelation = &SizeComparing; break; }
	}
	if(lessRelation) virtualFiles.Sort(lessRelation, reverse);
	else if (reverse) virtualFiles.Reverse();
	UpdateFiltersStates();
}
bool CloneSearcher::FilterLess(Filter* filter1, Filter* filter2)
{
	if (!filter1->data || !filter2->data) return false;
	setlocale(LC_ALL, "ru");
	if (wcscoll(filter1->data, filter2->data) < 0) return true;
	else return false;
}
void CloneSearcher::UpdateFilters()
{
	std::set<std::wstring> set;
	std::wstring ext;
	uint setSize;
	SAL::List<Filter*> newFilters;
	bool marked;
	for (uint i = 0; i < virtualFiles.Size(); i++)
	{
		if (!virtualFiles[i]) continue;
		ext = L"";
		if (virtualFiles[i]->extension) ext = virtualFiles[i]->extension;
		setSize = set.size();
		set.insert(ext);
		if (setSize == set.size()) continue;
		marked=true;
		for (uint j = 0; j < filters.Size(); j++)
		{
			if (!filters[j]) continue;
			if ((filters[j]->data && virtualFiles[i]->extension && wcscmp(filters[j]->data, virtualFiles[i]->extension) == 0)
				|| (!filters[j]->data && !virtualFiles[i]->extension))
			{
				marked = filters[j]->state;
				break;
			}
		}
		newFilters.Push(new Filter(virtualFiles[i]->extension, marked));
	}
	if (newFilters.Size()) newFilters.Sort(&FilterLess);
	for (uint i = 0; i < filters.Size(); i++)
	{
		if (filters[i]) delete filters[i];
	}
	filters = newFilters;
	UpdateFiltersStates();
}
void CloneSearcher::UpdateFiltersStates()
{
	if (filteringIndices) filteringIndices->Clear();
	else filteringIndices = new SAL::List<uint64>();
	for (uint i = 0; i < virtualFiles.Size(); i++)
	{
		for (uint j = 0; j < filters.Size(); j++)
		{
			if (filters[j] && filters[j]->state)
			{
				if (!filters[j]->data || !virtualFiles[i]->extension)
				{
					if (!filters[j]->data && !virtualFiles[i]->extension)
					{
						filteringIndices->Push(i);
						break;
					}
					else continue;
				}
				else if (filters[j]->data && virtualFiles[i]->extension && wcscmp(filters[j]->data, virtualFiles[i]->extension) == 0)
				{
					filteringIndices->Push(i);
					break;
				}
			}
		}
	}
}
uint CloneSearcher::GetFiltersNumber() const { return filters.Size(); }
const wchar_t* CloneSearcher::GetFilter(uint i){ return (i < filters.Size()) ? filters[i]->data : NULL; }
bool CloneSearcher::GetFilterState(uint i){ return (i < filters.Size()) ? filters[i]->state : false; }
void CloneSearcher::SetFilterState(uint i, bool state){ if (i < filters.Size()) filters[i]->state = state; }

void CloneSearcher::ScanSystemFiles(bool state){ scanSystemFiles = state; }
void CloneSearcher::ScanHiddenFiles(bool state){ scanHiddenFiles = state; }
void CloneSearcher::DeleteToRecycleBin(bool state){ deleteToRecycleBin = state; }
void CloneSearcher::SetMinFileSize(uint16 size){ minFileSize = ((uint64)size) << 20; }
void CloneSearcher::SetMaxFileSize(uint16 size){ maxFileSize = ((uint64)size) << 20; }
bool CloneSearcher::IsScanSystemFiles() const { return scanSystemFiles; }
bool CloneSearcher::IsScanHiddenFiles() const { return scanHiddenFiles; }
bool CloneSearcher::IsDeleteToRecycleBin() const { return deleteToRecycleBin; }
uint16 CloneSearcher::GetMinFileSize() const { return (uint16)(minFileSize >> 20); }
uint16 CloneSearcher::GetMaxFileSize() const { return (uint16)(maxFileSize >> 20); }
void CloneSearcher::SetMemoryForHashing(uint16 memorySize) //1-4095 MB
{
	if (memorySize > 4095) memorySize = 4095;
	else if (memorySize == 0) memorySize = 1;
	Hash::SetMaxRAM(((uint32)memorySize) << 20);//megabytes -> bytes
}
uint16 CloneSearcher::GetMemorySizeForHashing() const { return (uint16)(Hash::GetMaxRAM() >> 20); }