#include "stdafx.h"
using namespace SAL;

String::String()
{
	reserved=64;
	size=0;
	str=new wchar_t[reserved];
	str[0]=0;
}
String::String(const String &srcString)
{
	this->reserved=srcString.reserved;
	this->size=srcString.size;
	this->str=new wchar_t[this->reserved];
	memcpy((void*)this->str, (const void*)srcString.str, this->size*sizeof(*this->str));
	this->str[this->size]=0;
}
String::String(const wchar_t *s)
{
	if(!s) return;
	size=StrLength(s);
	if(size<64) reserved=64;
	else reserved=size+64;
	str=new wchar_t[reserved];
	memcpy((void*)str, (const void*)s, size*sizeof(*s));
	str[size]=0;
}
String::String(int reservedSize)
{
	reserved=reservedSize;
	size=0;
	str=new wchar_t[reserved];
	str[0]=0;
}
String::String(SYSTEMTIME &time)
{
	size=23; reserved=64;
	str=new wchar_t[reserved];
	str[0]=L'0'+time.wDay/10; str[1]=L'0'+time.wDay%10; str[2]=L'.';
	str[3]=L'0'+time.wMonth/10; str[4]=L'0'+time.wMonth%10; str[5]=L'.';
	memcpy((void*)(str+6), (const void*)IntToStr(time.wYear), 4*sizeof(wchar_t));
	str[10]=L' ';
	str[11]=L'0'+time.wHour/10; str[12]=L'0'+time.wHour%10; str[13]=L':';
	str[14]=L'0'+time.wMinute/10; str[15]=L'0'+time.wMinute%10; str[16]=L':';
	str[17]=L'0'+time.wSecond/10; str[18]=L'0'+time.wSecond%10; str[19]=L':';
	str[20]=L'0'+time.wMilliseconds/100; str[21]=L'0'+(time.wMilliseconds/10)%10; str[22]=L'0'+time.wMilliseconds%10;
	str[size]=0;
}
String::~String()
{
	if(str) {delete [] str; str=0; reserved=0; size=0;}
}

void String::Pop()
{
	if(!this->str||!this->size||!this->reserved) return;
	this->str[this->size-1]=0;
	this->size--;
}
void String::Pop(uint start, uint length)
{
	if(!length||start>=size) return;
	if(start+length>size) length=size-start;
	uint copyLength=size-start-length;
	memcpy((void*)(str+start), (const void*)(str+start+length), copyLength*sizeof(str));
	size-=length;
	str[size]=0;
}

bool String::Push(const wchar_t *s, uint caret, uint line)
{
	if(!this->str||!this->reserved||!s) return false;
	uint iterator=GetIterator(caret, line);
	wchar_t *temp;
	uint sSize=String::StrLength(s);
	if(sSize>=reserved-size)
	{
		reserved+=sSize;
		temp=new wchar_t[reserved];
		memcpy((void*)temp, (const void*)str, iterator*sizeof(*str));
		memcpy((void*)(temp+iterator), (const void*)s, sSize*sizeof(*s));
		memcpy((void*)(temp+iterator+sSize), (const void*)(str+iterator), (size-iterator)*sizeof(*str));
		delete [] str;
		str=temp;
	}
	else
	{
		if(iterator+1<size)
		{
			temp=new wchar_t[size-iterator+1];
			memcpy((void*)temp, (const void*)(str+iterator), (size-iterator)*sizeof(*str));
			temp[size-iterator]=0;
			memcpy((void*)(str+iterator+sSize), (const void*)temp, (size-iterator)*sizeof(*str));
			delete temp; temp=NULL;
		}
		memcpy((void*)(str+iterator), (const void*)s, sSize*sizeof(*s));
	}
	size+=sSize;
	str[size]=0;
	return true;
}
uint String::GetIterator(uint caret, uint line)
{
	uint iterator=0;
	if(line)
	{
		while(iterator+1<size)
		{
			if(str[iterator]==L'\r'&&str[iterator+1]==L'\n') {line--; iterator++;}
			iterator++;
		}
		if(line) return size;
	}
	iterator+=caret;
	if(iterator>size) return size;
	return iterator;
}
wchar_t String::operator[](uint i){if(i<=size) return str[i]; else return 0;}

String& String::operator=(const wchar_t *s)
{
	if(!s) return *this;
	size=StrLength(s);
	if(size>=reserved)
	{
		reserved+=size;
		delete [] str;
		str=new wchar_t[reserved];
	}
	memcpy((void*)str, (const void*)s, size*sizeof(s[0]));
	str[size]=0;
	return *this;
}
String& String::operator=(const char *s){*this=CharToWchar(s); return *this;}
String& String::operator=(String &s)
{
	size=s.size;
	if(size>=reserved)
	{
		reserved=s.reserved;
		delete [] str;
		str=new wchar_t[reserved];
	}
	memcpy((void*)str, (const void*)(s.str), size*sizeof(s.str[0]));
	str[size]=0;
	return *this;
}
String& String::operator+=(const wchar_t *s)
{
	if(!s) return *this;
	uint sSize=StrLength(s);
	if(sSize>=reserved-size)
	{
		reserved+=sSize;
		wchar_t *temp;
		temp=new wchar_t[reserved];
		memcpy((void*)temp, (const void*)str, size*sizeof(*str));
		delete [] str;
		str=temp;
	}
	memcpy((void*)(str+size),(const void*)s,sSize*sizeof(*s));
	size+=sSize;
	str[size]=0;
	return *this;
}
String& String::operator+=(const char *s)
{return (*this+=CharToWchar(s));}
String& String::operator+=(const String &s)
{
	if(s.size>=reserved-size)
	{
		reserved+=s.size;
		wchar_t *temp;
		temp=new wchar_t[reserved];
		memcpy((void*)temp, (const void*)str, size*sizeof(*str));
		delete [] str;
		str=temp;
	}
	memcpy((void*)(str+size), (const void*)s.str, s.size*sizeof(*s.str));
	size+=s.size;
	str[size]=0;
	return *this;
}

String& String::operator+=(int n) {return ((*this)+=IntToStr(n));}

bool String::operator==(SAL::String &s)
{
	if (this->size != s.size) return false;
	for (uint i = 0; i < size; i++)
	{
		if (str[i] != s.str[i]) return false;
	}
	return true;
}
bool String::operator!=(SAL::String &s){ return !((*this) == s); }

String& SAL::operator+(String &Str, const wchar_t *s) { return (*(new String(Str))) += s; }
String& SAL::operator+(const wchar_t *s, String &Str) { return (*(new String(s))) += Str; }
String& SAL::operator+(String &Str, const char *s){ return (*(new String(Str))) += s; }

template <class T> uint String::StrLength(const T *Str)
{
	if(!Str) return 0;
	uint length=0;
	while(Str[length]!=L'\0') length++;
	return length;
}
wchar_t* String::IntToStr(int n)
{
	wchar_t* res;
	unsigned int temp, size=1, i;
	if(n<0) {n*=-1; size++;}
	temp=n;
	while(temp>9){temp/=10; size++;}
	i=size;
	res=new wchar_t[size+1];
	if(n==0) {res[0]=L'0'; i--;}
	temp=n;
	while(temp!=0)
	{
		i--;
		res[i]=L'0'+temp%10;
		temp/=10;
	}
	if(i) res[0]=L'-';
	res[size]=0;
	return res;
}
wchar_t* String::CharToWchar(const char* cstr)
{
	if(!cstr) return NULL;
	uint length=StrLength(cstr);
	wchar_t *wstr;
	wstr=new wchar_t[length+1];
	MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, cstr, length, wstr, 2*length);
	wstr[length]=0;
	return wstr;
}

bool SAL::operator==(const wchar_t *s, SAL::String &Str)
{
	if (!s) return false;
	uint i = 0;
	while (s[i] && i<Str.size && s[i] == Str[i]){ i++; }
	if (!s[i] && i == Str.size) return true;
	return false;
}
bool SAL::operator>=(const wchar_t *s, SAL::String &Str)
{
	if (!s) return false;
	uint i = 0;
	while (s[i] && i<Str.size && s[i] == Str[i]){ i++; }
	if (i == Str.size) return true;
	return false;
}
bool SAL::operator<=(const wchar_t *s, SAL::String &Str)
{
	if (!s) return false;
	uint i = 0;
	while (s[i] && i<Str.size && s[i] == Str[i]){ i++; }
	if (!s[i]) return true;
	return false;
}
//String& System::operator<<(System::String &Str, const wchar_t *s)
//{
//	return (*(new System::String(s)))+=Str;
//}
