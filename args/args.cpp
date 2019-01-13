#include "args.hpp"
#include <vector>

void argsInterpreter::prepare(string args)
{
    string now = "";
    vector<string> argsV;
    args += ' ';

    while(args.size() > 0)
    {
        if(args[0] == ' ' && now != "") {
            argsV.push_back(now);
            now = "";
        } else now += args[0];
        args.erase(0, 1);
    }
    this->args = argsV;
}

argsInterpreter::argsInterpreter(int argc, const char *argv[])
{
    this->prepare(this->parseArgs(argc, argv));
    for(auto i: this->args)
    {
        if(i[0] == '-')
        {
            while(i[0] == '-') i.erase(0, 1);
            string name = "";
            while(i[0] != '=' && !i.empty())
            {
                name += i[0];
                i.erase(0, 1);
            }
            if(!i.empty()) i.erase(0, 1);
            if(i == "") i = "true";
            this->flags[name] = i;
        } else {
            this->unnamed.push_back(i);
        }
    }
}

string argsInterpreter::parseArgs(int argc, const char *argv[])
{
    string args = "";
    ++argv;
    for(unsigned short i = 1;i < argc;++i)
    {
        args += *argv;
        args += ' ';
        argv++;
    }
    args.pop_back();
    return args;
}

string argsInterpreter::operator[](string flagName)
{
    return this->flags[flagName];
}

string argsInterpreter::operator[](int argName)
{
    return this->unnamed[argName];
}