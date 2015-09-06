/**
 * @file ND_String.cpp
 * @author Adrián Arroyo Calle
 * Pedigree Project
 * @brief Some useful functions for manipulate strings
 * */
 
#include <ND_String.hpp>
#include <ND_Types.hpp>
int ND::String::NumberLength(int num){
	int len = 0;
	if(num < 0){
		num *= -1;
		len++;
	}
	while(num > 0){
		num /= 10;
		len++;
	}
	return len;
}
char* ND::String::itoa(int num)
{
	int len = NumberLength(num);
	int pos = 0;
	char str[len];
	unsigned int tmp;
    if(num<0){
        str[0] = '-';
        num *= -1;
        pos++;
    }
    tmp = 0;
	do{
		tmp = tmp * 10 + num % 10;
		num = num / 10;
	}while(num);
    do{ //Move back, inserting digits as u go
        str[pos] = ((char)(tmp % 10 + 48));
        tmp = tmp / 10;
        pos++;
    }while(tmp);
    return str;
}
size_t ND::String::Length(const char* src)
{
	size_t i=0;
	while(*src--)
		i++;
	return i;
}
int ND::String::Copy(char* dest, const char* src)
{
	int n = 0;
	while (*src)
	{
		*dest++ = *src++;
		n++;
	}
	*dest = '\0';
	return n;
}
int ND::String::Compare(const char *p1, const char *p2)
{
  int i = 0;
  int failed = 0;
  while(p1[i] != '\0' && p2[i] != '\0')
  {
    if(p1[i] != p2[i])
    {
      failed = 1;
      break;
    }
    i++;
  }
  if( (p1[i] == '\0' && p2[i] != '\0') || (p1[i] != '\0' && p2[i] == '\0') )
    failed = 1;

  return failed;
}
char *ND::String::Concatenate(char *dest, const char *src)
{
  int di = ND::String::Length(dest);
  int si = 0;
  while (src[si])
    dest[di++] = src[si++];
  
  dest[di] = '\0';

  return dest;
}
bool ND::String::IsUpper(char c)
{
  return (c >= 'A' && c <= 'Z') ? true : false;
}

bool ND::String::IsLower(char c)
{
  return (c >= 'a' && c <= 'z') ? true : false;
}

bool ND::String::IsDigit(char c)
{
  return (c >= '0' && c <= '9') ? true : false;
}
