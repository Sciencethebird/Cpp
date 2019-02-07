#include<stdio.h>

int main()
{
    int a, i, j, n;
    scanf("%d",&a);
    for(i=1; i<=a; i++)
    {
        scanf("%d",&n);
        int age[n];
        for(j=1; j<=n; j++)
        {
            scanf("%d",&age[j]);
        }
        j=(n+1)/2;
        printf("Case %d: %d\n",i,age[j]);

    }
    return 0;
}
