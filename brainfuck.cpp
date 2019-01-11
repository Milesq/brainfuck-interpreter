#include <iostream>
#include <fstream>
#include "compiler.hpp"

using namespace std;

string parseArgs(int argc, const char *argv[])
{
	string args = "";
	++argv;
	for(unsigned short i = 1;i<argc;++i)
	{
		args += *argv;
		args += ' ';
		argv++;
	}
	args.pop_back();
	return args;
}

int main(int argc, const char *argv[])
{
    string args = parseArgs(argc, argv);
    fstream f(args, ios::in);
    if(!f.good() || args[args.length()-1] != 'b')
    {
        cout << "Invalid path!";
        f.close();
        return EXIT_FAILURE;
    }

    string content, now;
    while(f >> now)
    {
        content += now + ' ';
    }
    f.close();

    bf_compiler::brainfuck bf;
    bf.load(content);
    cout << bf.program;
    bf.exec();
    return 0;
}