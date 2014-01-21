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
			void ISR2();
			void ISR3();
			void ISR4();
			void ISR5();
			void ISR6();
			void ISR7();
			void ISR8();
			void ISR9();
			void ISR10();
			void ISR11();
			void ISR12();
			void ISR13();
			void ISR14();
			void ISR15();
			void ISR16();
			void ISR17();
			void ISR18();
			void ISR19();
			void ISR20();
			void ISR21();
			void ISR22();
			void ISR23();
			void ISR24();
			void ISR25();
			void ISR26();
			void ISR27();
			void ISR28();
			void ISR29();
			void ISR30();
			void ISR31();
			void ISR32();
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
