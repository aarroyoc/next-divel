/**
 * @file ND_Timer.cpp
 * @author Adrián Arroyo Calle
 * @brief Timer x86
 * */
 
#include <ND_Timer.hpp>
#include <ND_Ports.hpp>
#include <ND_Screen.hpp>
#include <ND_IDT.hpp>
#include <ND_ISR.hpp>
#include <ND_IRQ.hpp>

int ND_TIMER_TICKS=0;

void ND::Timer::Phase(int hz)
{
	int divisor=1193180/hz;
	ND::Ports::OutputB(0x43,0x36);
	ND::Ports::OutputB(0x40, divisor & 0xFF);
	ND::Ports::OutputB(0x40, divisor >> 8);
}
void ND::Timer::Wait(int ticks)
{
	unsigned long eticks;
	eticks=ND_TIMER_TICKS+ticks;
	while(ND_TIMER_TICKS < eticks)
	{
		
	}
}
void ND::Timer::Setup()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND, ND_COLOR_BLACK);
	ND::Screen::PutString("\nSetup timer...");
	
	ND_IRQ_InstallHandler(0,&ND_Timer_Handler);
	
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString("done");
}
extern "C"
void ND_Timer_Handler(struct regs* r)
{
	ND_TIMER_TICKS++;
	if(ND_TIMER_TICKS % 18 ==0)
	{
		ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BROWN);
		ND::Screen::PutString("\nOne more second");
	}else{
		ND::Screen::PutString("\nSomething strange");
	}
}
