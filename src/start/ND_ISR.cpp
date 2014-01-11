/**
 * @file ND_ISR.cpp
 * @author Adrián Arroyo Calle
 * @brief ISR related functions
 * */
#include <ND_ISR.hpp>
#include <ND_Panic.hpp>

const char* exception_messages[]=
{
	"Division by zero",
	"Debug exception",
	"Non maskable interrupt exception",
	"Breakpoint exception",
	"Into detected overflow exception",
	"Out of bounds exception",
	"Invalid opcode",
	"No coprocessor exception",
	"Double fault exception",
	"Coprocessor segment overrdide exception",
	"Bad TSS exception",
	"Segment not present exception",
	"Stack fault exception",
	"General protection fault exception",
	"Page fault exception",
	"Unknown interrupt exception",
	"Coprocessor fault exception",
	"Alignment check exception",
	"Machine check exception",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved"
};
extern "C"
void ND_ISR_Handler(struct regs *r)
{
	if(r->int_no < 32)
	{
		ND::Panic::Show(exception_messages[r->int_no]);
		for(;;);
	}
}
extern "C"
void ND_ISR_Common()
{
	asm volatile(
	"pusha \n"
	"push %ds \n"
	"push %es \n"
	"push %fs \n"
	"push %gs \n"
	"movw $0x10, %ax \n"
	"movw %ax, %ds \n"
	"movw %ax, %es \n"
	"movw %ax, %fs \n"
	"movw %ax, %gs \n"
	"movl %esp, %eax \n"
	"push %eax \n"
	"movl $ND_ISR_Handler, %eax \n"
	"call *%eax \n"
	"popl %eax \n"
	"popl %ds \n"
	"popl %es \n"
	"popl %fs \n"
	"popl %gs \n"
	"popa \n"
	"addl 8, %esp \n"
	"iret \n"
	);
}
void ND::ISR::ISR1()
{
	asm volatile(
	"cli \n"
	"pushl 0 \n"
	"pushl 0 \n"
	"jmp ND_ISR_Common \n"
	);
}
