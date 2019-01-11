#include <iostream>
#ifndef BF_COMPILER
#define BF_COMPILER

namespace bf_compiler {
    class brainfuck {
        std::string program;
        inline void load(std::string);
        void exec();
    };
}
#endif // BF_COMPILER