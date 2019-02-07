#include <iostream>

using namespace std;

int main(){
    const double pi = 3.14;
    double const e = 2.718;

    const int *ptr = new int;

    const double *ptr2 = &pi;
    //*ptr2 = 3;
    //*ptr = 2;
    int *ptr3 = new int;
    *ptr3 = 3;

    cout << *ptr3 << ",  " << e << endl;
    return 0;
}



