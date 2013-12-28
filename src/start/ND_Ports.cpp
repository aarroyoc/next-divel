/**
 * @file ND_Ports.cpp
 * @author Adrián Arroyo Calle
 * @brief Implements some hardware functions
 * */
#include <ND_Ports.hpp>

unsigned char ND::Ports::InputB(unsigned short _port)
{
	unsigned char rv;
	asm volatile("inb %1, %0" : "=a"(rv) : "dN"(_port));
	return rv;
}
