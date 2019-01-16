CC = g++
out = bf
files = brainfuck.cpp \
		compiler/compilerLoad.cpp \
		compiler/compilerExec.cpp \
		compiler/compiler.hpp \
		compiler/predefFuncs.hpp \
		args/args.hpp \
		args/args.cpp \
		status/status.hpp \
		status/status.cpp \
		compiler/instructs/arithmetics.hpp \
		compiler/instructs/io.hpp \
		compiler/instructs/logic.hpp
all:
	@cls
	@echo kompilacja
	@${CC} ${files} -o ${out}.exe
run: all justRun
justRun:
	${out} main.b --int --ext