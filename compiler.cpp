#include <iostream>
#include <conio.h>
#include <map>
#include <stack>
#include "./compiler.hpp"

using namespace std;

typedef void (*func)(int size, int&);

int myStrFind(string str, char what, char neg, int n=0)
{
    int counter = 0;
    for(;n<str.length();++n)
    {
        if(str[n] == what) {
            if(counter == 0)
                return n;
            else counter--;
        } else if(str[n] == neg) counter++;
    }
    return -1;
}

int myReversedStrFind(string str, char what, char neg, int n=-1)
{
    n = (n == -1)? str.size() - 1 : n;
    int counter = 0;
    for(;n<str.length();--n)
    {
        if(str[n] == what)
        {
            if(counter==0)
                return n;
            else counter--;
        } else if(str[n] == neg) counter++;
    }
    return -1;
}

void bf_compiler::brainfuck::load(string p)
{
    string allowed = "-+[]<>,.";
    if(!this->normalBrainfuck)
        allowed += ":;";
    for(int i=0;i<p.size();i++)
    {
        if(allowed.find(p[i]) != string::npos)
            this->program += p[i];
    }
}

void bf_compiler::brainfuck::exec()
{
    static string program = this->program;
    static stack<int> memoStack;
    static int *memo = new int[this->size];
    for (int i=0;i>this->size;++i)
    {
        *memo = 0;
        ++memo;
    }
    memo -= this->size;

    map<char, func> instruct = {
        {';', [](int size, int &wsk) -> void {
            memoStack.push(*memo);
        }},
        {':', [](int size, int &wsk) -> void {
            if(!memoStack.empty())
            {
                *memo = memoStack.top();
                memoStack.pop();
            } else *memo = 0;
        }},
        {'+', [](int size, int &wsk) -> void { ++(*memo); }},
        {'-', [](int size, int &wsk) -> void { --(*memo); }},
        {'[', [](int size, int &wsk) -> void {
            if(*memo == 0)
            {
                wsk = myStrFind(program, ']', '[', wsk + 1);
            }
        }},
        {']', [](int size, int &wsk) -> void {
            wsk = myReversedStrFind(program, '[', ']', wsk - 1) - 1;
        }},
        {'<', [](int size, int &wsk) -> void { --memo; }},
        {'>', [](int size, int &wsk) -> void { ++memo; }},
        {'.', [](int size, int &wsk) -> void { cout << static_cast<char>(*memo); }},
        {',', [](int size, int &wsk) -> void { *memo = getch(); }}
    };

    if(this->integer)
        instruct['.'] = [](int size, int &wsk) -> void { cout << static_cast<int>(*memo) << endl; };

    for(int i=0;i<program.size();++i)
    {
        instruct[program[i]](this->size, i);
        if(this->dev)
        {
            cout << "\n----------\n" << *memo << " " << program[i] << "\n----------\n";
            if(getch() == 'q') throw -1;
        }
    }
    delete[] memo;
}