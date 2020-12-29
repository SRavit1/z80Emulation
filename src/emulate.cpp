#include <iostream>

#include "machine.h"

int main() {
	z80CPU cpu;
	memory mem(0x0000,0xFFFF);
	dataBus bus;

	machine* myMachine = new machine(&cpu, &mem, &bus);

	/*
	LD A, 0
	LD B, 3
	loop:
	INC A
	DNJZ loop
	*/

	//LD C, 3
	mem.write(0x0000, 0x0e); //LDCN Op Code
	mem.write(0x0001, 0x00); //Operand for above op code
	//LD B, 3
	mem.write(0x0002, 0x06); //LDBN Op Code
	mem.write(0x0003, 0x03); //Operand for above op code
	//INC C
	mem.write(0x0004, 0x0C); //INCC Op Code
	//DNJZ -2
	mem.write(0x0005, 0x10); //DJNZ Op Code
	mem.write(0x0006, 0xFD); //Operand for above op Code

	for (int i = 0; i < 25; i++) {
		myMachine->tick();
	}
}
