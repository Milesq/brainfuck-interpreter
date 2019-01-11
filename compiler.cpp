#include <iostream>
#include <stdio.h>
#include <map>
#include "./compiler.hpp"

using namespace std;

typedef void (*func)(int*, int size);

void operator<<(ostream &out, string x) {out << x.c_str();}

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
    map<char, func> instruct = {
        {'+', [](int *memo, int size) -> void { ++(*memo); }},
        {'-', [](int *memo, int size) -> void { --(*memo); }},
        // {'[', [](int *memo, int size) -> void { --*memo; }},
        // {']', [](int *memo, int size) -> void { --*memo; }},
        // {'<', [](int *memo, int size) -> void { --memo; }},
        // {'>', [](int *memo, int size) -> void { ++memo; }},
        // {'.', [](int *memo, int size) -> void { cout << static_cast<char>(*memo); }},
        // {',', [](int *memo, int size) -> void { scanf("%c", &(*memo)); }}
    };

    for(char i: this->program)
    {
        instruct[i](this->memo, this->size);
    }
}