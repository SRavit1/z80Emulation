#include "module.h"

module::module(REG16 lower, REG16 upper, bool input, bool output)
	: acceptsInput(input), sendsOutput(output)
{
	ar.lower = lower;
	ar.upper = upper;
}

void module::assignBus(dataBus* bus) {
	m_bus = bus;
}

void module::executeCycle() {
	
}