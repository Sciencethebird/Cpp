#include <iostream>
#include<string>

/// implement a array of structure
using namespace std;
template<class T>
void doublesize(T * &arrptr, int &sz) /// pointer call by reference
{
    T *newptr = new T[sz*2];
    for(int i = 0; i<sz; i++)
    {
        newptr[i]= arrptr[i];
    }
    delete [] arrptr;
    cout << "arrptr address before doubling: "<< arrptr <<endl;
    arrptr = newptr;
    cout << "arrptr address after doubling: "<< arrptr <<endl;
    //cout << "sizeof = " << sizeof (arrptr) << endl;
    sz *=2;
}

struct birb
{
    string name;
    int db;
    int dankness;
    void writename(string name)
    {
        this->name = name;    ///this ->  equals to birb::name
    }
    void displayinfo()
    {
        cout<<"Name = " << birb::name << endl;
    }
};
int main()
{
    int sz;
    cout << "Please enter size of the Birb Database : ";
    cin >> sz;

    //birb science;
    birb *birbdata = new birb[sz];

    int bound;
    cout <<"Please enter the max  number of data you want to store: ";
    cin >> bound;
    for(int i = 0; i<bound; i++)
    {
        if(i + 1> sz)   /// ex: sz = 4, when i = 4, 5>4 -> need more size
        {
            doublesize(birbdata, sz);
            cout << "array size doubled   " << sz/2 << "to" << sz << endl;
        }
        birbdata[i].writename("N\\A");
    }

    birbdata[5].writename("Science");

    for(int i = 0; i< bound; i++)
    {
        cout << i+1 << "th birb: ";
        birbdata[i].displayinfo();
    }

    //cout << arrptr[10] << endl;
    delete [] birbdata;


    return 0;
}
