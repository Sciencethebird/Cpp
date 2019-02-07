#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int main()
{
    long long int a, b, comdiv, ref, i;
    scanf("%lli %lli", &a, &b);
    if(a >= b)
    {
        ref =  a;
    }
    else
    {
        ref =  b;
    }
    if( a < 0 && b < 0)
    {
        if( a <= b)
        {
            ref =  -a;
        }
        else
        {
            ref =  -b;
        }
    }
    for(i = 1; i<= ref; i++)
    {
        if(a % i == 0 && b % i == 0)
        {
            comdiv = i;
        }
    }
    printf("%lli", comdiv);
    return 0;
}
