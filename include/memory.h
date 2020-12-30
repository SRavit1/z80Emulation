#pragma once

#include <string>
#include <vector>

#include "types.h"
#include "module.h"

class memory : public module {
public:
	//Note: We assume that the entire addressable space is taken by memory
	std::vector<uint8_t> m_memory; //8 bits per row of memory, 8-bit addressable space

	memory(REG16 lower, REG16 upper);

	bool validLocation(uint16_t location); //indicates whether the specified address is valid location in memory

	int write(uint16_t location, uint8_t data); // writes data to location in memory
	int read(uint16_t location, uint8_t& result); //  reads from location in memory

	int write(uint16_t location, std::vector<uint8_t> data); // writes data to location in memory
	int read(uint16_t location, int bytes, std::vector<uint8_t>& result); //  reads from location in memory

	int write(uint16_t location, std::string data); // writes object code to memory
};