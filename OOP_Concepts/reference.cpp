#include<iostream>

using namespace std;



int main()
{
    int a = 10;
    int& Ref = a;
    cout << Ref << endl;
    Ref  = 20;
    cout << Ref << " "<< a << endl;/// change ref will change a
    return 0;
}



