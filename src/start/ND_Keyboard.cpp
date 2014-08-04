/**
 * @file ND_Keyboard.cpp
 * @author Adrián Arroyo Calle
 * @brief The keyboard handler
 * */

#include <ND_Keyboard.hpp>
#include <ND_Keymap.hpp>
#include <ND_Ports.hpp>
#include <ND_Screen.hpp>
#include <ND_IRQ.hpp>

#define MAX_STRING_SIZE 1024

unsigned int tmp;
char stringBuffer[MAX_STRING_SIZE];
unsigned int stringPos=0;

void ND::Keyboard::Setup()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND, ND_COLOR_BLACK);
	ND::Screen::PutString("\nSetup Keyboard...");

	ND_IRQ_InstallHandler(1,&ND_Keyboard_Handler);

	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString("done");
	tmp = 1;
}
void ND::Keyboard::wait()
{

}
char ND::Keyboard::GetChar()
{
	unsigned char scancode;
	scancode=(unsigned char)ND::Ports::InputB(0x60);
		
	if(scancode & ND_KEYBOARD_KEY_RELEASE)
	{
		return 0;
	}else{
		return en_US[scancode];
	}
}
char* ND::Keyboard::GetString()
{
	while(stringBuffer[stringPos-1]!='\n')
	{
		
	}
	stringPos=0;
	
	return stringBuffer;
}

extern "C"
void ND_Keyboard_Handler(struct regs* r)
{
    unsigned char scancode = ND::Keyboard::GetChar();
	ND::Screen::PutChar(scancode);
	stringBuffer[stringPos]=scancode;
	stringPos++;
}
