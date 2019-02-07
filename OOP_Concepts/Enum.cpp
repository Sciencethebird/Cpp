#include<iostream>

using namespace std;

enum extra{a, b, c};
class log
{
    public:int logvar = 6969;
    enum Action {sit = 0, stand, jump}; ///0, 1, 2
};



int main()
{
    int lol = 0, b = 6969;
    log hehe;
    lol = lol + hehe.logvar;
    log::Action act = log::jump; ///a variable "act" with type "Action", act = 2
    lol = act + 1;
    lol = act + extra::b;
    cout << "Value in Action enum = " << lol << endl;

    return 0;
}
