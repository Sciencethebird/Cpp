#include<stdio.h>

int main()
{
    int n=1, k=1, j, CASE=1, day, start;
    double RSI, U=0, D=0, u, d;
    while(n!=0 && k!=0)
    {
        scanf("%d %d", &n, &k);
        day=k;
        if(n==0 && k==0)
        {
            break;
        }
        else
        {
            double a[n];
            printf("Case %d:\n",CASE);
            for(j=0; j<n; j++)
            {
                scanf("%lf", &a[j]);
                printf("%f ",a[j]);
            }
            printf("\n");

            for(start=0; start<n-k; start++)
            {
                for(j=start; j<start+k; j++)
                {

                    if(a[j]<a[j+1])
                    {
                        u=a[j+1]-a[j];
                        printf("\nu=%f",u);
                        U=U+u;
                    }
                    if(a[j]>a[j+1])
                    {
                        d=a[j]-a[j+1];
                        printf("\nd=%f",d);
                        D=D+d;
                    }
                }
                printf("\n%f,%f",U,D);
                U=U/k;
                D=D/k;
                RSI=U/(U+D)*100;
                U=0;
                D=0;
                printf("\n");
                printf("day %d: %.2f\n",day,RSI);
                day=day+1;
            }
            CASE=CASE+1;
        }
    }
    return 0;
}
