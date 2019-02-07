#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    char a[10000];
    int num;
    while(fgets(a, 66, stdin) != NULL)
    {
        //cout << a << endl;
        num = atoi(a);


        cout << sqrt(num) << endl;

    }

    return 0;
}

/*
12
23
34
56
*/
