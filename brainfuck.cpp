#include <iostream>
#include <fstream>
#include <string>
#include "compiler/compiler.hpp"
#include "args/args.hpp"

using namespace std;

int main(int argc, const char *argv[])
{
    string content, // brainfuck program
           now = "";
    argsInterpreter args(argc, argv);

    fstream f(args[0], ios::in);
    if(!f.good() || args[0][args[0].length()-1] != 'b')
    {
        cout << "Invalid path!";
        f.close();
        return EXIT_FAILURE;
    }
    now = "";
    while(f >> now)
    {
        content += now + ' ';
    }
    f.close();

    bf_compiler::brainfuck bf(args["dev"]=="true",
        args["int"]=="true",
        args["ext"]!="true");
    bf.load(content);
    bf.exec();
    return 0;
}