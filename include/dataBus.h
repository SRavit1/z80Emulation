#pragma once

#include "types.h"
#include "z80CPU.h"
#include "module.h"
#include "memory.h"

class z80CPU;
class memory;
class module;

class dataBus {
public:
	z80CPU* m_cpu;
	memory* m_mem;

	//vector of peripheral devices
	//vector <module*> devices;

	dataBus();

	void connectToBus(z80CPU* cpu);
	void connectToBus(memory* mem);
	void connectToBus(module* mod);
private:
	uint8_t  data_lines; //represent the data lines of the data bus
	uint16_t addr_lines; //represent the address lines of the data bus
};