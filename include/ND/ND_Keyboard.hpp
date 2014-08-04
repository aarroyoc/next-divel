/**
 * @file ND_Keyboard.hpp
 * @author Adrián Arroyo Calle
 * @brief The keyboard handler
 * */
 #ifndef ND_KEYBOARD_HPP
 #define ND_KEYBOARD_HPP
 
 #define ND_KEYBOARD_KEY_RELEASE 0x80
 
 namespace ND{
		namespace Keyboard{
				void Setup();
				void wait();
				char GetChar();
			}
	 }
extern "C"
void ND_Keyboard_Handler(struct regs* r);
 #endif
