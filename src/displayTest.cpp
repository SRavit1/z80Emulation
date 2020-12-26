#include <vector>

#include "display.h"

int main() {
	std::vector<uint8_t> memory;
	for (int i = 0; i < 256; i++) {
		memory.push_back(i);
	}

	printMemory(memory);
}