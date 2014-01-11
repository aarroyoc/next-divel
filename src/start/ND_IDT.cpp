/**
 * @file ND_IDT.cpp
 * @author Adrián Arroyo Calle
 * @brief Creates and intalls the IDT
 * */

#include <ND_IDT.hpp>
#include <ND_Screen.hpp>
#include <ND_Color.hpp>
#include <ND_Memory.hpp>

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
	
	ND::IDT::Flush();
	
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString("done");
}
