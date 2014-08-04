/**
 * @file ND_Timer.hpp
 * @author Adrián Arroyo Calle
 * @brief Timer x86 API
 * */
namespace ND{
	namespace Timer{
			void Setup();
			void Phase(unsigned int hz);
			void Wait(int ticks);
		}
}
extern "C"
void ND_Timer_Handler(struct regs* r);

