/**
 * @file ND_IDT.cpp
 * @author Adrián Arroyo Calle
 * @brief Creates and intalls the IDT
 * */

#include <ND_IDT.hpp>
#include <ND_Screen.hpp>
#include <ND_Color.hpp>
#include <ND_Memory.hpp>
#include <ND_ISR.hpp>
#include <ND_IRQ.hpp>

struct ND::IDT::Entry idt[256];
struct ND::IDT::Ptr idtptr;

void ND::IDT::Flush()
{
	asm volatile("lidtl (idtptr)");
}
void ND::IDT::SetGate(uint8_t num,uint32_t base,uint16_t sel, uint8_t flags)
{
	idt[num].base_low=(base & 0xFFFF);
	idt[num].base_high=(base >> 16) & 0xFFFF;

	idt[num].sel=sel;
	idt[num].always0 = 0;
	idt[num].flags=flags;
}
void ND::IDT::Install()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLACK);
	ND::Screen::PutString("\nInstalling IDT...");

	idtptr.limit=(sizeof(struct ND::IDT::Entry)*256)-1;
	idtptr.base=(uint32_t)&idt;

	ND::Memory::Set(&idt,0,sizeof(struct ND::IDT::Entry)*256);

	/* Here it goes the ISR */

	ND::IDT::SetGate(0,(uint32_t)ND::ISR::ISR1,0x08,0x8E);
	ND::IDT::SetGate(1,(uint32_t)ND::ISR::ISR2,0x08,0x8E);
	ND::IDT::SetGate(2,(uint32_t)ND::ISR::ISR3,0x08,0x8E);
	ND::IDT::SetGate(3,(uint32_t)ND::ISR::ISR4,0x08,0x8E);
	ND::IDT::SetGate(4,(uint32_t)ND::ISR::ISR5,0x08,0x8E);
	ND::IDT::SetGate(5,(uint32_t)ND::ISR::ISR6,0x08,0x8E);
	ND::IDT::SetGate(6,(uint32_t)ND::ISR::ISR7,0x08,0x8E);
	ND::IDT::SetGate(7,(uint32_t)ND::ISR::ISR8,0x08,0x8E);
	ND::IDT::SetGate(8,(uint32_t)ND::ISR::ISR9,0x08,0x8E);
	ND::IDT::SetGate(9,(uint32_t)ND::ISR::ISR10,0x08,0x8E);
	ND::IDT::SetGate(10,(uint32_t)ND::ISR::ISR11,0x08,0x8E);
	ND::IDT::SetGate(11,(uint32_t)ND::ISR::ISR12,0x08,0x8E);
	ND::IDT::SetGate(12,(uint32_t)ND::ISR::ISR13,0x08,0x8E);
	ND::IDT::SetGate(13,(uint32_t)ND::ISR::ISR14,0x08,0x8E);
	ND::IDT::SetGate(14,(uint32_t)ND::ISR::ISR15,0x08,0x8E);
	ND::IDT::SetGate(15,(uint32_t)ND::ISR::ISR16,0x08,0x8E);
	ND::IDT::SetGate(16,(uint32_t)ND::ISR::ISR17,0x08,0x8E);
	ND::IDT::SetGate(17,(uint32_t)ND::ISR::ISR18,0x08,0x8E);
	ND::IDT::SetGate(18,(uint32_t)ND::ISR::ISR19,0x08,0x8E);
	ND::IDT::SetGate(19,(uint32_t)ND::ISR::ISR20,0x08,0x8E);
	ND::IDT::SetGate(20,(uint32_t)ND::ISR::ISR21,0x08,0x8E);
	ND::IDT::SetGate(21,(uint32_t)ND::ISR::ISR22,0x08,0x8E);
	ND::IDT::SetGate(22,(uint32_t)ND::ISR::ISR23,0x08,0x8E);
	ND::IDT::SetGate(23,(uint32_t)ND::ISR::ISR24,0x08,0x8E);
	ND::IDT::SetGate(24,(uint32_t)ND::ISR::ISR25,0x08,0x8E);
	ND::IDT::SetGate(25,(uint32_t)ND::ISR::ISR26,0x08,0x8E);
	ND::IDT::SetGate(26,(uint32_t)ND::ISR::ISR27,0x08,0x8E);
	ND::IDT::SetGate(27,(uint32_t)ND::ISR::ISR28,0x08,0x8E);
	ND::IDT::SetGate(28,(uint32_t)ND::ISR::ISR29,0x08,0x8E);
	ND::IDT::SetGate(29,(uint32_t)ND::ISR::ISR30,0x08,0x8E);
	ND::IDT::SetGate(30,(uint32_t)ND::ISR::ISR31,0x08,0x8E);
	ND::IDT::SetGate(31,(uint32_t)ND::ISR::ISR32,0x08,0x8E);

	ND::IDT::Flush();
//	asm volatile ("sti");

	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString("done");
}
