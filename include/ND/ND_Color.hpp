/**
* @file ND_Color.hpp
* @author Adrián Arroyo Calle
* @brief Defines the ND_Color struct
* The ND_Color struct defines 16 colors for VGA graphics cards
*/
#ifndef ND_COLOR_HPP
#define ND_COLOR_HPP

typedef enum ND_Color{ 
	ND_COLOR_BLACK			= 0,
	ND_COLOR_BLUE			= 1,
	ND_COLOR_GREEN			= 2,
	ND_COLOR_CYAN			= 3,
	ND_COLOR_RED			= 4,
	ND_COLOR_MAGENTA		= 5,
	ND_COLOR_BROWN			= 6,
	ND_COLOR_LIGHT_GREY		= 7,
	ND_COLOR_DARK_GREY		= 8,
	ND_COLOR_LIGHT_BLUE		= 9,
	ND_COLOR_LIGHT_GREEN	= 10,
	ND_COLOR_LIGHT_CYAN		= 11,
	ND_COLOR_LIGHT_RED		= 12,
	ND_COLOR_LIGHT_MAGENTA	= 13,
	ND_COLOR_LIGHT_BROWN	= 14,
	ND_COLOR_WHITE			= 15

} ND_Color;
#endif
