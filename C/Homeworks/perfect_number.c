#include<stdio.h>


int isPerfect()
{
    int num, i, divcount=0,divisor[50], Q=0;
    for(num=2; num<1000; num++)
    {
        for(i=2; i<num; i++)
        {
            if(num % i == 0)
            {
                divisor[divcount]= i;
                divcount++;
            }
        }
        for(i=0; i<divcount; i++)
        {

            Q = Q+divisor[i];
        }
        if(Q+1 == num)
        {
            printf("%d = 1", num);
            for(i=0; i<divcount; i++)
            {
                printf(" + %d", divisor[i]);
            }
            printf("\n");
        }

        divcount=0;
        Q=0;
    }
}

int main()
{
    printf("Perfect integers between 1 and 1000\n");
    isPerfect();
    return 0;
}
