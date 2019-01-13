CC = g++
out = bf
files = brainfuck.cpp \
		compiler/compiler.cpp \
		compiler/compiler.hpp \
		args/args.hpp \
		args/args.cpp

all:
	${CC} ${files} -o ${out}.exe