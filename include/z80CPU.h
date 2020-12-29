#pragma once

#include <vector>

#include "types.h"
#include "dataBus.h"
#include "memory.h"
#include "OpCode.h"

//class dataBus;

class z80CPU {
public:
	//General Purpose Registers
	REG8 acc , A,  B,  D,  H,  F,  C,  E,  L ; // main set of registers
	REG8 acc_, A_, B_, D_, H_, F_, C_, E_, L_; // alternate set of registers
	FLAG8 FL, FL_; // Flag registers

	//Special Purpose Registers
	REG8 I, R; //interrupt vector, memory refresh
	REG16 IX, IY, SP, PC; //index registers, stack pointer, program counter

	enum iff {IFF_RESET, IFF_ENABLE};
	iff iff1, iff2; //Interrupt-enable flip flop; whether the CPU will accept an interrupt

	enum {MODE0, MODE1, MODE2} interrupt_status;

	dataBus* m_bus;

	z80CPU();
	void assignBus(dataBus* bus);
	
	void reset(); //reset
	void INT_(); //interrupt
	void NMI(); //non-maskable interrupt

	void executeCycle(); //goes through one clock cycle
private:
	int nCycles; //helper variable; number of cycles remaining for current instruction

	uint8_t fetched; //helper variable; store fetched instruction from memory

	bool nextInst; //helper variable; indicates whether program counter should be incremented at end of instruction
	uint8_t operand1, operand2; //helper variable; used to obtain operands of OpCodes

	std::vector <OpCode> lookUpTable; //helper variable; stores vector of OpCodes
	
	uint8_t memReadPC(); //reads memory at PC

	//Inline functions set and reset flags
	void SET_FLAG(FLAG a) { a = FLAG_SET; }
	void RESET_FLAG(FLAG a) { a = FLAG_RESET; }
	
	//NOP and IMP are dummy functions to be replaced with the instruction/address mode functions
	//ADDRESS MODE IMPLEMENTATIONS
	uint8_t IMP();  uint8_t IMM();  
	
	//INSTRUCTIONS IMPLEMENTATIONS (ALPHABETICAL)
	uint8_t NOP(); 
	uint8_t DJNZ(); uint8_t INCA(); uint8_t LDAN(); uint8_t LDBN(); 
};