/**
* @file ND_Panic.cpp
* @author Adrián Arroyo Calle
* @brief Implements the Panic Screen for NextDivel
*/
#include <ND_Panic.hpp>
#include <ND_Screen.hpp>

/**
 * @brief Shows a Kernel Panic screen with the selected error message
 * @param error A string containing the name of the error
 * */
void ND::Panic::Show(const char* error)
{
	ND::Screen::Clear(ND_COLOR_RED);
	ND::Screen::SetColor(ND_SIDE_BACKGROUND, ND_COLOR_WHITE);
	ND::Screen::SetColor(ND_SIDE_FOREGROUND, ND_COLOR_RED);
	ND::Screen::SetCursor(29,10); //(80-22)/2
	ND::Screen::PutString("NextDivel Kernel Error\n");
	ND::Screen::SetCursor(15,12);
	ND::Screen::PutString(error);
}
