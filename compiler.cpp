#include <iostream>
#include "./compiler.hpp"

using namespace std;

void bf_compiler::brainfuck::load(string p)
{
    for(int i=0;i<p.size();i++)
    {
        if(string("-+[]<>,.").find(p[i]) != string::npos)
            this->program += p[i];
    }
}

void bf_compiler::brainfuck::exec()
{
    ;
}