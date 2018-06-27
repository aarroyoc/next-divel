/**
 * @file ND_Keymap.hpp
 * @author Adrián Arroyo Calle
 * @brief Keymaps for some keyboards
 * */
#ifndef ND_KEYMAP_HPP
#define ND_KEYMAP_HPP
unsigned char en_US[128]=
{
	0,27,'1','2','3','4','5','6','7','8','9','0','-','=', '\b',
	'\t','q','w','e','r','t','y','u','i','o','p','[',']','\n',
	'\n', /* Ctrl (It's used to activate the function keys)*/
	'a','s','d','f','g','h','j','k','l',';',
	'\'','`',0, /* Left Shift */
	'\\','z','x','c','v','b','n','m',',','.','/', 0,/* Right shift */
	'*', 0, /* Alt */
	' ',
	0, /* Caps lock*/
	'H',0,0,0,0,0,0,0,0,0, /* F1-F10 keys */
	0, /* Num lock */
	0, /* Scroll lock */
	0, /* Home key */
	0, /* Up arrow */
	0, /* Page up */
	'-',
	0, /* Left arrow */
	0,
	0, /* Right arrow */
	'+',
	0, /* End key */
	0, /* Down arrow */
	0, /* Page down */
	0, /* Insert key */
	0, /* Delete key */
	0,0,0,
	'R', 0, /* F11-F12 Keys */
	0
};


#endif
