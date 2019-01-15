#include <iostream>
#include <string>
#include <map>
#include <stack>
#include "compiler.hpp"
#include "../status/status.hpp"
#include "./instructs/every.hpp"

using namespace std;

typedef void (*func)(status&);

void bf_compiler::brainfuck::load(string p)
{
    string allowed = "-+[]<>,.";

    if(!this->normalBrainfuck)
        allowed += ":;";

    for(int i=0;i<p.size();i++)
    {
        if(!this->normalBrainfuck)
        {
            if(string("/*%").find(p[i]) != string::npos) // arytmetics
            {
                this->program += p[i];
                this->program += p[i+1];
                continue;
            }

            if(p[i] == '"') // functions
            {
                ++i;
                string funcName = "",
                funcBody = "";

                while(p[i] != '"') funcName += p[i++];
                while(p[i++] != '{');
                while(p[i] != '}') funcBody += p[i++];

                this->declaredFunctions[funcName] = funcBody;
                continue;
            }

            if(p[i] == '(')
            {
                this->program += '(';
                while(p[i++] != ')') this->program += p[i];
                continue;
            }
        }

        if(allowed.find(p[i]) != string::npos)
            this->program += p[i];
    }
}

stack<int> bf_compiler::brainfuck::exec(stack<int> memoStack)
{
    // cout << "Funkcje: ";
    // for(auto i: this->declaredFunctions) {
    //    cout << i.first << endl << i.second << "\n\n"; }
    // cout << "Program: " << this->program;
    // return stack<int>();

    int *memo = new int[this->size];

    for (int i=0;i<this->size;++i)
    {
        *memo = 0;
        ++memo;
    }
    memo -= this->size / 2;

    map<char, func> instruct = {
        // {'(', [](status &st) -> void {
        //     string func = "";
        //     while(program[++wsk] != ')') func += program[wsk];
        //     if(declaredFunctions[func] == "")
        //          throw "Undeclared function " + func + "!";
        // }},
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

    if(this->integer)
        instruct['.'] =
            [](status &st) -> void { cout << static_cast<int>(*st.memo) << endl; };

    for(int i=0;i<program.size();++i)
    {
        status st(i, memo, memoStack, this->program);
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