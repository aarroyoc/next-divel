/**
 * @file ND_Memory.hpp
 * @author Adrián Arroyo Calle
 * @brief Memory related functions
 * */

#ifndef ND_MEMORY_HPP
#define ND_MEMORY_HPP

#include <ND_Types.hpp>

namespace ND{
		namespace Memory{
				void* Set(void* buf, int c, size_t len);
				void* Copy(void* dest,const void* src, size_t len);
				int Compare(const void* p1, const void* p2, size_t len);
			}
	}


#endif
