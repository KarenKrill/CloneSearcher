#include "stdafx.h"
#include <fstream>

uint32 cls(uint32 a, uint8 s)
{
	return (a << s) | (a >> (32 - s));
} //cyclic left shift

#define F(x,y,z) (((x)&(y))|((~(x))&(z)))
#define G(x,y,z) (((x)&(z))|((~(z))&(y)))
#define H(x,y,z) ((x)^(y)^(z))
#define I(x,y,z) ((y)^((~(z))|(x)))

#define FF_md5(a,b,c,d,k,s,i) (a=(b)+cls((a)+F(b,c,d)+(k)+(i), s))
#define GG_md5(a,b,c,d,k,s,i) (a=(b)+cls((a)+G(b,c,d)+(k)+(i), s))
#define HH_md5(a,b,c,d,k,s,i) (a=(b)+cls((a)+H(b,c,d)+(k)+(i), s))
#define II(a,b,c,d,k,s,i) (a=(b)+cls((a)+I(b,c,d)+(k)+(i), s))

uint32 Hash::maxRAM = 0x01000000; //16 MB
void Hash::SetMaxRAM(uint32 bytesSize){ Hash::maxRAM = bytesSize; }
uint32 Hash::GetMaxRAM(){ return Hash::maxRAM; }

Hash::Hash(){}
Hash::~Hash(){}
bool Hash::operator>(Hash h){ return ((this->first > h.first) || ((this->first == h.first) && (this->second > h.second))) ? true : false; }
bool Hash::operator<(Hash h){ return ((this->first < h.first) || ((this->first == h.first) && (this->second < h.second))) ? true : false; }
bool Hash::operator>=(Hash h){ return ((this->first > h.first) || ((this->first == h.first) && (this->second >= h.second))) ? true : false; }
bool Hash::operator<=(Hash h){ return ((this->first < h.first) || ((this->first == h.first) && (this->second <= h.second))) ? true : false; }
bool Hash::operator==(Hash h){ return ((this->first == h.first) && (this->second == h.second)) ? true : false; }
Hash& Hash::operator=(Hash h){ this->first = h.first; this->second = h.second; return *this; }
Hash *MD5(LPCWSTR fileName, uint64 &byteSize)
{
	char *buffer;
	uint32 blockSize = 64, blockSetSize = Hash::maxRAM / blockSize * blockSize;
	uint64 offsetToBlockSet = 0, offsetToBlock = 0;
	std::ifstream file;
	if (!byteSize)
	{
		file.open(fileName, std::ios::in | std::ios::binary);
		if (!file.is_open()) return NULL;
		file.seekg(0, std::ios::end);
		//if (file.tellg()>0x00000006ffffffff) //<4GB, <=4095MB
		//{
		//	file.close();
		//	return NULL;
		//}
		byteSize = file.tellg();//max <16 EB (exabyte)
		file.close();
	}
	uint64 bitSize = byteSize * 8; //size in bits
	uint32 inverseModulo = 64 - (byteSize + 1) % 64;
	ushort placeholderLength = (ushort)((inverseModulo >= 8) ? inverseModulo - 8 : inverseModulo + 56);
	bool isLastBlockSet = (byteSize <= blockSetSize);
	if (isLastBlockSet) blockSetSize = (uint32)byteSize;
	buffer = new char[blockSetSize + 1 + placeholderLength + 8];//byteSize + 1 + placeholderLength + 8];
	file.open(fileName, std::ios::in | std::ios::binary);
	if (!file.is_open()) { delete[] buffer; return NULL; }
	file.seekg(0, std::ios::beg);
	file.read(buffer, blockSetSize); //read first blockSet
	file.close();
	
	// T[] replaced by constants
	//uint32 T[65];
	//T[0] = 0;
	//for (int i = 1; i <= 64; i++)
	//{
	//	T[i] = (uint32)((double)0x100000000 * abs(sin((double)i))); //2^32 * |sin(i)|
	//}
	uint32 A = 0x67452301, B = 0xefcdab89, C = 0x98badcfe, D = 0x10325476, tempA, tempB, tempC, tempD;
	uint32 X[16];
	bool isLastBlock=false;
	while (!isLastBlock)//offsetToBlock < byteSize + 1 + placeholderLength + 8)
	{
		isLastBlock = (byteSize - offsetToBlockSet - offsetToBlock <= blockSize);
		if (isLastBlock)
		{
			blockSize = (uint32)(byteSize - offsetToBlockSet - offsetToBlock);
			buffer[offsetToBlock + blockSize] = (char)0x80;
			for (ushort i = 0; i < placeholderLength; i++) { buffer[offsetToBlock + blockSize + 1 + i] = 0; }

			buffer[offsetToBlock + blockSize + 1 + placeholderLength] = bitSize & 0xff;
			buffer[offsetToBlock + blockSize + 1 + placeholderLength + 1] = (bitSize >> 8) & 0xff;
			buffer[offsetToBlock + blockSize + 1 + placeholderLength + 2] = (bitSize >> 16) & 0xff;
			buffer[offsetToBlock + blockSize + 1 + placeholderLength + 3] = (bitSize >> 24) & 0xff;

			buffer[offsetToBlock + blockSize + 1 + placeholderLength + 4] = (bitSize >> 32) & 0xff;
			buffer[offsetToBlock + blockSize + 1 + placeholderLength + 5] = (bitSize >> (32 + 8)) & 0xff;
			buffer[offsetToBlock + blockSize + 1 + placeholderLength + 6] = (bitSize >> (32 + 16)) & 0xff;
			buffer[offsetToBlock + blockSize + 1 + placeholderLength + 7] = (bitSize >> (32 + 24)) & 0xff;
		}
		if (offsetToBlock >= blockSetSize)
		{
			offsetToBlockSet += blockSetSize;
			offsetToBlock = 0;
			isLastBlockSet = (byteSize - offsetToBlockSet <= blockSetSize);
			if (isLastBlockSet) blockSetSize = (uint32)(byteSize - offsetToBlockSet);
			file.open(fileName, std::ios::in | std::ios::binary);
			if (!file.is_open())
			{
				delete[] buffer;
				return NULL;
			}
			file.seekg(offsetToBlockSet, std::ios::beg);
			file.read(buffer, blockSetSize);
			file.close();
		}
		for (int i = 0; i<64; i+=4)
		{
			X[i / 4] = ((uint32)((uchar)buffer[offsetToBlock + i]));
			X[i / 4] |= ((uint32)((uchar)buffer[offsetToBlock + i + 1])) << 8;
			X[i / 4] |= ((uint32)((uchar)buffer[offsetToBlock + i + 2])) << 16;
			X[i / 4] |= ((uint32)((uchar)buffer[offsetToBlock + i + 3])) << 24;
 		}
		offsetToBlock += blockSize;
		tempA = A; tempB = B; tempC = C; tempD = D;
		/* Раунд 1. FF_md5(A,B,C,D,k,s,i) - a = b + ((a + F(b,c,d) + k + i) <<< s) */
		FF_md5(A, B, C, D, X[0], 7, 0xd76aa478); FF_md5(D, A, B, C, X[1], 12, 0xe8c7b756); FF_md5(C, D, A, B, X[2], 17, 0x242070db); FF_md5(B, C, D, A, X[3], 22, 0xc1bdceee);
		FF_md5(A, B, C, D, X[4], 7, 0xf57c0faf); FF_md5(D, A, B, C, X[5], 12, 0x4787c62a); FF_md5(C, D, A, B, X[6], 17, 0xa8304613); FF_md5(B, C, D, A, X[7], 22, 0xfd469501);
		FF_md5(A, B, C, D, X[8], 7, 0x698098d8); FF_md5(D, A, B, C, X[9], 12, 0x8b44f7af); FF_md5(C, D, A, B, X[10], 17, 0xffff5bb1); FF_md5(B, C, D, A, X[11], 22, 0x895cd7be);
		FF_md5(A, B, C, D, X[12], 7, 0x6b901122); FF_md5(D, A, B, C, X[13], 12, 0xfd987193); FF_md5(C, D, A, B, X[14], 17, 0xa679438e); FF_md5(B, C, D, A, X[15], 22, 0x49b40821);
		/* Раунд 2. GG_md5(A,B,C,D,k,s,i) - a = b + ((a + G(b,c,d) + k + i) <<< s) */
		GG_md5(A, B, C, D, X[1], 5, 0xf61e2562); GG_md5(D, A, B, C, X[6], 9, 0xc040b340); GG_md5(C, D, A, B, X[11], 14, 0x265e5a51); GG_md5(B, C, D, A, X[0], 20, 0xe9b6c7aa);
		GG_md5(A, B, C, D, X[5], 5, 0xd62f105d); GG_md5(D, A, B, C, X[10], 9, 0x2441453); GG_md5(C, D, A, B, X[15], 14, 0xd8a1e681); GG_md5(B, C, D, A, X[4], 20, 0xe7d3fbc8);
		GG_md5(A, B, C, D, X[9], 5, 0x21e1cde6); GG_md5(D, A, B, C, X[14], 9, 0xc33707d6); GG_md5(C, D, A, B, X[3], 14, 0xf4d50d87); GG_md5(B, C, D, A, X[8], 20, 0x455a14ed);
		GG_md5(A, B, C, D, X[13], 5, 0xa9e3e905); GG_md5(D, A, B, C, X[2], 9, 0xfcefa3f8); GG_md5(C, D, A, B, X[7], 14, 0x676f02d9); GG_md5(B, C, D, A, X[12], 20, 0x8d2a4c8a);
		/* Раунд 3. HH_md5(A,B,C,D,k,s,i) - a = b + ((a + H(b,c,d) + k + i) <<< s) */
		HH_md5(A, B, C, D, X[5], 4, 0xfffa3942); HH_md5(D, A, B, C, X[8], 11, 0x8771f681); HH_md5(C, D, A, B, X[11], 16, 0x6d9d6122); HH_md5(B, C, D, A, X[14], 23, 0xfde5380c);
		HH_md5(A, B, C, D, X[1], 4, 0xa4beea44); HH_md5(D, A, B, C, X[4], 11, 0x4bdecfa9); HH_md5(C, D, A, B, X[7], 16, 0xf6bb4b60); HH_md5(B, C, D, A, X[10], 23, 0xbebfbc70);
		HH_md5(A, B, C, D, X[13], 4, 0x289b7ec6); HH_md5(D, A, B, C, X[0], 11, 0xeaa127fa); HH_md5(C, D, A, B, X[3], 16, 0xd4ef3085); HH_md5(B, C, D, A, X[6], 23, 0x4881d05);
		HH_md5(A, B, C, D, X[9], 4, 0xd9d4d039); HH_md5(D, A, B, C, X[12], 11, 0xe6db99e5); HH_md5(C, D, A, B, X[15], 16, 0x1fa27cf8); HH_md5(B, C, D, A, X[2], 23, 0xc4ac5665);
		/* Раунд 4. II(a,b,c,d,k,s,i) - a = b + ((a + I(b,c,d) + k + i) <<< s). */
		II(A, B, C, D, X[0], 6, 0xf4292244); II(D, A, B, C, X[7], 10, 0x432aff97); II(C, D, A, B, X[14], 15, 0xab9423a7); II(B, C, D, A, X[5], 21, 0xfc93a039);
		II(A, B, C, D, X[12], 6, 0x655b59c3); II(D, A, B, C, X[3], 10, 0x8f0ccc92); II(C, D, A, B, X[10], 15, 0xffeff47d); II(B, C, D, A, X[1], 21, 0x85845dd1);
		II(A, B, C, D, X[8], 6, 0x6fa87e4f); II(D, A, B, C, X[15], 10, 0xfe2ce6e0); II(C, D, A, B, X[6], 15, 0xa3014314); II(B, C, D, A, X[13], 21, 0x4e0811a1);
		II(A, B, C, D, X[4], 6, 0xf7537e82); II(D, A, B, C, X[11], 10, 0xbd3af235); II(C, D, A, B, X[2], 15, 0x2ad7d2bb); II(B, C, D, A, X[9], 21, 0xeb86d391);
		A += tempA; B += tempB; C += tempC; D += tempD;
	}
	delete[] buffer;
	Hash *hash;
	hash = new Hash();
	hash->first = ((uint64)A) << 32 | ((uint64)B);
	hash->second = ((uint64)C) << 32 | ((uint64)D);
	return hash;
}
wchar_t *Hash::ToWstr()
{
	uint32 A = (uint32)(this->first >> 32), B = (uint32)this->first, C = (uint32)(this->second >> 32), D = (uint32)this->second;
	uint8 res[32];
	res[0] = (A >> 4) & 15; res[1] = A & 15;
	res[2] = ((A >> 8) >> 4) & 15; res[3] = (A >> 8) & 15;
	res[4] = ((A >> 16) >> 4) & 15; res[5] = (A >> 16) & 15;
	res[6] = ((A >> 24) >> 4) & 15; res[7] = (A >> 24) & 15;
	res[8] = (B >> 4) & 15; res[9] = B & 15;
	res[10] = ((B >> 8) >> 4) & 15; res[11] = (B >> 8) & 15;
	res[12] = ((B >> 16) >> 4) & 15; res[13] = (B >> 16) & 15;
	res[14] = ((B >> 24) >> 4) & 15; res[15] = (B >> 24) & 15;
	res[16] = (C >> 4) & 15; res[17] = C & 15;
	res[18] = ((C >> 8) >> 4) & 15; res[19] = (C >> 8) & 15;
	res[20] = ((C >> 16) >> 4) & 15; res[21] = (C >> 16) & 15;
	res[22] = ((C >> 24) >> 4) & 15; res[23] = (C >> 24) & 15;
	res[24] = (D >> 4) & 15; res[25] = D & 15;
	res[26] = ((D >> 8) >> 4) & 15; res[27] = (D >> 8) & 15;
	res[28] = ((D >> 16) >> 4) & 15; res[29] = (D >> 16) & 15;
	res[30] = ((D >> 24) >> 4) & 15; res[31] = (D >> 24) & 15;

	wchar_t *resStr;
	resStr = new wchar_t[32 + 1];
	for (uint i = 0; i < 32; i++)
	{
		if (res[i] < 10) resStr[i] = L'0' + res[i];
		else
		{
			switch (res[i])
			{
			case 10: resStr[i] = L'a'; break;
			case 11: resStr[i] = L'b'; break;
			case 12: resStr[i] = L'c'; break;
			case 13: resStr[i] = L'd'; break;
			case 14: resStr[i] = L'e'; break;
			case 15: resStr[i] = L'f'; break;
			}
		}
	}
	resStr[32] = 0;
	return resStr;
}