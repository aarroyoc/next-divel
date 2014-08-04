/**
 * @file ND_IRQ.hpp
 * @author Adrián Arroyo Calle
 * @brief Interrupt Request
 * */
#ifndef ND_IRQ_HPP
#define ND_IRQ_HPP
#include <ND_Types.hpp>

extern "C"{
namespace ND{
		namespace IRQ{
				extern void UninstallHandler(int irq_code);
				extern void Remap(int pic1, int pic2);
				extern void Install();
				extern void IRQ1();
				extern void IRQ2();
				extern void IRQ3();
				extern void IRQ4();
				extern void IRQ5();
				extern void IRQ6();
				extern void IRQ7();
				extern void IRQ8();
				extern void IRQ9();
				extern void IRQ10();
				extern void IRQ11();
				extern void IRQ12();
				extern void IRQ13();
				extern void IRQ14();
				extern void IRQ15();
				extern void IRQ16();
		}
}
}
extern "C"
{
	void ND_IRQ_Handler(struct regs *r);
	void ND_IRQ_Common();
	void ND_IRQ_InstallHandler(int irq_code,void (*handler)(struct regs* r));
}


#endif
