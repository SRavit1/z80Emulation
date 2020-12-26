cmake_minimum_required (VERSION 2.8.11)
project (z80Emulation)

set (EXE a.exe)
set (SRC_DIR src)
set (INCLUDE_DIR include)

add_executable(${EXE} ${SRC_DIR}/emulate.cpp ${SRC_DIR}/z80CPU.cpp ${SRC_DIR}/dataBus.cpp ${SRC_DIR}/machine.cpp ${SRC_DIR}/module.cpp ${SRC_DIR}/memory.cpp)
target_include_directories (${EXE} PUBLIC ${INCLUDE_DIR})
