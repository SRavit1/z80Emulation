/*
Op code -> (function causes a change in the state of CPU)
Every op code has a unique name
*/
#include <string>

class z80CPU;

struct OpCode
{
    std::string mneumonic = "";
    uint8_t  (z80CPU::*operate) (void) = nullptr;
	uint8_t  (z80CPU::*addrmode)(void) = nullptr;
    uint8_t cycles = 0;
};