#include<stdio.h>
#include<math.h>

void bubbleSort(int a[], int size)
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
    int  num[200], dgt[5], ord[100], inv[100], i, j, o;
    int a=1;
    while(1)
    {
        scanf("%d", &num[0]);
        if(num[0] == 0)
        {
            return 0;
        }
        printf("Case %d: %05d\n", a , num[0]);
        for(i=0; i<100; i++)
        {
            dgt[4] = num[i] % 10;
            dgt[3] = (num[i] %100 - num[i] % 10) / 10;
            dgt[2] = (num[i] %1000 - num[i] % 100) / 100;
            dgt[1] = (num[i] %10000 - num[i] % 1000) / 1000;
            dgt[0] = (num[i]- num[i] % 10000) / 10000;

            bubbleSort(dgt, 5);

            ord[i] = dgt[0]*10000 + dgt[1]*1000 + dgt[2]*100 + dgt[3]*10 + dgt[4];
            inv[i] = dgt[4]*10000 + dgt[3]*1000 + dgt[2]*100 + dgt[1]*10 + dgt[0];

            num[i+1]=inv[i]-ord[i];
            ///記得i會加到100，雖然100不會進入迴圈，但size大於100，只設100會爆掉
        }

        for(i=0; i<100; i++)
        {

            for(j=1; j<100; j++)
            {

                if(i!=j && num[i]==num[j])
                {
                    for(o=0; o<j; o++)
                    {
                        printf("%05d - %05d = %05d\n", inv[o], ord[o], num[o+1]);
                    }
                    break;
                }
            }

            if(i!=j && num[i] == num[j])
            {   printf("       %d       \n",i);
                printf("Cycle length: %d\n\n", j-i+1);
                break;
            }
        }
        a++;

    }
    return 0;
}
