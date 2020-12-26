#pragma once

#ifndef REG_H
	#define REG_H
	#include <stdint.h>
	typedef uint8_t REG8;
	typedef uint16_t REG16;
	typedef struct range {
		uint16_t lower;
		uint16_t upper;
	} addressableRange;
	typedef struct {
		unsigned int C : 1;
		unsigned int N : 1;
		unsigned int P_V : 1;
		unsigned int X1 : 1;
		unsigned int H : 1;
		unsigned int X2 : 1;
		unsigned int Z : 1;
		unsigned int S : 1;
	} FLAG8;
#endif

class dataBus;

class z80CPU {
public:
	//General Purpose Registers
	REG8 acc , A,  B,  D,  H,  F,  C,  E,  L ; // main set of registers
	REG8 acc_, A_, B_, D_, H_, F_, C_, E_, L_; // alternate set of registers
	FLAG8 FL, FL_; // Flag registers

	//Special Purpose Registers
	REG8 I, R; //interrupt vector, memory refresh
	REG16 IX, IY, SP, PC; //index registers, stack pointer, program counter

	dataBus* m_bus;

	z80CPU();
	void assignBus(dataBus* bus);
	
	void reset(); //reset
	void INT_(); //interrupt
	void NMI(); //non-maskable interrupt

	void executeCycle(); //goes through one clock cycle
private:
	int nCycles; //number of cycles remaining for current instruction
};