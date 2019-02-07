#include<stdio.h>
int main ()
{
    int a, row, col, start;
    while(a!=0)
    {
        scanf("%d",&a);
        for(row=1; row<a+1; row++)
        {
            for(col=a-row; col>0; col--)
            {
                printf(" ");
            }
            for(start=1; start<2*row; start++)
            {
                printf("*");
            }
            printf("\n");
        }
        for(row=a-1; row>0; row--)
        {
            for(col=0; col<a-row; col++)
            {
                printf(" ");
            }
            for(start=1; start<2*row; start++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    while(a==0)
    {
        break;
    }

    return 0;

}
