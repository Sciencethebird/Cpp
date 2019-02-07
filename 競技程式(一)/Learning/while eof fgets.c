#include<stdio.h>
#include<stdlib.h>
#include <string.h>

sort(int A[], int n)
{
    int i, j, k,t=1, Temp, sp, ac;
    for (i=n-1; i>0; i--)
    {
        sp=1;
        for (j =0; j <i; j++)
            if (A[j] > A[j+1])
            {
                Temp = A[j];
                A[j] = A[j+1];
                A[j+1] = Temp;
                sp=0;
            }
        if (sp==1)
            break;
    }
}
///1 3 3 4 4 9 12 12 16
///
/*
16
4 8 10 14 8 16 20 28 10 20 25 35 14 28 35 49
*/
static char buf[550] = {};

int main()
{
    while(fgets(buf, sizeof(buf), stdin) != NULL)
    {
           printf("%s\n", buf);
    }
    return 0;
}
