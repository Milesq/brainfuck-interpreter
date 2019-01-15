#include <iostream>
#include <conio.h>

#include "../../status/status.hpp"
namespace instructs
{
    void out(status &st){std::cout << static_cast<char>(*st.memo);}
    void in(status &st){*st.memo = getch();}

    void popstack(status &st)
    {
        if(!st.memoStack.empty())
        {
            *st.memo = st.memoStack.top();
            st.memoStack.pop();
        } else *st.memo = 0;
    }
    void pushstack(status &st){st.memoStack.push(*st.memo);}
}