#include "memory.h"

memory::memory(REG16 lower, REG16 upper, bool input, bool output)
	: module(lower, upper, input, output) {
	
}