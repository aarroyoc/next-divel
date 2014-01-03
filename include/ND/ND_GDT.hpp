/**
 * @file ND_GDT.hpp
 * @author Adrián Arroyo Calle
 * @brief Interface for create GDT descriptions
 * */
#include <stdint.h>
#ifndef ND_GDT_HPP
#define ND_GDT_HPP

namespace ND{
		namespace GDT{
				void SetGate(int num, uint32_t base, uint32_t limit, uint8_t access,uint8_t gran);
				void Install();
				struct Entry{
						uint16_t limit_low;
						uint16_t base_low;
						uint8_t base_middle;
						uint8_t access;
						uint8_t granularity;
						uint8_t base_high;
				} __attribute__((packed));
				struct Ptr{
						uint16_t limit;
						uint32_t base;
				} __attribute__((packed));
		}
	
}


#endif
