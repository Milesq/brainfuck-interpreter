#include <iostream>
#include <string>
#include <conio.h>
#include <map>
#include <stack>
#include "compiler.hpp"
#include "status.hpp"

using namespace std;

typedef void (*func)(status);

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

stack<int> bf_compiler::brainfuck::exec()
{
    // cout << "Funkcje: ";
    // for(auto i: this->declaredFunctions) { cout << i.first << endl << i.second << "\n\n"; }
    // cout << "Program: " << this->program;
    // return stack<int>();

    static string program = this->program;
    static stack<int> memoStack;
    static map<string, string> declaredFunctions = this->declaredFunctions;
    static int *memo = new int[this->size];

    for (int i=0;i>this->size;++i)
    {
        *memo = 0;
        ++memo;
    }
    memo -= this->size;

    map<char, func> instruct = {
        // {'(', [](int &wsk) -> void {
        //     string func = "";
        //     while(program[++wsk] != ')') func += program[wsk];
        //     if(declaredFunctions[func] == "") throw "Undeclared function " + func + "!";
        // }},
        // {':', [](int &wsk) -> void { memoStack.push(*memo); }},
        // {';', [](int &wsk) -> void {
        //     if(!memoStack.empty())
        //     {
        //         *memo = memoStack.top();
        //         memoStack.pop();
        //     } else *memo = 0;
        // }},
        // {'%', [](int &wsk) -> void {
        //     *memo %= (static_cast<int>(program[wsk+1]) - 48);
        //     ++wsk;
        // }},
        // {'*', [](int &wsk) -> void {
        //     *memo *= (static_cast<int>(program[wsk+1]) - 48);
        //     ++wsk;
        // }},
        // {'/', [](int &wsk) -> void {
        //     *memo /= (static_cast<int>(program[wsk+1]) - 48);
        //     ++wsk;
        // }},
        {'+', [](status st) -> void { ++(*st.memo); }},
        // {'+', [](int &wsk) -> void { ++(*memo); }},
        // {'-', [](int &wsk) -> void { --(*memo); }},
        // {'[', [](int &wsk) -> void {
        //     if(*memo == 0)
        //     {
        //         wsk = myStrFind(program, ']', '[', wsk + 1);
        //     }
        // }},
        // {']', [](int &wsk) -> void { wsk = myReversedStrFind(program, '[', ']', wsk - 1) - 1; }},
        // {'<', [](int &wsk) -> void { --memo; }},
        // {'>', [](int &wsk) -> void { ++memo; }},
        {'.', [](status st) -> void { cout << static_cast<char>(*st.memo); }},
        // {'.', [](int &wsk) -> void { cout << static_cast<char>(*memo); }},
        // {',', [](int &wsk) -> void { *memo = getch(); }}
    };

    if(this->integer)
        instruct['.'] = [](int &wsk) -> void { cout << static_cast<int>(*memo) << endl; };

    for(int i=0;i<program.size();++i)
    {
        status st(i, memo, memoStack, program);
        instruct[program[i]](st);
        if(this->dev)
        {
            cout << "\n----------\n" << *memo << " " << program[i] << "\n----------\n";
            if(getch() == 'q') throw -1;
        }
    }
    delete[] memo;
    return memoStack;
}