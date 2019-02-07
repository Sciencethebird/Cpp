#include<stdio.h>

int main()
{
    int a, b, i, k, sum;
    while(1)
    {
        scanf("%d %d", &a, &b);
        if(a==0 && b==0)
        {
            return 0;
        }
        k=a/2;
        sum=0;
        for(i=k; 2*i+1<=b; i++)
        {
            sum = sum+2*i+1;
        }
        printf("%d\n",sum);
    }

    return 0;
}
