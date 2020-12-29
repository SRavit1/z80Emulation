#include "machine.h"

machine::machine(z80CPU* cpu, memory* mem, dataBus* bus)
	: m_cpu(cpu), m_mem(mem), m_bus(bus) {
		bus->connectToBus(m_cpu);
		m_cpu->assignBus(bus);

		bus->connectToBus(m_mem);
		m_mem->assignBus(bus);
}

void machine::tick() {
	m_cpu->executeCycle();
};