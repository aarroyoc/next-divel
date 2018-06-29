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
	ND::Screen::PutString("NextDivel 0.1.1 - NextShellLite 0.1.2\n");
}

void NextShell::Lite::Keys::Help()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString("\nNextDivel Help\n");
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLACK);
	ND::Screen::PutString("About the system:\n");
	ND::Screen::PutString("NextDivel is an experimental OS write in C, C++ and Assembler. It's currently being developed by the community.\n");
	ND::Screen::PutString("For more complete documentation, plese visit https://github.com/aarroyoc/next-divel/wiki\n");
}

void NextShell::Lite::Keys::Reboot()
{
	// It's not used (without ideas)
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
	{
		NextShell::Lite::Commands::Version();
	}else if(ND::String::Compare("clear\n",script)==0)
	{
		ND::Screen::Clear(ND_COLOR_WHITE);
	}else
	{
		if(ND::String::Compare("echo\n",script)==0)
		{
			NextShell::Lite::Commands::Echo();
		}else if(ND::String::Compare("H\n",script)==0)
		{
			NextShell::Lite::Keys::Help();
		}else
		{
			NextShell::Lite::Commands::NotFound();
		}
	
	}
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
	ND::Screen::Clear(ND_COLOR_BLACK);
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_WHITE);
	ND::Screen::PutString("Password: ");
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLACK);
	char* password=ND::Keyboard::GetString();
	if(ND::String::Compare("12345678\n",password)==0)
	{
	ND::Screen::Clear(ND_COLOR_WHITE);
	ND::Screen::SetColor(ND_SIDE_BACKGROUND,ND_COLOR_WHITE);
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLUE);
	ND::Screen::PutString("NextShellLite v0.1.0\n");
	NextShell::Lite::WaitForCommand();
	}
	else
	{
		ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_RED);
		ND::Screen::PutString("Incorrect password. Reboot the PC and try again.\n");
	}

}

