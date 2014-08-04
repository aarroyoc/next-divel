/**
 * @file ND_IRQ.hpp
 * @author Adrián Arroyo Calle
 * @brief Interrupt Requests
 * */

#include <ND_IRQ.hpp>
#include <ND_Ports.hpp>
#include <ND_IDT.hpp>
#include <ND_ISR.hpp>
#include <ND_Screen.hpp>

void *irq[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

extern "C"
void ND_IRQ_InstallHandler(int irq_code,void (*handler)(struct regs* r))
{
	irq[irq_code]=(void *)handler;
}
void ND::IRQ::UninstallHandler(int irq_code)
{
	irq[irq_code]=0;
}
void ND::IRQ::Install()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLACK);
	ND::Screen::PutString("\nInstalling IRQ...");

	ND::IRQ::Remap(0x20,0x28);

	ND::IDT::SetGate(32,(uint32_t)ND::IRQ::IRQ1,0x08,0x8E);
	ND::IDT::SetGate(33,(uint32_t)ND::IRQ::IRQ2,0x08,0x8E);
	ND::IDT::SetGate(34,(uint32_t)ND::IRQ::IRQ3,0x08,0x8E);
	ND::IDT::SetGate(35,(uint32_t)ND::IRQ::IRQ4,0x08,0x8E);
	ND::IDT::SetGate(36,(uint32_t)ND::IRQ::IRQ5,0x08,0x8E);
	ND::IDT::SetGate(37,(uint32_t)ND::IRQ::IRQ6,0x08,0x8E);
	ND::IDT::SetGate(38,(uint32_t)ND::IRQ::IRQ7,0x08,0x8E);
	ND::IDT::SetGate(39,(uint32_t)ND::IRQ::IRQ8,0x08,0x8E);
	ND::IDT::SetGate(40,(uint32_t)ND::IRQ::IRQ9,0x08,0x8E);
	ND::IDT::SetGate(41,(uint32_t)ND::IRQ::IRQ10,0x08,0x8E);
	ND::IDT::SetGate(42,(uint32_t)ND::IRQ::IRQ11,0x08,0x8E);
	ND::IDT::SetGate(43,(uint32_t)ND::IRQ::IRQ12,0x08,0x8E);
	ND::IDT::SetGate(44,(uint32_t)ND::IRQ::IRQ13,0x08,0x8E);
	ND::IDT::SetGate(45,(uint32_t)ND::IRQ::IRQ14,0x08,0x8E);
	ND::IDT::SetGate(46,(uint32_t)ND::IRQ::IRQ15,0x08,0x8E);
	ND::IDT::SetGate(47,(uint32_t)ND::IRQ::IRQ16,0x08,0x8E);

	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString("done");

//	ND::IDT::Flush();

//	asm volatile("sti");
}
void ND::IRQ::Remap(int pic1, int pic2)
{

#define PIC1 0x20
#define PIC2 0xA0

#define ICW1 0x11
#define ICW4 0x01

	ND::Ports::OutputB(PIC1, ICW1); /* write ICW1 to PICM, we are gonna write commands to PICM */
	ND::Ports::OutputB(PIC2, ICW1); /* write ICW1 to PICS, we are gonna write commands to PICS */

	ND::Ports::OutputB(PIC1 + 1, pic1); /* remap PICM to 0x20 (32 decimal) */
	ND::Ports::OutputB(PIC2 + 1, pic2); /* remap PICS to 0x28 (40 decimal) */

	ND::Ports::OutputB(PIC1 + 1, 0x04); /* IRQ2 -> connection to slave */
	ND::Ports::OutputB(PIC2 + 1, 0x02);

	ND::Ports::OutputB(PIC1 + 1, ICW4); /* write ICW4 to PICM, we are gonna write commands to PICM */
	ND::Ports::OutputB(PIC2 + 1, ICW4); /* write ICW4 to PICS, we are gonna write commands to PICS */

	ND::Ports::OutputB(PIC1 + 1, 0x01); /* enable all IRQs on PICM */
	ND::Ports::OutputB(PIC2 + 1, 0x01); /* enable all IRQs on PICS */

	/* disable all IRQs */
//	ND::Ports::OutputB(PIC1 + 1, 0xFF); /* disable all IRQs on PICM */
//	ND::Ports::OutputB(PIC2 + 1, 0xFF); /* disable all IRQs on PICS */
	ND::Ports::OutputB(PIC1 + 1, 0x00);
	ND::Ports::OutputB(PIC2 + 1, 0x00);
}

extern "C"
void ND_IRQ_Handler(struct regs *r)
{
/*/	ND::Screen::PutString("\n GS = ");
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
	ND::Screen::PutChar('\n');
*/
	void (*handler)(struct regs *r);

	handler = (void (*)(struct regs *r))irq[r->int_no - 0x20];
	if(handler != 0)
	{
		handler(r);
	}
	if(r->int_no >= 0x28)
	{
		ND::Ports::OutputB(0xA0,0x20);
	}
	ND::Ports::OutputB(0x20,0x20);
}

extern "C"{
void ND_IRQ_Common()
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
	"movl $ND_IRQ_Handler, %eax \n"
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

void ND::IRQ::IRQ1()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli	\n"
	"pushl	$0x00\n"
	"pushl	$0x20\n"
	"jmp ND_IRQ_Common"
	);
}

void ND::IRQ::IRQ2()
{
	asm volatile(
	"popl %ebp	\n"	
	"cli	\n"
	"pushl	$0x00\n"
	"pushl	$0x21\n"
	"jmp ND_IRQ_Common"
	);
}
void ND::IRQ::IRQ3()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli	\n"
	"pushl	$0x00\n"
	"pushl	$0x22\n"
	"jmp ND_IRQ_Common"
	);
}
void ND::IRQ::IRQ4()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli	\n"
	"pushl	$0x00\n"
	"pushl	$0x23\n"
	"jmp ND_IRQ_Common"
	);
}
void ND::IRQ::IRQ5()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli	\n"
	"pushl	$0x00\n"
	"pushl	$0x24\n"
	"jmp ND_IRQ_Common"
	);
}
void ND::IRQ::IRQ6()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli	\n"
	"pushl	$0x00\n"
	"pushl	$0x25\n"
	"jmp ND_IRQ_Common"
	);
}
void ND::IRQ::IRQ7()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli	\n"
	"pushl	$0x00\n"
	"pushl	$0x26\n"
	"jmp ND_IRQ_Common"
	);
}
void ND::IRQ::IRQ8()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli	\n"
	"pushl	$0x00\n"
	"pushl	$0x27\n"
	"jmp ND_IRQ_Common"
	);
}
void ND::IRQ::IRQ9()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli	\n"
	"pushl	$0x00\n"
	"pushl	$0x28\n"
	"jmp ND_IRQ_Common"
	);
}
void ND::IRQ::IRQ10()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli	\n"
	"pushl	$0x00\n"
	"pushl	$0x29\n"
	"jmp ND_IRQ_Common"
	);
}
void ND::IRQ::IRQ11()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli	\n"
	"pushl	$0x00\n"
	"pushl	$0x2A\n"
	"jmp ND_IRQ_Common"
	);
}
void ND::IRQ::IRQ12()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli	\n"
	"pushl	$0x00\n"
	"pushl	$0x2B\n"
	"jmp ND_IRQ_Common"
	);
}
void ND::IRQ::IRQ13()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli	\n"
	"pushl	$0x00\n"
	"pushl	$0x2C\n"
	"jmp ND_IRQ_Common"
	);
}
void ND::IRQ::IRQ14()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli	\n"
	"pushl	$0x00\n"
	"pushl	$0x2D\n"
	"jmp ND_IRQ_Common"
	);
}
void ND::IRQ::IRQ15()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli	\n"
	"pushl	$0x00\n"
	"pushl	$0x2E\n"
	"jmp ND_IRQ_Common"
	);
}
void ND::IRQ::IRQ16()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli	\n"
	"pushl	$0x00\n"
	"pushl	$0x2F\n"
	"jmp ND_IRQ_Common"
	);
}
}
