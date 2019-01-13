#include <iostream>
#ifndef BF_COMPILER
#define BF_COMPILER

namespace bf_compiler {
    class brainfuck {
        bool dev;
        bool integer;
        bool normalBrainfuck;
        public:
        int size = 100;
        std::string program="";

        brainfuck(bool _dev=false, bool _integer=false, bool nbf=false):
            dev(_dev),
            integer(_integer),
            normalBrainfuck(nbf) {}
        void load(std::string);
        void exec();
    };
}
#endif // BF_COMPILER