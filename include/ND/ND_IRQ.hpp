/**
 * @file ND_IRQ.hpp
 * @author Adrián Arroyo Calle
 * @brief Interrupt Request
 * */
#ifndef ND_IRQ_HPP
#define ND_IRQ_HPP
#include <ND_Types.hpp>
namespace ND{
		namespace IRQ{
				void UninstallHandler(int irq_code);
				void Remap(int pic1, int pic2);
				void Install();
				void IRQ1();
				void IRQ2();
				void IRQ3();
				void IRQ4();
				void IRQ5();
				void IRQ6();
				void IRQ7();
				void IRQ8();
				void IRQ9();
				void IRQ10();
				void IRQ11();
				void IRQ12();
				void IRQ13();
				void IRQ14();
				void IRQ15();
				void IRQ16();
		}
}
extern "C"
{
	void ND_IRQ_Handler(struct regs* r);
	void ND_IRQ_Common();
	void ND_IRQ_InstallHandler(int irq_code,void (*handler)(struct regs* r));
}


#endif
