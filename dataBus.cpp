#include "dataBus.h"

dataBus::dataBus() {
	
}

uint8_t dataBus::readData() {
	return data_lines;
}
void dataBus::writeData(uint8_t data) {
	data_lines = data;
}

uint16_t dataBus::readAddress() {
	return addr_lines;
}
void dataBus::writeAddress(uint16_t address) {
	addr_lines = address;
}

void dataBus::connectToBus(z80CPU* cpu) {
	m_cpu = cpu;
	m_cpu->assignBus(this);
}

void dataBus::connectToBus(memory* mem) {
	m_mem = mem;
	m_cpu->assignBus(this);
}

void dataBus::connectToBus(module* mod) {
	//TODO: Add to bus
	mod->assignBus(this);
}