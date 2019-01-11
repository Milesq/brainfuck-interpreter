#include <map>
#include <iostream>

using namespace std;

typedef int(*func)(int, int);

int main()
{
    static int x = 8;

    map<char, func> funcs = {
        {'q', [](int a, int b) -> int {
            return a + b;
        }},
        {'w', [](int a, int b) -> int {
            return a * b * x;
        }}
    };
    cout << endl << funcs['w'](5, 6);
    cout << endl << funcs['q'](4, 2);
    ////////////////////////////////////
    cout << endl << [](int a, int b) -> int {
        return a + b + x;
    }(2, 5);
    return 0;
}