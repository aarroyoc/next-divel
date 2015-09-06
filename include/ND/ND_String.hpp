/**
 * @file ND_String.hpp
 * @author Adrián Arroyo Calle
 * @brief Functions for manipulate strings
 * */

#ifndef ND_STRING_HPP
#define ND_STRING_HPP

#include <ND_Types.hpp>

namespace ND{
		namespace String{
				size_t Length(const char* src);
				int Copy(char* dest, const char* src);
				int Compare(const char *p1, const char *p2);
				char* Concatenate(char *dest, const char *src);
				bool IsUpper(char c);
				bool IsLower(char c);
				bool IsDigit(char c);
				char* itoa(int num);
				int NumberLength(int num);
			}
	
	}
#endif
