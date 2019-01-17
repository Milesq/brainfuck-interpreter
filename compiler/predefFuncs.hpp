#include <string>
#include <iostream>
#include <stack>
#include <map>

#include <time.h>
#include <stdlib.h>

using namespace std;

typedef stack<int> T;
 // zrobić z tego dll'a albo .a
 // z innych plików porobić.a bo inaczej to nie robota...
map<string, T(*)(T)> predefinedFuncs = {
    {"rd", [](T st) -> T {
        int (*popStack)(stack<int>&) = [](stack<int> &st) -> int {
            if(st.size() == 0) return 0;
            int ret = st.top();
            st.pop();
            return ret;
        };
        static bool firstTime = true;
        if(firstTime)
        {
            srand(time(NULL));
            firstTime = false;
        }

		int min = popStack(st);
        int max = popStack(st);
        max = (max==0)? 100 : max;
        st.push(rand() % max + min);
        return st;
    }},
    {"exit", [](T st) -> T {
        exit((st.size() > 0)? st.top() : 0);
    }}
};