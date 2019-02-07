#include<iostream>

using namespace std;
class birb{
public:
    void printfunction();
    void printconstfunction() const;
};

void birb::printfunction(){
    cout << "This is a regular function"<< endl;
}
void birb::printconstfunction() const {
    cout << "This is a const function" << endl;
}
int main(){

    birb b1;
    birb const b2;
    b1.printfunction();
    b1.printconstfunction();
    ///b2.printfunction(); error
    b2.printconstfunction();

     return 0;
}
