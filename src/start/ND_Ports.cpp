/**
 * @file ND_Ports.cpp
 * @author Adrián Arroyo Calle
 * @brief Implements some hardware functions
 * */
#include <ND_Ports.hpp>
#include <ND_Types.hpp>

/**
 * @brief Gets the input 8 bits in the selected port
 * @param _port The port direction
 * @return The 8 bits data
 * */
uint8_t ND::Ports::InputB(uint16_t _port)
{
	unsigned char rv;
	asm volatile("inb %1, %0" : "=a"(rv) : "dN"(_port));
	return rv;
}
uint16_t ND::Ports::InputW(uint16_t port)
{
	uint16_t rv;
	asm volatile("inw %1, %0" : "=a"(rv) : "dN"(port));
}
/**
 * @brief Sets the output for the 8bit port in the selected port
 * @param port The port to set the value
 * @param value The value to set
 * */
void ND::Ports::OutputB(uint16_t port, uint8_t value)
{
	asm volatile("outb %1, %0" : : "dN"(port), "a"(value));
}
