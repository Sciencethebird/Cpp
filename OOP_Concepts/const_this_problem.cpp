#include<iostream>
using namespace std;

class foo{
public:
    foo(int n):a(n){}
    foo():a(0){}
    /*foo(const foo &n){
        cout << "copied" << endl;
        a = n.a;
    }*/
    int a;
    foo function();

    friend ostream& operator << (ostream &stream, foo &n);
};

foo foo::function(){
    a++;
    return *this;
}
void another_function(foo n){
    n.a--;
}
ostream& operator <<(ostream &stream, foo &n){
    stream << n.a;
    return stream;
}
int main(){

    foo xd(87);
    cout << xd << endl;
    another_function(xd.function());
    cout << xd;
    return 0;
}

