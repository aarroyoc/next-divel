/**
 * @file ND_ISR.hpp
 * @author Adrián Arroyo Calle
 * @brief ISR related functions
 * */
#ifndef ND_ISR_HPP
#define ND_ISR_HPP
#include <ND_Types.hpp>
namespace ND{
	namespace ISR{
			void ISR1();
		}
	}
extern "C"{
	struct regs{
		uint32_t ds;
		uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
		uint32_t int_no, err_code;
		uint32_t eip, cs, eflags, useresp, ss;  
	};
	void ND_ISR_Handler(struct regs* r);
	void ND_ISR_Common();
}
#endif
