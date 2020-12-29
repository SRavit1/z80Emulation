#pragma once

#include "types.h"
#include "z80CPU.h"
#include "memory.h"
#include "dataBus.h"

class machine {
public:
	z80CPU* m_cpu;
	memory* m_mem;
	dataBus* m_bus;

	machine(z80CPU* cpu, memory* mem, dataBus* bus);

	void tick(); //one clock cycle is completed
private:
};