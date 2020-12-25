#include "machine.h"

int main() {
	z80CPU cpu;
	memory mem(0,0,0,0);
	dataBus bus;

	machine* myMachine = new machine(&cpu, &mem, &bus);
}