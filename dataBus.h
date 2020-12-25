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
		REG16 lower;
		REG16 upper;
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
	z80CPU* cpu;
	memory* mem;

	//vector of peripheral devices
	//vector <module*> devices;

	dataBus();

	void connectToBus(z80CPU* cpu);
	void connectToBus(memory* mem);
	void connectToBus(module* mod);
};