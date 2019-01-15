#include "../../status/status.hpp"
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
    /*void funcBeg(status &st)
    {
        string func = "";
        while(program[++wsk] != ')') func += program[wsk];
        if(declaredFunctions[func] == "")
            throw "Undeclared function " + func + "!";
    }*/
}