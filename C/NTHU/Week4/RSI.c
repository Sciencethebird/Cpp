#include<stdio.h>

void bubbleSort(double a[], int size)
{
    int i, j, temp;

    for(i=size-1; i>=0; i--)
    {
        for(j=0; j<i; j++)
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
    int n, k, j, CASE, day;
    while(n!=0 && k!=0)
    {
        scanf("%d %d", &n, &k);
        if(n==0 && k==0)
        {
            break;
        }
        else
        {
            double a[n];
            for(j=0; j<n; j++)
            {
                scanf("%lf", &a[j]);
                printf("%f ", a[j]);
            }
            bubbleSort(a, n);
            printf("\n重新排序為");
            for(j=0; j<n; j++)

            {
                printf("%f ", a[j]);
            }





            //printf("Case %d:\n",CASE);
            //printf("day %d: %.2f\n",day);
        }








    }
    return 0;
}
