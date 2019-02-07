#include<stdio.h>
#include<math.h>

int bubbleSort(int a[], int size)
{
    int i, j, temp;
    for(i=size; i>0; i--)
    {
        for(j=1; j<i; j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
int main()
{
    int test, n, i, j, door[1000];
    scanf("%d", &test);
    for(i=1; i<=test; i++)
    {
        double loc, dis=0;
        scanf("%d",&n);
        for(j=1; j<=n; j++)
        {
            scanf("%d",&door[j]);
        }

        bubbleSort(door, n);

        if(n%2==0)
        {
            loc=(door[n/2]+door[(n+1)/2])/2;
        }
        if(n%2==1)
        {
            loc=door[(n+1)/2];
        }
        for(j=1; j<=n; j++)
        {
            dis=dis+fabs(loc-door[j]);
        }
        printf("%.0f\n", dis);
    }
    return 0;
}












