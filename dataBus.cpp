#include "dataBus.h"

dataBus::dataBus() {
	
}

void dataBus::connectToBus(z80CPU* cpu) {
	this->cpu = cpu;
	cpu->assignBus(this);
}

void dataBus::connectToBus(memory* mem) {
	this->mem = mem;
	mem->assignBus(this);
}

void dataBus::connectToBus(module* mod) {
	//TODO: Add to bus
	mod->assignBus(this);
}