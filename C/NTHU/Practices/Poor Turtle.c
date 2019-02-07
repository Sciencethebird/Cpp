#include<stdio.h>
void uppertri(a)
{
    int  row, col, start;
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
}
void lowertri(a)
{
    int row, col, start;
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

int main ()
{
    int a, s, row, col, start;
    while(a!=0)
    {
        scanf("%d %d", &a, &s);
        if(s>=2*a*a-2*a+1)
        {
            uppertri(a);
            lowertri(a);
        }
        if(s>a*a && s<2*a*a-2*a+1)
        {
            uppertri(a);
        }
        if(s<a*a)
        {
            lowertri(a);

        }
    }
    while(a==0)
    {
        break;
    }

    return 0;

}
