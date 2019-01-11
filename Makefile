CC = g++
out = bf
files = brainfuck.cpp \
		compiler.cpp \
		compiler.hpp

all:
	${CC} ${files} -o ${out}.exe