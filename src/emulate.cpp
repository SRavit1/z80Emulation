#include <iostream>

#include "machine.h"
#include "display.h"

int main() {
	z80CPU cpu;
	memory mem(0x0000,0xFFFF);
	dataBus bus;

	machine* myMachine = new machine(&cpu, &mem, &bus);

	/*
	LD C, 0
	LD B, 3
	loop:
	INC C
	DNJZ loop
	*/

	/*
	0E LDCN Op Code
	00 Operand for above op code
	06 LDBN Op Code
	03 Operand for above op code
	0C INCC Op Code
	10 DJNZ Op Code
	FD Operand for above op Code
	*/

	REG16 loc = 0x0010;
	mem.write(loc, "0E 00 06 03 0C 10 FD");

	//TODO: Substitute both statements with cpu.change
	//(PC would be incremented automatically)
	cpu.PC = loc;
	cpu.fetchDecode();

	for (int i = 1; ; i++) {
		myMachine->tick();
		if (cpu.nCycles == 0) { //current instruction is executing
			printState(cpu, mem);
			obtainCommand();
		}
	}
}
