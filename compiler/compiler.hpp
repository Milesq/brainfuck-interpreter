#include <iostream>
#include <string>
#include <stack>
#include <map>
#ifndef BF_COMPILER
#define BF_COMPILER

using namespace std;

namespace bf_compiler {
    class brainfuck {
        protected:
        bool dev;
        bool integer;
        bool normalBrainfuck;

        private:
        map<string, string> declaredFunctions;

        public:
        int size = 100;
        string program = "";

        brainfuck(bool _dev=false, bool _integer=false, bool nbf=false):
            dev(_dev),
            integer(_integer),
            normalBrainfuck(nbf) {}
        void load(string);
        stack<int> exec();
    };
}
#endif // BF_COMPILER