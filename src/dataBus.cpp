#include "dataBus.h"

dataBus::dataBus() {
	
}

void dataBus::connectToBus(z80CPU* cpu) {
	m_cpu = cpu;
}

void dataBus::connectToBus(memory* mem) {
	m_mem = mem;
}

void dataBus::connectToBus(module* mod) {
	//TODO: Add to bus
}