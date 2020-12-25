#pragma once

#ifndef REG_H
	#define REG_H
	#include <stdint.h>
	typedef uint8_t REG8;
	typedef uint16_t REG16;
	typedef struct range {
		REG16 lower;
		REG16 upper;
	} addressableRange;
	typedef struct {
		unsigned int C : 1;
		unsigned int N : 1;
		unsigned int P_V : 1;
		unsigned int X1 : 1;
		unsigned int H : 1;
		unsigned int X2 : 1;
		unsigned int Z : 1;
		unsigned int S : 1;
	} FLAG8;
#endif

class dataBus;

class module {
public:
	bool acceptsInput;
	bool sendsOutput;

	addressableRange ar;

	module(REG16 lower, REG16 upper, bool input, bool output);

	dataBus* bus;
	void assignBus(dataBus* bus);

	void executeCycle(); //goes through one clock cycle
};