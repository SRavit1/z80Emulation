#include <vector>
#include <iostream>
#include <iomanip>

void printMemory(std::vector<uint8_t> memory) {
	std::cout << "MEMORY" << std::endl;
	std::cout << std::hex << std::setw(2) << std::setfill('0');
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			std::cout << std::setw(2) << std::setfill('0');
			std::cout << static_cast<int>(memory[i*16 + j]) << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	std::vector<uint8_t> memory;
	for (int i = 0; i < 256; i++) {
		memory.push_back(i);
	}

	printMemory(memory);
}