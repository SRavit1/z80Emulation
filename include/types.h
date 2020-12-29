#pragma once

#ifndef REG_H
	#define REG_H
	#include <stdint.h>
	typedef uint8_t REG8;
	typedef uint16_t REG16;
	typedef struct range {
		uint16_t lower;
		uint16_t upper;
	} addressableRange;
	enum FLAG {FLAG_RESET, FLAG_SET};
	typedef struct {
		FLAG C;
		FLAG N;
		FLAG P_V;
		FLAG X1;
		FLAG H;
		FLAG X2;
		FLAG Z;
		FLAG S;
	} FLAG8;
#endif