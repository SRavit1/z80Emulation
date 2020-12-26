#include "machine.h"

machine::machine(z80CPU* cpu, memory* mem, dataBus* bus)
	: m_cpu(cpu), m_mem(mem), m_bus(bus) {
		bus->connectToBus(m_cpu);
		bus->connectToBus(m_mem);
}

void machine::tick() {

};