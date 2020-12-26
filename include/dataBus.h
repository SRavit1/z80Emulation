#pragma once

#include "z80CPU.h"
#include "module.h"
#include "memory.h"

#ifndef REG_H
	#define REG_H
	#include <stdint.h>
	typedef uint8_t REG8;
	typedef uint16_t REG16;
	typedef struct range {
		uint16_t lower;
		uint16_t upper;
	} addressableRange;
	typedef struct {
		unsigned int C : 1;
		unsigned int N : 1;
		unsigned int P_V : 1;
		unsigned int X1 : 1;
		unsigned int H : 1;
		unsigned int X2 : 1;
		unsigned int Z : 1;
		unsigned int S : 1;
	} FLAG8;
#endif

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

	uint8_t readData();
	void writeData(uint8_t data);

	uint16_t readAddress();
	void writeAddress(uint16_t address);

	void connectToBus(z80CPU* cpu);
	void connectToBus(memory* mem);
	void connectToBus(module* mod);
private:
	uint8_t  data_lines; //represent the data lines of the data bus
	uint16_t addr_lines; //represent the address lines of the data bus
};