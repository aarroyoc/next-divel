/**
 * @file ND_Keyboard.cpp
 * @author Adrián Arroyo Calle
 * @brief The keyboard handler
 * */

#include <ND_Keyboard.hpp>
#include <ND_Keymap.hpp>
#include <ND_Ports.hpp>
#include <ND_Screen.hpp>

char ND::Keyboard::GetChar()
{
	unsigned char scancode;
//	while(1)
//	{
		scancode=(unsigned char)ND::Ports::InputB(0x60);
		
		if(scancode & ND_KEYBOARD_KEY_RELEASE)
		{
			/*return en_US[scancode];*/
		}else{

			return en_US[scancode];
		}
//	}
	return 'N';
}
