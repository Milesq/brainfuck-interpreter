#include <stack>
#include <map>
#include <iostream>
#ifndef STATUS
#define STATUS

using namespace std;

class status {
    public:
    int &wsk;
    int *&memo;
    stack<int> &memoStack;
    string &program;
    bool &integer;
    bool &dev;
    map<string, string> &declaredFunctions;

    status(int &w,
           int *&memo,
           stack<int> &ms,
           string &p,
           bool &_integer,
           bool &_dev,
           map<string, string> &df):
        wsk(w),
        memo(memo),
        memoStack(ms),
        program(p),
        integer(_integer),
        dev(_dev),
        declaredFunctions(df) { }

    static int myStrFind(string, char, char, int n=0);
    static int myReversedStrFind(string, char, char, int n=-1);
};
#endif // STATUS