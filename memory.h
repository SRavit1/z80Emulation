#pragma once

#include "module.h"

#include <vector>

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

class memory : public module {
public:
	//Note: We assume that the entire addressable space is taken by memory
	std::vector<uint8_t> m_memory; //8 bits per row of memory, 8-bit addressable space

	memory(REG16 lower, REG16 upper);

	bool validLocation(uint8_t location); //indicates whether the specified address is valid location in memory

	void write(uint8_t location, uint8_t data); // writes data to location in memory
	uint8_t read(uint8_t location); //  reads from location in memory
};