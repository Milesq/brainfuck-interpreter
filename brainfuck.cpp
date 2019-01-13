#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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
    string content,
           fileName,
           now = "",
           argcv = parseArgs(argc, argv) + " P";
    bool dev = false,
         integer = false;
    vector<string> args;

    while(argcv.size() > 0)
    {
        if(argcv[0] == ' ' && now != "") {
            args.push_back(now);
            now = "";
        } else now += argcv[0];
        argcv.erase(0, 1);
    }

    for(string i: args)
    {
        if(i[0] != '-') fileName = i;
        if(i == "--int") integer = true;
        if(i == "--dev") dev = true;
    }
    
    fstream f(fileName, ios::in);
    if(!f.good() || fileName[fileName.length()-1] != 'b')
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

    bf_compiler::brainfuck bf(dev, integer);
    bf.load(content);
    bf.exec();
    return 0;
}