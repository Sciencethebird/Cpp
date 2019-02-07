#include<iostream>
using namespace std;
class example
{
public:
    example();
    example(int k, int m, int n);
    void printval(){
        cout << a << " " << b << " " << c << endl;
    }
private:
    int a, b, c;
};
example::example():a(0), b(0), c(0){};
example::example(int k, int m, int n):a(k), b(m), c(n){};
int main()
{

    example e1(1, 2, 3), e2;
    e1.printval();
    e2.printval();
    return 0;
}
