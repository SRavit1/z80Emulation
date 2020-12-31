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

	enum REG8_vals {_acc , _A,  _B,  _D,  _H,  _F,  _C,  _E,  _L, 
					_acc_, _A_, _B_, _D_, _H_, _F_, _C_, _E_, _L_,
					_I, _R};
	enum REG16_vals {_IX, _IY, _SP, _PC};
	enum FLAG8_vals {_FL, _FL_};

	enum iff {IFF_RESET, IFF_ENABLE};
	iff iff1, iff2; //Interrupt-enable flip flop; whether the CPU will accept an interrupt

	enum {MODE0, MODE1, MODE2} interrupt_status;

	dataBus* m_bus;

	z80CPU();
	void assignBus(dataBus* bus);
	
	void reset(); //reset
	void INT_(); //interrupt
	void NMI(); //non-maskable interrupt

	void fetchDecode(); //fetches opcode and loads operands
	void executeCycle(); //goes through one clock cycle

	//TODO: Implement these functions and make all registers/flags private
	//TODO: If PC is changed, be sure to call fetchDecode
	REG8  access(REG8_vals);
	REG16 access(REG16_vals);
	FLAG8 access(FLAG8_vals);

	void change (REG8_vals, REG8&);
	void change (REG16_vals, REG16&);
	void change (FLAG8_vals, FLAG8&);

	OpCode* currInst; //helper variable; stores a reference to the current instruction
	uint8_t operand1, operand2; //helper variable; used to obtain operands of OpCodes

	int nCycles; //helper variable; number of cycles remaining for current instruction
private:
	uint8_t fetched; //helper variable; store fetched instruction from memory

	bool nextInst; //helper variable; indicates whether program counter should be incremented at end of instruction

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
	
	uint8_t DJNZ(); uint8_t INCA(); uint8_t INCB(); uint8_t INCC(); uint8_t INCD(); uint8_t INCH();
	uint8_t INCHL();
	uint8_t LDAN(); uint8_t LDBN(); uint8_t LDCN();  uint8_t LDDN(); 
	uint8_t LDEN(); uint8_t LDHN(); uint8_t LDLN();
};