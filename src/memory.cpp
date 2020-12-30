#include <iostream>
#include <sstream>

#include "memory.h"

memory::memory(REG16 lower, REG16 upper)
	: module(lower, upper, true, true) {
	for (int i = 0; i < (256*256); i++) {
		m_memory.push_back(0);
	}
}

bool memory::validLocation(uint16_t location) {
	return location >= ar.lower && location <= ar.upper;
}

int memory::write(uint16_t location, uint8_t data) {
	if (!validLocation(location)) {
		return 1;
	}
	
	m_memory[location] = data;
	return 0;
}

int memory::read(uint16_t location, uint8_t& result) {
	if (!validLocation(location)) {
		return 1;
	}
	uint8_t value = m_memory[location]; //copying the value
	result = value;
	return 0;
}

int memory::write(uint16_t location, std::vector<uint8_t> data) {
	for (int i = 0; i < data.size(); i++) {
		if (!validLocation(location+i)) return 1;
	}
	for (int i = 0; i < data.size(); i++) {
		m_memory[location+i] = data[i];
	}
	return 0;
}

int memory::read(uint16_t location, int bytes, std::vector<uint8_t>& result) {
	for (int i = 0; i < bytes; i++) {
		if (!validLocation(location+i)) return 1;
	}
	result.clear();
	for (int i = 0; i < bytes; i++) {
		uint8_t value = m_memory[location+i];
		result.push_back(value);
	}
	return 0;
}

int memory::write(uint16_t location, std::string data) {
	std::vector<uint8_t> vecData;
	for (int i = 0; i+2 <= data.size(); i += 3) {
		uint8_t currByte;

		int tempVal;
		std::stringstream ss;
		std::string subVal = data.substr(i, 2);
		ss << std::hex << subVal;
		ss >> tempVal;

		currByte = tempVal;

		vecData.push_back(currByte);
	}

	write(location, vecData);
}