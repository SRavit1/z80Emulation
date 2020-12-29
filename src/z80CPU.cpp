#include <iostream>
#include <iomanip>

#include "z80CPU.h"

z80CPU::z80CPU() {
	//Preparing the lookup table
	using a = z80CPU;
	OpCode NOP_INST						 = { "???", &a::NOP, &a::IMP, 2 };
	lookUpTable = {
		//0									1								2								3								4								5								6								7								8								9								A								B								C								D								E								F
/*0*/	{"???", &a::NOP, &a::IMP, 2}	, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, {"LDBN", &a::LDBN, &a::IMM, 2}, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, {"INCC", &a::INCC, &a::IMP, 1}, NOP_INST						, {"LDCN", &a::LDCN, &a::IMM, 2}, NOP_INST						,
/*1*/	{"DJNZ", &a::DJNZ, &a::IMM, 2}	, NOP_INST						, NOP_INST						, NOP_INST						, {"INCD", &a::INCD, &a::IMP, 1}, NOP_INST						, {"LDDN", &a::LDDN, &a::IMM, 2}, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, {"LDEN", &a::LDEN, &a::IMM, 2}, NOP_INST						,
/*2*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, {"LDHN", &a::LDHN, &a::IMM, 2}, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, {"LDLN", &a::LDLN, &a::IMM, 2}, NOP_INST						,
/*3*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, {"INCA", &a::INCA, &a::IMP, 1}, NOP_INST						, {"LDAN", &a::LDAN, &a::IMM, 2}, NOP_INST						,
/*4*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
/*5*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
/*6*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
/*7*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
/*8*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
/*9*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
/*A*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
/*B*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
/*C*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
/*D*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
/*E*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,
/*F*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						
	};

	//setting number of cycles to 0
	nCycles = 0;

	//Resetting the CPU
	reset();
}

void z80CPU::assignBus(dataBus* bus) {
	m_bus = bus;
}

void z80CPU::reset() {
	//resetting Interrupt-enable Flip Flops (IFF)
	iff1 = IFF_RESET;
	iff2 = IFF_RESET;

	//clears the Program Counter and registers I and R
	PC = 0x0000;
	I = 0x00;
	R = 0x00;

	interrupt_status = MODE0;
}

void z80CPU::INT_() { //interrupt

}

void z80CPU::NMI() { //non-maskable interrupt

}

void z80CPU::executeCycle() {
	if (nCycles == 0) {
		//Op Code Fetch Cycle
		fetched = memReadPC();

		//Decoding the Op Code
		OpCode& inst = lookUpTable[fetched];
		//can be modified from within instruction if it depends on operands (e.g. DJNZ)
		nCycles = inst.cycles;
		nextInst = true; //set to false in operate() if jump group instruction

		//Instruction execution cycle
		//Note: As of now, the return value of these functions is not used
		(this->*(inst.addrmode))();
		(this->*(inst.operate))();

		//Increment program counter by default
		if (nextInst) PC++;
	}

	nCycles--;
}

uint8_t z80CPU::memReadPC() {
	return m_bus->m_mem->read(PC);
}

//IMPLEMENTATION OF ADDRESS MODES
uint8_t z80CPU::IMP() {

}

uint8_t z80CPU::IMM() {
	PC++;
	operand1 = memReadPC();
}

//IMPLEMENTATION OF INSTRUCTION FUNCTIONS
uint8_t z80CPU::NOP() {
	std::cout << "NOP instruction called" << std::endl;
}

uint8_t z80CPU::LDAN() {
	std::cout << "LDAN instruction called with " << 
		std::hex << std::uppercase << static_cast<int>(operand1) << std::endl;;
	A = operand1;
}

uint8_t z80CPU::LDBN() {
	std::cout << "LDBN instruction called with " << 
		std::hex << std::uppercase << static_cast<int>(operand1) << std::endl;;
	B = operand1;
}

uint8_t z80CPU::LDCN() {
	std::cout << "LDCN instruction called with " << 
		std::hex << std::uppercase << static_cast<int>(operand1) << std::endl;;
	C = operand1;
}

uint8_t z80CPU::LDDN() {
	std::cout << "LDDN instruction called with " << 
		std::hex << std::uppercase << static_cast<int>(operand1) << std::endl;;
	D = operand1;
}

uint8_t z80CPU::LDEN() {
	std::cout << "LDEN instruction called with " << 
		std::hex << std::uppercase << static_cast<int>(operand1) << std::endl;;
	E = operand1;
}

uint8_t z80CPU::LDHN() {
	std::cout << "LDHN instruction called with " << 
		std::hex << std::uppercase << static_cast<int>(operand1) << std::endl;;
	H = operand1;
}

uint8_t z80CPU::LDLN() {
	std::cout << "LDLN instruction called with " << 
		std::hex << std::uppercase << static_cast<int>(operand1) << std::endl;;
	L = operand1;
}

uint8_t z80CPU::INCA() {
	std::cout << "INCA instruction called" << std::endl;
	
	//P/V is set if r was 7Fh before operation; otherwise, it is reset.
	if (A == 0x7F) { SET_FLAG(FL.P_V); } else { RESET_FLAG(FL.P_V); }
	
	A++;
	
	//S is set if result is negative; otherwise, it is reset.
	if (A < 0x80) { SET_FLAG(FL.S); } else { RESET_FLAG(FL.S); }
	//Z is set if result is 0; otherwise, it is reset.
	if (A == 0x00) { SET_FLAG(FL.Z); } else { RESET_FLAG(FL.Z); }
	//H is set if carry from bit 3 (AKA if last 3 bits are now 0); otherwise, it is reset.
	if ((A & 0b00000111) == 0x000) { SET_FLAG(FL.H); } else { RESET_FLAG(FL.H); }
}

uint8_t z80CPU::INCC() {
	std::cout << "INCC instruction called" << std::endl;
	
	//P/V is set if r was 7Fh before operation; otherwise, it is reset.
	if (C == 0x7F) { SET_FLAG(FL.P_V); } else { RESET_FLAG(FL.P_V); }
	
	C++;
	
	//S is set if result is negative; otherwise, it is reset.
	if (C < 0x80) { SET_FLAG(FL.S); } else { RESET_FLAG(FL.S); }
	//Z is set if result is 0; otherwise, it is reset.
	if (C == 0x00) { SET_FLAG(FL.Z); } else { RESET_FLAG(FL.Z); }
	//H is set if carry from bit 3 (AKA if last 3 bits are now 0); otherwise, it is reset.
	if ((C & 0b00000111) == 0x000) { SET_FLAG(FL.H); } else { RESET_FLAG(FL.H); }
}

uint8_t z80CPU::INCD() {
	std::cout << "INCC instruction called" << std::endl;
	
	//P/V is set if r was 7Fh before operation; otherwise, it is reset.
	if (D == 0x7F) { SET_FLAG(FL.P_V); } else { RESET_FLAG(FL.P_V); }
	D++;
	
	//S is set if result is negative; otherwise, it is reset.
	if (D < 0x80) { SET_FLAG(FL.S); } else { RESET_FLAG(FL.S); }
	//Z is set if result is 0; otherwise, it is reset.
	if (D == 0x00) { SET_FLAG(FL.Z); } else { RESET_FLAG(FL.Z); }
	//H is set if carry from bit 3 (AKA if last 3 bits are now 0); otherwise, it is reset.
	if ((D & 0b00000111) == 0x000) { SET_FLAG(FL.H); } else { RESET_FLAG(FL.H); }
}


uint8_t z80CPU::DJNZ() {
	std::cout << "DJNZ instruction called with " << 
		std::hex << std::uppercase << static_cast<int>(operand1) << std::endl;

	B--;

	if (B != 0x00) {
		// program counter is incremented once more after this instruction in executeCycle()
		PC += (operand1);
		// if B is not 0, 3 cycles are taken rather than 2
		nCycles++;
	}
}