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

    status(int &w, int *memo, stack<int> &ms, string &p):
        wsk(w),
        memoStack(ms),
        program(p),
        memo(memo) { }

    static int myStrFind(string, char, char, int n=0);
    static int myReversedStrFind(string, char, char, int n=-1);
};
#endif // STATUS