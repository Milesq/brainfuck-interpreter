#include <iostream>
#include <string>
#include <map>
#include <stack>
#include "compiler.hpp"
#include "../status/status.hpp"
#include "./instructs/every.hpp"

using namespace std;

typedef void (*func)(status&);

stack<int> bf_compiler::brainfuck::exec(stack<int> memoStack)
{
    // cout << "Funkcje: ";
    // for(auto i: this->declaredFunctions) {
    //    cout << i.first << endl << i.second << "\n\n"; }

    // cout << "\nProgram: " << this->program;
    // return stack<int>();

    int *memo = new int[this->size];

    for (int i=0;i<this->size;++i)
    {
        *memo = 0;
        ++memo;
    }
    memo -= this->size / 2;

    map<char, func> instruct = {
        // {'(', instructs::funcBeg},
        {':', instructs::pushstack},
        {';', instructs::popstack},
        {'%', instructs::modulo},
        {'*', instructs::multiply},
        {'/', instructs::divide},
        {'+', instructs::add},
        {'-', instructs::sub},
        {'[', instructs::loopBeg},
        {']', instructs::loopEnd},
        {'<', instructs::left},
        {'>', instructs::right},
        {'.', instructs::out},
        {',', instructs::in}
    };

    for(int i=0;i<program.size();++i)
    {
        status st(i, memo, memoStack, this->program, this->integer);
        instruct[program[i]](st);
        if(this->dev)
        {
            cout << "\n----------\n" << *memo
                << " " << program[i] << "\n----------\n";
            if(getch() == 'q') throw -1;
        }
    }
    delete[] memo;
    return memoStack;
}