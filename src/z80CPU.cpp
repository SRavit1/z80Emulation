#include <iostream>
#include <iomanip>

#include "z80CPU.h"

z80CPU::z80CPU() {
	//Preparing the lookup table
	using a = z80CPU;
	OpCode NOP_INST = { "NOP", &a::NOP, &a::IMP, 2 };
	lookUpTable = {
		//0									1								2								3								4								5								6								7								8								9								A								B								C								D								E								F
/*0*/	{"NOP", &a::NOP, &a::IMP, 2}	, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, {"LDBN", &a::LDBN, &a::IMM, 2}, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, {"INCC", &a::INCC, &a::IMP, 1}, NOP_INST						, {"LDCN", &a::LDCN, &a::IMM, 2}, NOP_INST						,
/*1*/	{"DJNZ", &a::DJNZ, &a::IMM, 2}	, NOP_INST						, NOP_INST						, NOP_INST						, {"INCD", &a::INCD, &a::IMP, 1}, NOP_INST						, {"LDDN", &a::LDDN, &a::IMM, 2}, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, {"LDEN", &a::LDEN, &a::IMM, 2}, NOP_INST						,
/*2*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, {"LDHN", &a::LDHN, &a::IMM, 2}, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, {"LDLN", &a::LDLN, &a::IMM, 2}, NOP_INST						,
/*3*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, {"INCHL", &a::INCHL, &a::IMP, 3}	, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, {"INCA", &a::INCA, &a::IMP, 1}, NOP_INST						, {"LDAN", &a::LDAN, &a::IMM, 2}, NOP_INST						,
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

	currInst = nullptr;
	//setting number of cycles to 0
	nCycles = 0;

	//Resetting the CPU
	reset();

	/*
	The idea here is to perform a half-cycle, where the instruction is fetched,
	but no instruction is executed before the fetch, nor is the program counter
	incremented.
	*/
	fetchDecode();
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

void z80CPU::fetchDecode() {
	//Op Code Fetch Cycle
	fetched = memReadPC();

	//Decoding the Op Code
	currInst = &lookUpTable[fetched];
	//can be modified from within instruction if it depends on operands (e.g. DJNZ)
	nCycles = currInst->cycles;
	nextInst = true; //set to false in operate() if jump group instruction

	//Instruction execution cycle
	//Note: As of now, the return value of these functions is not used
	(this->*(currInst->addrmode))();
}

void z80CPU::executeCycle() {
	if (nCycles == 0) {
		(this->*(currInst->operate))();

		//Increment program counter by default
		if (nextInst) PC++;

		//Fetching the next instruction so it can be displayed before the next cycle
		fetchDecode();
	}

	nCycles--;
}

uint8_t z80CPU::memReadPC() {
	uint8_t result = 0;
	m_bus->m_mem->read(PC, result);
	return result;
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

}

uint8_t z80CPU::LDAN() {
	A = operand1;
}

uint8_t z80CPU::LDBN() {
	B = operand1;
}

uint8_t z80CPU::LDCN() {
	C = operand1;
}

uint8_t z80CPU::LDDN() {
	D = operand1;
}

uint8_t z80CPU::LDEN() {
	E = operand1;
}

uint8_t z80CPU::LDHN() {
	H = operand1;
}

uint8_t z80CPU::LDLN() {
	L = operand1;
}

uint8_t z80CPU::INCA() {
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

uint8_t z80CPU::INCHL() {
	uint16_t addr = L;
	addr = (addr*0x100)+H;

	uint8_t result = 0;
	m_bus->m_mem->read(addr, result);

	//P/V is set if r was 7Fh before operation; otherwise, it is reset.
	if (result == 0x7F) { SET_FLAG(FL.P_V); } else { RESET_FLAG(FL.P_V); }

	m_bus->m_mem->write(addr, ++result);

	//S is set if result is negative; otherwise, it is reset.
	if (result < 0x80) { SET_FLAG(FL.S); } else { RESET_FLAG(FL.S); }
	//Z is set if result is 0; otherwise, it is reset.
	if (result == 0x00) { SET_FLAG(FL.Z); } else { RESET_FLAG(FL.Z); }
	//H is set if carry from bit 3 (AKA if last 3 bits are now 0); otherwise, it is reset.
	if ((result & 0b00000111) == 0x000) { SET_FLAG(FL.H); } else { RESET_FLAG(FL.H); }
	//N is reset
	RESET_FLAG(FL.N);
}

uint8_t z80CPU::DJNZ() {
	B--;

	if (B != 0x00) {
		// program counter is incremented once more after this instruction in executeCycle()
		PC += (int8_t) operand1;
		// if B is not 0, 3 cycles are taken rather than 2
		nCycles++;
	}
}