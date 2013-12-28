/**
* @file ND_Screen.cpp
* @author Adrián Arroyo Calle
* @brief Implements four easy functions for write strings directly
*/
#include <ND_Types.hpp>
#include <ND_Color.hpp>
#include <ND_Screen.hpp>

uint16_t *vidmem= (uint16_t *)0xB8000;
ND_Color backColour = ND_COLOR_BLACK;
ND_Color foreColour = ND_COLOR_WHITE;
uint8_t cursor_x = 0;
uint8_t cursor_y = 0;

/**
 * @brief Gets the current color
 * @param side The side to get the color
 * */
ND_Color ND::Screen::GetColor(ND_SIDE side)
{
	if(side==ND_SIDE_BACKGROUND){
		return backColour;
	}else{
		return foreColour;
	}
}
/**
 * @brief Sets the color to a screen side
 * @param side The side to set colour
 * @param colour The new colour
 * @see GetColor
 * */
void ND::Screen::SetColor(ND_SIDE side, ND_Color colour)
{
	if(side==ND_SIDE_BACKGROUND)
	{
		backColour=colour;
	}else{
		foreColour=colour;
	}
}
/**
 * @brief Puts the char on screen
 * @param c The character to write
 * */
void ND::Screen::PutChar(char c)
{
	uint8_t  attributeByte = (backColour << 4) | (foreColour & 0x0F);
	uint16_t attribute = attributeByte << 8;
	uint16_t *location;
	if (c == 0x08 && cursor_x)
	{
		cursor_x--;
	}else if(c == '\r')
	{
		cursor_x=0;
	}else if(c == '\n')
	{
		cursor_x=0;
		cursor_y=1;
	}
	if(c >= ' ') /* Printable character */
	{
		location = vidmem + (cursor_y*80 + cursor_x);
		*location = c | attribute;
		cursor_x++;
	}
	if(cursor_x >= 80) /* New line, please*/
	{
		cursor_x = 0;
		cursor_y++;
	}
	/* Scroll if needed*/
	uint8_t attributeByte2 = (0 /*black*/ << 4) | (15 /*white*/ & 0x0F);
	uint16_t blank = 0x20 /* space */ | (attributeByte2 << 8);
	if(cursor_y >= 25)
	{
       int i;
       for (i = 0*80; i < 24*80; i++)
       {
           vidmem[i] = vidmem[i+80];
       }

       // The last line should now be blank. Do this by writing
       // 80 spaces to it.
       for (i = 24*80; i < 25*80; i++)
       {
           vidmem[i] = blank;
       }
       // The cursor should now be on the last line.
       cursor_y = 24;
   }
}
/**
 * @brief Puts a complete string to screen
 * @param str The string to write
 * */
void ND::Screen::PutString(const char* str)
{
	int i=0;
	while(str[i]) 
	{
		ND::Screen::PutChar(str[i++]);
	}
}
/**
 * @brief Cleans the screen with a color
 * @param colour The colour to fill the screen
 * */
 void ND::Screen::Clear(ND_Color colour)
{
   // Make an attribute byte for the default colours
   uint8_t attributeByte = (colour /*background*/ << 4) | (15 /*white - foreground*/ & 0x0F);
   uint16_t blank = 0x20 /* space */ | (attributeByte << 8);

   int i;
   for (i = 0; i < 80*25; i++)
   {
       vidmem[i] = blank;
   }

   // Move the hardware cursor back to the start.
   cursor_x = 0;
   cursor_y = 0;
}
/**
 * @brief Sets the cursor via software
 * @param x The position of X
 * @param y The position of y
 * */
void ND::Screen::SetCursor(uint8_t x, uint8_t y)
{
	cursor_x=x;
	cursor_y=y;
}

