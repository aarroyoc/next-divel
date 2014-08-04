/**
 * @file ND_ISR.hpp
 * @author Adrián Arroyo Calle
 * @brief ISR related functions
 * */
#ifndef ND_ISR_HPP
#define ND_ISR_HPP
#include <ND_Types.hpp>

extern "C"{
namespace ND{
	namespace ISR{
            extern void ISR1();
			extern void ISR2();
			extern void ISR3();
			extern void ISR4();
			extern void ISR5();
			extern void ISR6();
			extern void ISR7();
			extern void ISR8();
			extern void ISR9();
			extern void ISR10();
			extern void ISR11();
			extern void ISR12();
			extern void ISR13();
			extern void ISR14();
			extern void ISR15();
			extern void ISR16();
			extern void ISR17();
			extern void ISR18();
			extern void ISR19();
			extern void ISR20();
			extern void ISR21();
			extern void ISR22();
			extern void ISR23();
			extern void ISR24();
			extern void ISR25();
			extern void ISR26();
			extern void ISR27();
			extern void ISR28();
			extern void ISR29();
			extern void ISR30();
			extern void ISR31();
			extern void ISR32();
		}
	}
}

extern "C"{
    struct regs{
	    uint32_t gs, fs, es, ds;      /* pushed the segs last gs, fs, es, */
    	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
	    uint32_t int_no, err_code;    /* our 'push byte #' and ecodes do this */
    	uint32_t eip, cs, eflags, useresp, ss;   /* pushed by the processor automatically */
	};

	void ND_ISR_Handler(struct regs* r);
	void ND_ISR_Common();
}
#endif
