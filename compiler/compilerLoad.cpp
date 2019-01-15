#include <iostream>
#include <string>
#include "compiler.hpp"

using namespace std;

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