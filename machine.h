#pragma once

#include "z80CPU.h"
#include "memory.h"
#include "dataBus.h"

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

class machine {
public:
	z80CPU* m_cpu;
	memory* m_mem;
	dataBus* m_bus;

	machine(z80CPU* cpu, memory* mem, dataBus* bus);

	void tick(); //one clock cycle is completed
private:
};