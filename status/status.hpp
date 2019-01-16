#include <stack>
#include <map>
#include <iostream>
#ifndef STATUS
#define STATUS

using namespace std;

class status {
    public:
    int *memo;
    int &wsk;
    stack<int> &memoStack;
    string &program;
    bool &integer;
    bool &dev;
    map<string, string> declaredFunctions;

    status(int &w,
           int *_memo,
           stack<int> &ms,
           string &p,
           bool &_integer,
           bool &_dev,
           map<string, string> &df):
        wsk(w),
        memoStack(ms),
        program(p),
        memo(_memo),
        declaredFunctions(df),
        integer(_integer),
        dev(_dev){ }

    static int myStrFind(string, char, char, int n=0);
    static int myReversedStrFind(string, char, char, int n=-1);
};
#endif // STATUS