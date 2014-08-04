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

unsigned int tmp;

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
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLACK);
	ND::Screen::PutString("\nEsperando que se oprima la tecla 'y': ");
	while (tmp){
	}
}
char ND::Keyboard::GetChar()
{
	unsigned char scancode;
//	while(1)
//	{
		scancode=(unsigned char)ND::Ports::InputB(0x60);
		
		if(scancode & ND_KEYBOARD_KEY_RELEASE)
		{
			return 0;
		}else{

			return en_US[scancode];
		}
//	}
}

extern "C"
void ND_Keyboard_Handler(struct regs* r)
{
    unsigned char scancode = ND::Keyboard::GetChar();
    if (scancode == 'y')
    	tmp = 0;
	ND::Screen::PutChar(scancode);
}
