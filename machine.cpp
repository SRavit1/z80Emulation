#include "machine.h"

machine::machine(z80CPU* cpu, memory* mem, dataBus* bus)
	: cpu(cpu), mem(mem), bus(bus) {
		bus->connectToBus(cpu);
		bus->connectToBus(mem);
}

void machine::tick() {

};