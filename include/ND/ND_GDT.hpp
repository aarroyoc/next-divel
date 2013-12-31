/**
 * @file ND_GDT.hpp
 * @author Adrián Arroyo Calle
 * @brief Interface for create GDT descriptions
 * */
#include <ND_Types.hpp>
#ifndef ND_GDT_HPP
#define ND_GDT_HPP

namespace ND{
		namespace GDT{
				void SetGate(int num, unsigned long base, unsigned long limit, unsigned char access,unsigned char gran);
				void Install();
				struct Entry{
						unsigned short limit_low;
						unsigned short base_low;
						unsigned char base_middle;
						unsigned char access;
						unsigned char granularity;
						unsigned char base_high;
				} __attribute__((packed));
				struct Ptr{
						unsigned short limit;
						unsigned int base;
				} __attribute__((packed));
		}
	
}


#endif
