#include <iostream>
#include <iomanip>

#include "z80CPU.h"

z80CPU::z80CPU() {
	//Preparing the lookup table
	using a = z80CPU;
	OpCode NOP_INST = { "NOP", &a::NOP, &a::IMP, 2 };
	lookUpTable = {
		//0									1								2								3								4								5								6								7								8								9								A								B								C								D								E								F
/*0*/	{"NOP", &a::NOP, &a::IMP, 2}	, NOP_INST						, NOP_INST						, NOP_INST						,{"INCB", &a::INCB, &a::IMP, 1} , 	{"DECB", &a::DECB, &a::IMP, 1}, {"LDBN", &a::LDBN, &a::IMM, 2}, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, {"INCC", &a::INCC, &a::IMP, 1}, {"DECC", &a::DECC, &a::IMP, 1}	, {"LDCN", &a::LDCN, &a::IMM, 2}, NOP_INST						,
/*1*/	{"DJNZ", &a::DJNZ, &a::IMM, 2}	, NOP_INST						, NOP_INST						, NOP_INST						,{"INCD", &a::INCD, &a::IMP, 1} , 	{"DECD", &a::DECD, &a::IMP, 1}, {"LDDN", &a::LDDN, &a::IMM, 2}, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, {"INCE", &a::INCE, &a::IMP, 1}, NOP_INST							, {"LDEN", &a::LDEN, &a::IMM, 2}, NOP_INST						,
/*2*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,{"INCH", &a::INCD, &a::IMP, 1} , 	{"DECH", &a::DECH, &a::IMP, 1}, {"LDHN", &a::LDHN, &a::IMM, 2}, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,{"DECHL", &a::DECHL, &a::IMP, 1}, {"INCL", &a::INCL, &a::IMP, 1}, {"DECL", &a::DECL, &a::IMP, 1}	, {"LDLN", &a::LDLN, &a::IMM, 2}, NOP_INST						,
/*3*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,{"INCHL", &a::INCHL, &a::IMP, 3},	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, {"INCA", &a::INCA, &a::IMP, 1}, {"DECA", &a::DECA, &a::IMP, 1}	, {"LDAN", &a::LDAN, &a::IMM, 2}, NOP_INST						,
/*4*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, 	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST							, NOP_INST						, NOP_INST						,
/*5*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, 	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST							, NOP_INST						, NOP_INST						,
/*6*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, 	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST							, NOP_INST						, NOP_INST						,
/*7*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, 	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST							, NOP_INST						, NOP_INST						,
/*8*/	{"ADDB", &a::ADDB, &a::IMP, 1}	, {"ADDC", &a::ADDC, &a::IMP, 1}, {"ADDD", &a::ADDD, &a::IMP, 1}, {"ADDE", &a::ADDE, &a::IMP, 1}	, {"ADDH", &a::ADDH, &a::IMP, 1}, 	{"ADDL", &a::ADDL, &a::IMP, 1}	, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST							, NOP_INST						, NOP_INST						,
/*9*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, 	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST							, NOP_INST						, NOP_INST						,
/*A*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, 	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST							, NOP_INST						, NOP_INST						,
/*B*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, 	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST							, NOP_INST						, NOP_INST						,
/*C*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, 	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST							, NOP_INST						, NOP_INST						,
/*D*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, 	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,{"xIXx", &a::xIXx, &a::IMM_EXT, 6}	, NOP_INST						, NOP_INST						,
/*E*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, 	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST							, NOP_INST						, NOP_INST						,
/*F*/	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, 	NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						, NOP_INST						,{"xIYx", &a::xIYx, &a::IMM_EXT, 6} , NOP_INST						, NOP_INST						
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

uint8_t z80CPU::IMM_EXT() {
	PC++;
	operand1 = memReadPC();
	PC++;
	operand2 = memReadPC();
}

//IMPLEMENTATION OF INSTRUCTION FUNCTIONS
uint8_t z80CPU::NOP() {

}

uint8_t z80CPU::ADDr(REG8& r) {
	//H is set if carry from bit 3; otherwise, it is reset.
	if ((acc & 0b00001111) + (r & 0b00001111) > 0x1111) { SET_FLAG(FL.H); } else { RESET_FLAG(FL.H); }
	//C is set if carry from bit 7; otherwise, it is reset.
	if ((acc & 0b11111111) + (r & 0b11111111) > 0x11111111) { SET_FLAG(FL.C); } else { RESET_FLAG(FL.C); }
	//P/V is set if overflow; otherwise, it is reset.
	if (static_cast<int>(acc)+static_cast<int>(r) != acc+r) { SET_FLAG(FL.P_V); } else { RESET_FLAG(FL.P_V); }

	acc += r;

	//S is set if result is negative; otherwise, it is reset.
	if (acc > 0x7F) { SET_FLAG(FL.S); } else { RESET_FLAG(FL.S); }
	//Z is set if result is 0; otherwise, it is reset.
	if (acc == 0x00) { SET_FLAG(FL.Z); } else { RESET_FLAG(FL.Z); }
}

uint8_t z80CPU::ADDB() {
	ADDr(B);
}

uint8_t z80CPU::ADDC() {
	ADDr(C);
}

uint8_t z80CPU::ADDD() {
	ADDr(D);
}

uint8_t z80CPU::ADDE() {
	ADDr(E);
}

uint8_t z80CPU::ADDH() {
	ADDr(H);
}

uint8_t z80CPU::ADDL() {
	ADDr(L);
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

uint8_t z80CPU::INCr(REG8& r) {
	//P/V is set if r was 7Fh before operation; otherwise, it is reset.
	if (r == 0x7F) { SET_FLAG(FL.P_V); } else { RESET_FLAG(FL.P_V); }
	
	r++;

	//S is set if result is negative; otherwise, it is reset.
	if (r > 0x7F) { SET_FLAG(FL.S); } else { RESET_FLAG(FL.S); }
	//Z is set if result is 0; otherwise, it is reset.
	if (r == 0x00) { SET_FLAG(FL.Z); } else { RESET_FLAG(FL.Z); }
	//H is set if carry from bit 3 (AKA if last 3 bits are now 0); otherwise, it is reset.
	if ((r & 0b00001111) == 0x0000) { SET_FLAG(FL.H); } else { RESET_FLAG(FL.H); }
}

uint8_t z80CPU::INCA() {
	return INCr(A);
}

uint8_t z80CPU::INCB() {
	return INCr(B);
}

uint8_t z80CPU::INCC() {
	return INCr(C);
}

uint8_t z80CPU::INCD() {
	return INCr(D);
}

uint8_t z80CPU::INCE() {
	return INCr(E);
}

uint8_t z80CPU::INCH() {
	return INCr(H);
}

uint8_t z80CPU::INCL() {
	return INCr(L);
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
	if (result < 0x7F) { SET_FLAG(FL.S); } else { RESET_FLAG(FL.S); }
	//Z is set if result is 0; otherwise, it is reset.
	if (result == 0x00) { SET_FLAG(FL.Z); } else { RESET_FLAG(FL.Z); }
	//H is set if carry from bit 3 (AKA if last 3 bits are now 0); otherwise, it is reset.
	if ((result & 0b00001111) == 0x0000) { SET_FLAG(FL.H); } else { RESET_FLAG(FL.H); }
	//N is reset
	RESET_FLAG(FL.N);
}

uint8_t z80CPU::DECr(REG8& r) {
	//P/V is set if r was 7Fh before operation; otherwise, it is reset.
	if (r == 0x80) { SET_FLAG(FL.P_V); } else { RESET_FLAG(FL.P_V); }
	
	r--;

	//S is set if result is negative; otherwise, it is reset.
	if (r > 0x7F) { SET_FLAG(FL.S); } else { RESET_FLAG(FL.S); }
	//Z is set if result is 0; otherwise, it is reset.
	if (r == 0x00) { SET_FLAG(FL.Z); } else { RESET_FLAG(FL.Z); }
	//H is set if borrow from bit 3 (AKA if last 3 bits are now 1); otherwise, it is reset.
	if ((r & 0b00001111) == 0x1111) { SET_FLAG(FL.H); } else { RESET_FLAG(FL.H); }
}

uint8_t z80CPU::DECA() {
	return DECr(A);
}

uint8_t z80CPU::DECB() {
	return DECr(B);
}

uint8_t z80CPU::DECC() {
	return DECr(C);
}

uint8_t z80CPU::DECD() {
	return DECr(D);
}

uint8_t z80CPU::DECE() {
	return DECr(E);
}

uint8_t z80CPU::DECH() {
	return DECr(H);
}

uint8_t z80CPU::DECL() {
	return DECr(L);
}

uint8_t z80CPU::DECHL() {
	uint16_t addr = L;
	addr = (addr*0x100)+H;

	uint8_t result = 0;
	m_bus->m_mem->read(addr, result);

	//P/V is set if r was 7Fh before operation; otherwise, it is reset.
	if (result == 0x7F) { SET_FLAG(FL.P_V); } else { RESET_FLAG(FL.P_V); }

	m_bus->m_mem->write(addr, --result);

	//S is set if result is negative; otherwise, it is reset.
	if (result < 0x7F) { SET_FLAG(FL.S); } else { RESET_FLAG(FL.S); }
	//Z is set if result is 0; otherwise, it is reset.
	if (result == 0x00) { SET_FLAG(FL.Z); } else { RESET_FLAG(FL.Z); }
	//H is set if carry from bit 3 (AKA if last 3 bits are now 0); otherwise, it is reset.
	if ((result & 0b00001111) == 0x0000) { SET_FLAG(FL.H); } else { RESET_FLAG(FL.H); }
	//N is reset
	RESET_FLAG(FL.N);
}

//Composite of distinct instructions (e.g. INC (IX + d))
uint8_t z80CPU::xIXx() {
	switch(operand1) {
		case 0x34: //INC (IX+d)
		{
			uint16_t addr = IX + operand2;
			
			uint8_t result = 0;
			m_bus->m_mem->read(addr, result);

			//P/V is set if r was 7Fh before operation; otherwise, it is reset.
			if (result == 0x7F) { SET_FLAG(FL.P_V); } else { RESET_FLAG(FL.P_V); }

			m_bus->m_mem->write(addr, ++result);

			//S is set if result is negative; otherwise, it is reset.
			if (result < 0x7F) { SET_FLAG(FL.S); } else { RESET_FLAG(FL.S); }
			//Z is set if result is 0; otherwise, it is reset.
			if (result == 0x00) { SET_FLAG(FL.Z); } else { RESET_FLAG(FL.Z); }
			//H is set if carry from bit 3 (AKA if last 3 bits are now 0); otherwise, it is reset.
			if ((result & 0b00001111) == 0x0000) { SET_FLAG(FL.H); } else { RESET_FLAG(FL.H); }
			//N is reset
			RESET_FLAG(FL.N);

			break;
		}
	}
}

uint8_t z80CPU::xIYx() {
	switch(operand1) {
		case 0x34: //INC (IX+d)
		{
			uint16_t addr = IX + operand2;
			
			uint8_t result = 0;
			m_bus->m_mem->read(addr, result);

			//P/V is set if r was 7Fh before operation; otherwise, it is reset.
			if (result == 0x7F) { SET_FLAG(FL.P_V); } else { RESET_FLAG(FL.P_V); }

			m_bus->m_mem->write(addr, ++result);

			//S is set if result is negative; otherwise, it is reset.
			if (result < 0x7F) { SET_FLAG(FL.S); } else { RESET_FLAG(FL.S); }
			//Z is set if result is 0; otherwise, it is reset.
			if (result == 0x00) { SET_FLAG(FL.Z); } else { RESET_FLAG(FL.Z); }
			//H is set if carry from bit 3 (AKA if last 3 bits are now 0); otherwise, it is reset.
			if ((result & 0b00000111) == 0x000) { SET_FLAG(FL.H); } else { RESET_FLAG(FL.H); }
			//N is reset
			RESET_FLAG(FL.N);

			break;
		}
	}
}
