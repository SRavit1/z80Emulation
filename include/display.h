#pragma once

#include <vector>
#include <iostream>
#include <iomanip>

#include "types.h"
#include "machine.h"

//TODO: Add display for disassembled instructions in memory

void clearScreen() {
	static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
	std::cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << std::flush;
}

void newLine() {
	std::cout << std::endl;
}

void obtainCommand() {
	char command;
	std::cout << "(n/q): ";
	std::cin >> command;
	if (command == 'q') {
		exit(0);
	}
}

void printInstruction(z80CPU& cpu) {
	if (cpu.currInst) {
		std::cout 
		<< "Instruction 0x" << std::setw(4) << std::setfill('0') << std::hex << std::uppercase 
		<< static_cast<int>(cpu.PC) << ": "
		<< std::setw(4) << std::setfill(' ') << cpu.currInst->mneumonic << " " 
		<< std::setw(2) << static_cast<int>(cpu.operand1) << " " 
		<< std::setw(2) << static_cast<int>(cpu.operand2) << std::dec << std::endl;
	} else {
		std::cout << "START" << std::endl;
	}
}

void printMemory(std::vector<uint8_t> memory, int start, int bytes) {
	std::cout << "MEMORY\n======" << std::endl;
	std::cout << std::hex << std::uppercase << std::setfill('0');
	for (int i = 0; i < (bytes/16)+1; i++) {
		std::cout << "0x" << std::setw(4) << start+i*16 << ": ";
		for (int j = 0; j < 16; j++) {
			std::cout << std::setw(2) << std::setfill('0') << static_cast<int>(memory[start + i*16 + j]) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::dec << std::nouppercase;
}

void printReg8(std::string name, REG8& reg) {
	std::cout << std::setw(4) << std::setfill(' ') << name << ": 0x" << std::setw(2) << std::setfill('0') << 
	static_cast<int>(reg) << "    ";
}

void printReg16(std::string name, REG16& reg) {
	std::cout << std::setw(2) << std::setfill(' ') << name << ": 0x" << std::setw(4) << std::setfill('0') << 
	static_cast<int>(reg) << "    ";
}

void printFlag(std::string name, FLAG& f) {
	std::string value = (f == FLAG_SET) ? "1" : "0";
	std::cout << name << " " << value << "\t";
}

void printFlag8(std::string name, FLAG8& flag) {
	std::cout << std::setw(3) << std::setfill(' ') << name << "\t";

	printFlag("C", flag.C);
	printFlag("N", flag.N);
	printFlag("P_V", flag.P_V);
	printFlag("H", flag.H);
	printFlag("Z", flag.Z);
	printFlag("S", flag.S);
	std::cout << std::endl;
}

void printCPU(z80CPU& cpu) {
	std::cout << "CPU\n======" << std::endl;

	std::cout << std::hex << std::uppercase << std::setw(2) << std::setfill('0');
	printReg8("A", cpu.A);
	printReg8("B", cpu.B);
	printReg8("D", cpu.D);
	printReg8("H", cpu.H);
	newLine();
	printReg8("F", cpu.F);
	printReg8("C", cpu.C);
	printReg8("E", cpu.E);
	printReg8("L", cpu.L);
	newLine();
	printReg8("A_", cpu.A_);
	printReg8("B_", cpu.B_);
	printReg8("D_", cpu.D_);
	printReg8("H_", cpu.H_);
	newLine();
	printReg8("F_", cpu.F_);
	printReg8("C_", cpu.C_);
	printReg8("E_", cpu.E_);
	printReg8("L_", cpu.L_);
	newLine();
	printReg8("I", cpu.I);
	printReg8("R", cpu.R);
	printReg8("acc", cpu.acc);
	printReg8("acc_", cpu.acc_);
	newLine();
	printReg16("IX", cpu.IX);
	printReg16("IY", cpu.IY);
	printReg16("SP", cpu.SP);
	printReg16("PC", cpu.PC);
	newLine();
	newLine();
	printFlag8("FL", cpu.FL);
	printFlag8("FL_", cpu.FL_);
}

void printState(z80CPU& cpu, memory& mem) {
	clearScreen();
	printInstruction(cpu);
	newLine();
	printCPU(cpu);
	newLine();
	printMemory(mem.m_memory, (cpu.PC/0x0010)*0x0010, 64);
	newLine();
}