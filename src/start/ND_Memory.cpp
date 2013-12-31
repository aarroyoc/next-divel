/**
 * @file ND_Memory.cpp
 * @author Adrián Arroyo Calle
 * Pedigree Project
 * @brief Implements common memory related functions
 * */

#include <ND_Memory.hpp>

/**
 * @brief Sets the memory to a value
 * @param buf The buffer to set the value
 * @param c The value
 * @param len The length of the buffer
 * @return The new buffer
 * @note POSIX name: memset
 * */
void* ND::Memory::Set(void* buf, int c, size_t len)
{
	unsigned char* tmp=(unsigned char*)buf;
	while(len--)
	{
		*tmp++=c;
	}
	return buf;
}
/**
 * @brief Copies the content of one buffer to another
 * @param dest The destination buffer
 * @param src The original buffer
 * @param len The length of the buffer
 * @return The destination buffer
 * @note POSIX name: memcpy
 * */
void* ND::Memory::Copy(void* dest,const void* src, size_t len)
{
	const unsigned char* sp=(const unsigned char*)src;
	unsigned char* dp=(unsigned char*)dest;
	for(;len!=0;len--) *dp++=*sp++;
	return dest;
}
/**
 * @brief Compares two buffers
 * @param p1 The first buffer
 * @param p2 The second buffer
 * @param len The length of the buffer
 * @return Returns 0 if the buffers are equal, other if not
 * @note POSIX name: memcmp
 * */
int ND::Memory::Compare(const void* p1, const void* p2, size_t len)
{
	const char* a=(const char*)p1;
	const char* b=(const char*)p2;
	size_t i=0;
	for(;i<len;i++)
	{
		if(a[i] < b[i])
			return -1;
		else if(a[i] > b[i])
			return 1;
	}
	return 0;
}
