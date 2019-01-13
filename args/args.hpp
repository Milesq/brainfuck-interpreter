#include <iostream>
#include <vector>
#include <map>
#include <string>

#ifndef ARGS_MANAGER
#define ARGS_MANAGER

using namespace std;

class argsInterpreter {
    vector<string> args;

    map<string, string> flags;
    vector<string> unnamed;
    public:
    static string parseArgs(int argc, const char *argv[]);
    void prepare(string);
    argsInterpreter(int argc, const char *argv[]);

    string operator[](string);
    string operator[](int);
};
#endif // ARGS_MANAGER