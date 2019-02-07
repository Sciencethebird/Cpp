#include <iostream>
using namespace std;

void doublesize(int * &arrptr, int &sz) /// pointer call by reference
{
    int *newptr = new int[sz*2];
    for(int i = 0; i<sz; i++)
    {
        newptr[i]= arrptr[i];
    }
    delete [] arrptr;
    cout << "arrptr address before doubling: "<<arrptr <<endl;
    arrptr = newptr;
    cout << "arrptr address after doubling: "<<arrptr <<endl;
    sz *=2;
}

int main()
{
    int sz;
    cout << "Please enter size of the array : ";
    cin >> sz;
    int *arrptr = new int[sz];

    int bound;
    cout <<"Please enter the number of element you want to store: ";
    cin >> bound;
    for(int i = 0; i<bound; i++)
    {
        if(i + 1> sz){  /// ex: sz = 4, when i = 4, 5>4 -> need more size
           doublesize(arrptr, sz);
           cout << "array size doubled   " << sz/2 << "to" << sz << endl;
        }
        arrptr[i] = i;
    }

    for(int i = 0; i< bound; i++){
        cout << arrptr[i] << " ";
    }

    //cout << arrptr[10] << endl;
    delete [] arrptr;


    return 0;
}
