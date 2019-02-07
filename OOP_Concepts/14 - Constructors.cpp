#include <iostream>
using namespace std;

/*
What we're gonna learn from the program?

    1.Constructors oc boiii
Note

    1.Constructor is a function in class that is called automatically(when it's created in main function).
      Usually used to initialize variables.
    2.Constructors don't have return type, so no need for int, void, whatever.
    3.name is the name of class
    4.public by default, can be used in private, but I'm lazy right now, it has something to do with friend function.
    5.you can only create one constructor.
*/
class birbclass
{
public:
    birbclass() ///this constructor is needed otherwise you won't be able to
    {
        ///initiate a class without any argument
        cout << "default birb" << endl;
        name = "Unknown" ;
    }
    birbclass(string z)
    {
        cout << "print birb automatically, " << z <<endl;
        name = z;
    }
    void send()
    {
        cout << "send nudes" << endl;
    }
    void write(string x)
    {
        name = x;
    }
    string read()
    {
        return name;
    }
private:
    string name;
};

class another
{

private:
    birbclass dd;
    int a;
public:
    another()
    {
        dd = birbclass("dd");
    }
};
int main()
{
    another hehe;

    birbclass obj1("science"), obj2("Harro"), obj3; ///initialize boii
    ///obj3 need a blank constructor
    obj3 = birbclass("Max");                        ///this is black magic

    cout << obj1.read() << endl;
    cout << obj2.read() << endl;
    cout << obj3.read() << endl;

    return 0;
}
