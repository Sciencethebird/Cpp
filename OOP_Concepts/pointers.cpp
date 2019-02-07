#include<iostream>
using namespace std;

int main(){

    int lol = 5, XD = 4;
    int* ptr = &lol;  ///send the address of lol into ptr

    cout <<"Address = "<< ptr << "  Content = " << *ptr <<endl;
    ptr = &XD;
    cout <<"Address = "<< ptr << "  Content = " << *ptr <<endl;
    return 0;
}
