#pragma once

class Hash
{
public:
	uint64 first, second;//hash parts
	static uint32 maxRAM; //buffer size for the hashed file (in bytes); < 4 GB
public:
	Hash();
	~Hash();
	static void SetMaxRAM(uint32 bytesSize);
	static uint32 GetMaxRAM();
	bool operator>(Hash h);
	bool operator<(Hash h);
	bool operator>=(Hash h);
	bool operator<=(Hash h);
	bool operator==(Hash h);
	Hash& operator=(Hash h);
	wchar_t *ToWstr();
};
Hash *MD5(LPCWSTR fileName, uint64 &size);