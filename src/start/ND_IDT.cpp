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
	idt[num].always0=0;
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
	ND::IDT::SetGate(0,(unsigned)ND::ISR::ISR1,0x08,0x8E);
	ND::IDT::SetGate(1,(unsigned)ND::ISR::ISR2,0x08,0x8E);
	ND::IDT::SetGate(2,(unsigned)ND::ISR::ISR3,0x08,0x8E);
	ND::IDT::SetGate(3,(unsigned)ND::ISR::ISR4,0x08,0x8E);
	ND::IDT::SetGate(4,(unsigned)ND::ISR::ISR5,0x08,0x8E);
	ND::IDT::SetGate(5,(unsigned)ND::ISR::ISR6,0x08,0x8E);
	ND::IDT::SetGate(6,(unsigned)ND::ISR::ISR7,0x08,0x8E);
	ND::IDT::SetGate(7,(unsigned)ND::ISR::ISR8,0x08,0x8E);
	ND::IDT::SetGate(8,(unsigned)ND::ISR::ISR9,0x08,0x8E);
	ND::IDT::SetGate(9,(unsigned)ND::ISR::ISR10,0x08,0x8E);
	ND::IDT::SetGate(10,(unsigned)ND::ISR::ISR11,0x08,0x8E);
	ND::IDT::SetGate(11,(unsigned)ND::ISR::ISR12,0x08,0x8E);
	ND::IDT::SetGate(12,(unsigned)ND::ISR::ISR13,0x08,0x8E);
	ND::IDT::SetGate(13,(unsigned)ND::ISR::ISR14,0x08,0x8E);
	ND::IDT::SetGate(14,(unsigned)ND::ISR::ISR15,0x08,0x8E);
	ND::IDT::SetGate(15,(unsigned)ND::ISR::ISR16,0x08,0x8E);
	ND::IDT::SetGate(16,(unsigned)ND::ISR::ISR17,0x08,0x8E);
	ND::IDT::SetGate(17,(unsigned)ND::ISR::ISR18,0x08,0x8E);
	ND::IDT::SetGate(18,(unsigned)ND::ISR::ISR19,0x08,0x8E);
	ND::IDT::SetGate(19,(unsigned)ND::ISR::ISR20,0x08,0x8E);
	ND::IDT::SetGate(20,(unsigned)ND::ISR::ISR21,0x08,0x8E);
	ND::IDT::SetGate(21,(unsigned)ND::ISR::ISR22,0x08,0x8E);
	ND::IDT::SetGate(22,(unsigned)ND::ISR::ISR23,0x08,0x8E);
	ND::IDT::SetGate(23,(unsigned)ND::ISR::ISR24,0x08,0x8E);
	ND::IDT::SetGate(24,(unsigned)ND::ISR::ISR25,0x08,0x8E);
	ND::IDT::SetGate(25,(unsigned)ND::ISR::ISR26,0x08,0x8E);
	ND::IDT::SetGate(26,(unsigned)ND::ISR::ISR27,0x08,0x8E);
	ND::IDT::SetGate(27,(unsigned)ND::ISR::ISR28,0x08,0x8E);
	ND::IDT::SetGate(28,(unsigned)ND::ISR::ISR29,0x08,0x8E);
	ND::IDT::SetGate(29,(unsigned)ND::ISR::ISR30,0x08,0x8E);
	ND::IDT::SetGate(30,(unsigned)ND::ISR::ISR31,0x08,0x8E);
	ND::IDT::SetGate(31,(unsigned)ND::ISR::ISR32,0x08,0x8E);
	
	ND::IDT::Flush();
	
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString("done");
}
