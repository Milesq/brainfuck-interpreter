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
    if(args["help"] == "true")
    {
        #pragma region helpMesage
        cout << "Interprets the code saved in the file with the extension .b"
             << "\n\nAvailable switches:\n"
             << "\n\n--int   Displays numbers from cells instead of the "
             << "corresponding ASCII characters"
             << "\n\n--ext   Includes the interpretation of my extended brainfuck"
             << "\n\n--dev   After each instruction, the program stops, displays the "
             << "contents of the current cell and instruction,\n" 
             << "then waits for any key to be pressed. To finish press 'q'\n\n\n";
        #pragma endregion
        return 0;
    }

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