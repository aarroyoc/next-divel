/**
 * @file NextShellLite.cpp
 * @author Adrian Arroyo Calle
 * @brief A Little shell for basic operations
 * NextShellLite is the first (and reduced) version of NextShell (planned). The main difference is that NextShellLite runs in kernel mode and it has built-in commands
 * */
#include <ND_Screen.hpp>
#include <ND_Keyboard.hpp>
#include "NextShellLite.hpp"
#include <ND_String.hpp>

char DIVISION_EXCEPTION[]={0x66,0xb8,0x00,0x00,
						0x66,0xbb,0x00,0x00,
						0x66,0xf7,0xfb};

void NextShell::Lite::Commands::Echo()
{
	char* str=ND::Keyboard::GetString();
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString(str);
}

void NextShell::Lite::Commands::Version()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString("\nNextDivel 0.1.0 - NextShellLite 0.1.0\n");
}
void NextShell::Lite::Commands::ForceException()
{
	void (*f)(void) = (void (*)(void)) DIVISION_EXCEPTION;
	f();
}
void NextShell::Lite::Commands::NotFound()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_RED);
	ND::Screen::PutString("\nCommand not found. Try again\n");
}
int NextShell::Lite::ExecuteString(char* script)
{
	if(ND::String::Compare("version\n",script)==0)
		NextShell::Lite::Commands::Version();
	else if(ND::String::Compare("force exception\n",script)==0)
		NextShell::Lite::Commands::ForceException();
	else if(ND::String::Compare("echo\n",script)==0)
		NextShell::Lite::Commands::Echo();
	else if(ND::String::Compare("clear\n",script)==0)
		ND::Screen::Clear();
	else
		NextShell::Lite::Commands::NotFound();
	NextShell::Lite::WaitForCommand();
}
int NextShell::Lite::WaitForCommand()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLACK);
	ND::Screen::PutString("NextShellLite:-> ");
	char* cmd=ND::Keyboard::GetString();
	//ND::Screen::PutString(cmd);
	NextShell::Lite::ExecuteString(cmd);
	
}
int NextShell::Lite::main()
{
	ND::Screen::Clear(ND_COLOR_WHITE);
	ND::Screen::SetColor(ND_SIDE_BACKGROUND,ND_COLOR_WHITE);
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLUE);
	ND::Screen::PutString("NextShellLite v0.1.0\n");
	
	NextShell::Lite::WaitForCommand();
}

