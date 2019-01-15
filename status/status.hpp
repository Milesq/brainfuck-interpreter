#include <stack>
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

    status(int &w, int *_memo, stack<int> &ms, string &p, bool &_integer):
        wsk(w),
        memoStack(ms),
        program(p),
        memo(_memo),
        integer(_integer) { }

    static int myStrFind(string, char, char, int n=0);
    static int myReversedStrFind(string, char, char, int n=-1);
};
#endif // STATUS