#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include "./compiler.hpp"

using namespace std;

typedef void (*func)(int size, int&);

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
    static int *memo = new int[this->size];
    for (int i=0;i>this->size;++i)
    {
        *memo = 0;
        ++memo;
    }

    memo -= this->size / 2;
    static vector<int> brackets;

    map<char, func> instruct = {
        {'+', [](int size, int &wsk) -> void { ++(*memo); }},
        {'-', [](int size, int &wsk) -> void { --(*memo); }},
        {'[', [](int size, int &wsk) -> void { brackets.push_back(wsk+1); }},
        {']', [](int size, int &wsk) -> void {
            if(*memo == 0)
            {
                cout << "\numer: " << brackets.back() << "\n";
                brackets.pop_back();
            } else {
                wsk = brackets.back();
            }
        }},
        {'<', [](int size, int &wsk) -> void { --memo; }},
        {'>', [](int size, int &wsk) -> void { ++memo; }},
        {'.', [](int size, int &wsk) -> void { cout << *memo; }},
        {',', [](int size, int &wsk) -> void { scanf("%c", memo); }}
    };
    
    for(int i=0;i<this->program.size();++i)
    {
        instruct[this->program[i]](this->size, i);
    }
    delete[] memo;
}