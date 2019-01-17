#include "../../status/status.hpp"
#include "../compiler.hpp"
#include "../predefFuncs.hpp"
#include <map>

namespace instructs
{
    void loopBeg(status &st)
    {
        if(*st.memo == 0)
        {
            st.wsk = status::myStrFind(st.program, ']', '[', st.wsk + 1);
        }
    }
    void loopEnd(status &st)
    {
        st.wsk = status::myReversedStrFind(st.program, '[', ']', st.wsk - 1) - 1; 
    }
    void funcBeg(status &st)
    {
        string func = "";
        while(st.program[++st.wsk] != ')') func += st.program[st.wsk];
        if(st.declaredFunctions[func] == "")
        {
            if(!predefinedFuncs[func]) throw "Undeclared function " + func + "!";
            st.memoStack = predefinedFuncs[func](st.memoStack);
        } else {
            bf_compiler::brainfuck procedure(st.dev, st.integer, false);
            procedure.load(st.declaredFunctions[func]);
            st.memoStack = procedure.exec(st.memoStack);
        }
    }
}