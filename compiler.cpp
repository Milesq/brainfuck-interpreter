#include <iostream>
#include "./compiler.hpp"

using namespace std;

inline void bf_compiler::brainfuck::load(string p)
{

    this->program = p;
}