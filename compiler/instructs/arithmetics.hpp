#include "../../status/status.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace instructs
{
    void add    (status &st) {++(*st.memo);}
    void sub    (status &st) {--(*st.memo);}
    void left   (status &st) {--st.memo;}
    void right  (status &st) {++st.memo;}

    void multiply(status &st) {
        *st.memo *= (static_cast<int>(st.program[st.wsk+1]) - 48);
        ++st.wsk;
    }
    void divide(status &st) {
        *st.memo /= (static_cast<int>(st.program[st.wsk+1]) - 48);
        ++st.wsk;
    }
    void modulo(status &st) {
        *st.memo %= (static_cast<int>(st.program[st.wsk+1]) - 48);
        ++st.wsk;
    }
}