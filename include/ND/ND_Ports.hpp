/**
 * @file ND_Ports.hpp
 * @brief Functions to input/output hardware ports
 * @author Adrián Arroyo Calle
 * */
#ifndef ND_PORTS_HPP
#define ND_PORTS_HPP

#include <ND_Types.hpp>

namespace ND{
	namespace Ports{
			uint8_t InputB(uint16_t _port);
			uint16_t InputW(uint16_t port);
			void OutputB(uint16_t port, uint8_t value); 
		}
	}
#endif
