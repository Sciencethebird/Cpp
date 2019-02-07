#include<iostream>
#include<string>
using namespace std;

/*
What are you going to learn from the program?
    1. It's bad to set variables in class public
    2. How to read/write a variable even when it's private

Note
    1.use object_name.stuff_in_class() to access functions/vari
      in object.
            ex: lol.addnumbers()
                lol.a


*/
namespace birb
{
class pub_variable
{
public:
    string pub_a;   ///It's really bad to set variables in classes public
    void print()
    {
        cout << "birb Public: " << pub_a << endl;
    }
};
}
namespace doggo
{
class pub_variable
{
public:
    string pub_a;   ///It's really bad to set variables in classes public
    void print()
    {
        cout << "doggo Public: " << pub_a << endl;
    }
};
}
class pri_variable
{
public:
    void write(string x)
    {
        pri_a = x;
    }
    string read()     ///"string" used s.t. the function returns string type
    {
        return pri_a;
    }

private:
    string pri_a;
};
int main()
{
    birb::pub_variable lol;
    pri_variable lol2;  /// can't use lol again, a conflict will occur(error)

    /// code below shows how to access public stuff in class
    lol.pub_a = "lalalalalal, public y\'all";  /// viable but bad method
    lol.print();
    //lol.print();
    ///you can't access private stuff in main fuction
    //lol2.pri_a = "error";

    ///so how do i access private variable?
    lol2.write("lol i write stuff into pri_a");
    cout << lol2.read() << endl;

    return 0;
}
