/**
 * @file ND_GDT.cpp
 * @author Adrián Arroyo Calle
 * @brief Creates GDT descriptions
 * */
 

#include <ND_GDT.hpp>
#include <ND_Screen.hpp>

struct ND::GDT::Entry gdt[3];
struct ND::GDT::Ptr gp;
	
static void gdt_flush()
{
	asm volatile("lgdt %0" :: "m" (gp));
	asm volatile(
		"movl $0x10, %eax \n"
		"movl %eax, %ds \n"
		"movl %eax, %es \n"
		"movl %eax, %fs \n"
		"movl %eax, %gs \n"
		"movl %eax, %ss \n"
	);
}
void ND::GDT::SetGate(int num, unsigned long base, unsigned long limit, unsigned char access,unsigned char gran)
{
	gdt[num].base_low=(base & 0xFFFF);
	gdt[num].base_middle=(base >> 16) & 0xFF;
	gdt[num].base_high=(base >> 24) & 0xFF;
	
	gdt[num].limit_low=(limit & 0xFFFF);
	gdt[num].granularity=(limit >> 16) & 0x0F;
	
	gdt[num].granularity |= (gran & 0xF0);
	gdt[num].access=access;
}
void ND::GDT::Install()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLACK);
	ND::Screen::PutString("Installing GDT...");

	gp.limit=(sizeof(struct ND::GDT::Entry)*3)-1;
	gp.base=(unsigned int)&gdt;
	
	ND::GDT::SetGate(0,0,0,0,0); /* NULL segmente entry */
	ND::GDT::SetGate(1,0,0xFFFFFFFF,0x9A,0xCF); /* 4 GiB for Code Segment */
	ND::GDT::SetGate(2,0,0xFFFFFFFF,0x92,0xCF); /* 4 GiB for Data segment */
	
	gdt_flush();
	
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString("done");
}
