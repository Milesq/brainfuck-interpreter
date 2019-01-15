CC = g++
out = bf
files = brainfuck.cpp \
		compiler/compiler.cpp \
		compiler/compiler.hpp \
		args/args.hpp \
		args/args.cpp \
		status/status.hpp \
		status/status.cpp \
		compiler/instructs/arithmetics.hpp \
		compiler/instructs/io.hpp \
		compiler/instructs/logic.hpp

all:
	${CC} ${files} -o ${out}.exe