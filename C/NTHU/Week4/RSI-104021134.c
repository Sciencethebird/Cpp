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
            double a[2000];

            for(j=0; j<n; j++)
            {
                scanf("%lf", &a[j]);
            }
            printf("Case %d:\n",CASE);
            for(start=0; start<n-k; start++)
            {
                for(j=start; j<start+k; j++)
                {

                    if(a[j]<a[j+1])
                    {
                        u=a[j+1]-a[j];
                        U=U+u;
                    }
                    if(a[j]>a[j+1])
                    {
                        d=a[j]-a[j+1];
                        D=D+d;
                    }
                }
                U=U/k;
                D=D/k;
                if(U==0 && D==0)
                {
                    RSI=0;
                }
                else
                {
                    RSI=U/(U+D)*100;
                }
                U=0;
                D=0;
                printf("day %d: %.2f\n",day,RSI);
                day=day+1;
            }
            printf("\n");
            CASE=CASE+1;
        }
    }
    return 0;
}
