#include "memory.h"

memory::memory(REG16 lower, REG16 upper)
	: module(lower, upper, true, true) {
	m_memory.reserve(256*256);
}

bool memory::validLocation(uint8_t location) {
	return location >= ar.lower && location <= ar.upper;
}

void memory::write(uint8_t location, uint8_t data) {
	if (validLocation(location)) {
		m_memory[location] = data;
	}
}

uint8_t memory::read(uint8_t location) {
	if (validLocation(location)) {
		return  m_memory[location];
	}
}