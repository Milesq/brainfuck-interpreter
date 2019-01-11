#include <iostream>
#ifndef BF_COMPILER
#define BF_COMPILER

namespace bf_compiler {
    class brainfuck {public:
        int *memo;
        int size = 100;
        // public:
        std::string program="";

        brainfuck() {
            this->memo = new int [size];
            this->memo += this->size / 2;
        }

        ~brainfuck() {
            delete[] this->memo; 
        }

        void load(std::string);
        void exec();
    };
}
#endif // BF_COMPILER