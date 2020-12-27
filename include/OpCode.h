/*
Op code -> (function causes a change in the state of CPU)
Every op code has a unique name
*/
#include <string>

struct OpCode
{
    std::string mneumonic = "";
    uint8_t  (*operate) (void) = nullptr;
	uint8_t  (*addrmode)(void) = nullptr;
    uint8_t cycles = 0;
}