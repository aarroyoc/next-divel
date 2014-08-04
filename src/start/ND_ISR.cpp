/**
 * @file ND_ISR.cpp
 * @author Adrián Arroyo Calle
 * @brief ISR related functions
 * */
#include <ND_ISR.hpp>
#include <ND_Screen.hpp>
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
	}
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString("\n GS = ");
	ND::Screen::itoa(r->gs);
	ND::Screen::PutString("   FS = ");
	ND::Screen::itoa(r->fs);
	ND::Screen::PutString("\n ES = ");
	ND::Screen::itoa(r->es);
	ND::Screen::PutString("\n DS = ");
	ND::Screen::itoa(r->ds);
	ND::Screen::PutString("\nEDI = ");
	ND::Screen::itoa(r->edi);
	ND::Screen::PutString("   ESI = ");
	ND::Screen::itoa(r->esi);
	ND::Screen::PutString("\nEBP = ");
	ND::Screen::itoa(r->ebp);
	ND::Screen::PutString("   ESP = ");
	ND::Screen::itoa(r->esp);
	ND::Screen::PutString("\nEBX = ");
	ND::Screen::itoa(r->ebx);
	ND::Screen::PutString("   EDX = ");
	ND::Screen::itoa(r->edx);
	ND::Screen::PutString("\nECX = ");
	ND::Screen::itoa(r->ecx);
	ND::Screen::PutString("   EAX = ");
	ND::Screen::itoa(r->eax);
	ND::Screen::PutString("\nINT_NO = ");
	ND::Screen::itoa(r->int_no);
	ND::Screen::PutString("   ERR_CODE = ");
	ND::Screen::itoa(r->err_code);
	ND::Screen::PutString("\nEIP = ");
	ND::Screen::itoa(r->eip);
	ND::Screen::PutString("    CS = ");
	ND::Screen::itoa(r->cs);
	ND::Screen::PutString("\nEFLAGS = ");
	ND::Screen::itoa(r->eflags);
	ND::Screen::PutString("   USERESP = ");
	ND::Screen::itoa(r->useresp);
	ND::Screen::PutString("\n SS = ");
	ND::Screen::itoa(r->ss);
	for(;;);
}

extern "C"{
void ND_ISR_Common()
{
	asm volatile(
	"popl %ebp	   \n"	
	"pushal	   \n"
	"pushl	%ds\n"//ds
	"pushl	%es\n"//es
	"pushl	%fs\n"//fs
	"pushl	%gs\n"//gs
	"movw $0x10, %ax \n"
	"movw %ax, %ds \n"
	"movw %ax, %es \n"
	"movw %ax, %fs \n"
	"movw %ax, %gs \n"
	"pushl %esp \n"
	"movl $ND_ISR_Handler, %eax \n"
	"call *%eax \n"
	"popl %esp \n"
	"popl %gs \n"
	"popl %fs \n"
	"popl %es \n"
	"popl %ds \n"
	"popal    \n"
	"add $0x8, %esp \n"
	"sti	\n"
	"iret \n"
	);
}

void ND::ISR::ISR1()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x00\n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR2()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x01 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR3()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x02 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR4()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x03 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR5()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x04 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR6()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x05 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR7()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x06 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR8()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x07 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR9()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x08 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR10()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x09 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR11()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x0A \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR12()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x0B \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR13()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x0C \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR14()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x0D \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR15()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x0E \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR16()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x0F \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR17()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x10 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR18()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x11 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR19()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x12 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR20()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x13 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR21()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x14 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR22()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x15 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR23()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x16 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR24()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x17 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR25()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x18 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR26()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x19 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR27()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x1A \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR28()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x1B \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR29()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x1C \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR30()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x1D \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR31()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x1E \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR32()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x1F \n"
	"jmp ND_ISR_Common \n"
	);
}
}
