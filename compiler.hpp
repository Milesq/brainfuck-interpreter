#include <iostream>
#ifndef BF_COMPILER
#define BF_COMPILER

namespace bf_compiler {
    class brainfuck {
        public:
        int size = 100;
        std::string program="";

        void load(std::string);
        void exec();
    };
}
#endif // BF_COMPILER