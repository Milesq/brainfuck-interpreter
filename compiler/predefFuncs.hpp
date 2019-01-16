#include <string>
#include <iostream>
#include <stack>
#include <map>

#include <time.h>
#include <stdlib.h>

using namespace std;

typedef stack<int> T;

map<string, T(*)(T)> predefinedFuncs = {
    {"rd", [](T st) -> T {
        static bool firstTime = true;
        if(firstTime)
        {
            srand(time(NULL));
            firstTime = false;
        }
        st.push(rand() % 100 + 1);
        return st;
    }}
};