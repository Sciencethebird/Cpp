#include<iostream>
using namespace std;
long long GCD(long long a, long long b) {
	if(b) while((a %= b) && (b %= a));
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
        scanf("%lli", &lcm);
        if(lcm % num1 != 0)
        {
            cout << "-1" << endl;
            continue;
        }

        A = lcm / num1;
        while(A*A < lcm){
            A*=A;
        }
        cout << A << endl;
    }
    return 0;
}
