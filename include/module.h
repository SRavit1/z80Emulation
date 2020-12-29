#pragma once

#include "types.h"

class dataBus;

class module {
public:
	bool acceptsInput;
	bool sendsOutput;

	addressableRange ar;

	module(REG16 lower, REG16 upper, bool input, bool output);

	dataBus* m_bus;
	void assignBus(dataBus* bus);

	void executeCycle(); //goes through one clock cycle
};