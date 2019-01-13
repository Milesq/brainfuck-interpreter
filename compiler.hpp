#include <iostream>
#ifndef BF_COMPILER
#define BF_COMPILER

namespace bf_compiler {
    class brainfuck {
        bool dev;
        bool integer;
        public:
        int size = 100;
        std::string program="";

        brainfuck(bool _dev=false, bool _integer=false): dev(_dev), integer(_integer) {}
        void load(std::string);
        void exec();
    };
}
#endif // BF_COMPILER