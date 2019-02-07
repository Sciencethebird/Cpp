#include<iostream>
#include<string>
using namespace std;
class mother_birb
{
private:
    string id = "mother birb";
    int a;
public:
    mother_birb() {}
    mother_birb(int a)
    {
        this->a = a;
    }
    virtual string Get_id(){return id;}
    ///without virtual only "mother birb" will be print.
};

class baby_birb : public mother_birb
{
private:
    string id = "baby_birb";
    int a;
public:
    baby_birb() {}
    baby_birb(int a)
    {
        this->a = a;
    }
    string Get_id(){return id;}

};

void printbirb_id(mother_birb &b)
{
    cout << b.Get_id() << endl;
}

int main()
{
    mother_birb m1;
    baby_birb c1;
    printbirb_id(m1);
    printbirb_id(c1);  ///print "baby" only if you mark the Get_id() function
                       ///in the base class "virtual".

    return 0;
}
