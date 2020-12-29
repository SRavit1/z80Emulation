#pragma once

#include <vector>
#include <iostream>
#include <iomanip>

#include "types.h"

//TODO: Add to separate file display.h
//TODO: Add displays for CPU registers/flags
//TODO: Add display for disassembled instructions in memory

void printMemory(std::vector<uint8_t> memory) {
	std::cout << "MEMORY" << std::endl;
	std::cout << std::hex << std::uppercase;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			std::cout << std::setw(2) << std::setfill('0');
			std::cout << static_cast<int>(memory[i*16 + j]) << " ";
		}
		std::cout << std::endl;
	}
}
