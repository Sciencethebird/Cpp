#include <iostream>

using namespace std;
class birb
{
public:
    birb()
    {
        birbnum = 0;
        cout << "constructor" << endl;
    }
    void method()
    {
        cout << "method" << endl;
    }

private:
    int birbnum;
    void friend birbfriendfunc(birb &la);

};

void birbfriendfunc(birb &la)  /// it's like normal function but have access to private stuff inside a class
{                          /// not like methods, friend function does not belongs to the class
    la.birbnum = 87;
    cout << "friend function access class private data = " << la.birbnum << endl;
}

int main()
{
    birb science;
    birbfriendfunc(science);
    science.method();
    return 0;
}
