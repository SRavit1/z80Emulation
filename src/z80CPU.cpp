#include "z80CPU.h"

z80CPU::z80CPU() {
	using a = z80CPU;

	OpCode NOP_INST						 = { "???", &a::NOP, &a::IMP, 2 };
	
	lookUpTable = {
		//0									1								2								3								4								5								6								7								8								9								10								11								12								13								14								15
		 { "???", &a::NOP, &a::IMP, 2 } , NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
		NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
		NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
		NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
		NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
		NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
		NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
		NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
		NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
		NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
		NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
		NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
		NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
		NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
		NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
		NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						
	};
}

void z80CPU::assignBus(dataBus* bus) {
	m_bus = bus;
}

void z80CPU::reset() {

}

void z80CPU::INT_() { //interrupt

}

void z80CPU::NMI() { //non-maskable interrupt

}

void z80CPU::executeCycle() {

}

//IMPLEMENTATION OF ADDRESS MODES
uint8_t z80CPU::IMP() {

}

//IMPLEMENTATION OF INSTRUCTION FUNCTIONS
uint8_t z80CPU::NOP() {

}