all:
	g++ emulate.cpp z80CPU.cpp dataBus.cpp machine.cpp module.cpp memory.cpp

clean:
	rm a.out
