#include <string>
#include "status.hpp"

using std::string;

int status::myReversedStrFind(string str, char what, char neg, int n)
{
    n = (n == -1)? str.size() - 1 : n;
    int counter = 0;
    for(;n<str.length();--n)
    {
        if(str[n] == what)
        {
            if(counter==0)
                return n;
            else counter--;
        } else if(str[n] == neg) counter++;
    }
    return -1;
}

int status::myStrFind(string str, char what, char neg, int n)
{
    int counter = 0;
    for(;n<str.length();++n)
    {
        if(str[n] == what) {
            if(counter == 0)
                return n;
            else counter--;
        } else if(str[n] == neg) counter++;
    }
    return -1;
}