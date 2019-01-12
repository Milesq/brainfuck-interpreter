#include <iostream>
#ifndef BF_COMPILER
#define BF_COMPILER

namespace bf_compiler {
    class brainfuck {
        public:
        int size = 100;
        bool dev;
        std::string program="";

        brainfuck(bool _dev=false) { this->dev = _dev; }
        void load(std::string);
        void exec();
    };
}
#endif // BF_COMPILER