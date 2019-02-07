#include<iostream>
using namespace std;
long long GCD(long long a, long long b) {
	if(b) while((a %= b) && (b %= a)){
        cout << "a= " << a << " " << "b= "<< b << endl;
	}
	cout << "GCD = " << a+b << endl;
	return a + b;
}
int main()
{
    int cs;
    cin >> cs;
    for(int i = 0; i< cs; i++)
    {
        long long num1, num2, lcm, A;
        scanf("%lli", &num1);
        scanf("%lli", &num2);

        cout << GCD(num1, num2) << endl;
    }
    return 0;
}
