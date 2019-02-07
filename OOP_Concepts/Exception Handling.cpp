#include<iostream>
#include<string>
using namespace std;
double divide(int a, int b)
{
    double c;
    if(b == 0)
    {
        throw "no divided by zero, get a book, stupid!";
    }

    c = (double)a/(double)b;
    return c;
}


int main()
{
    int a, b;
    cout <<"a divided by b, enter a, b(integer): ";
    while(cin >> a >> b)
    {
        cout << "input = " << a << ", " << b << endl;

        try
        {
            divide(a, b);
        }catch(const char* blabla){
            cout << blabla << endl;
            goto next_in;
        }
        cout << "Ans = " << divide(a, b) << endl;
        next_in:
        cout <<"a divided by b, enter a, b(integer): ";
    }


    //divide(a, b);

    return 0;
}
