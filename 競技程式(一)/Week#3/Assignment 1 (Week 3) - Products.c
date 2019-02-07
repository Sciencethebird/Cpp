#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int sort(long long A[], int n)
{
    int i, j, k, sp, ac;
    long long Temp;

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

static char buf[550] = {};

int main()
{
    while(fgets(buf, sizeof(buf), stdin) != NULL)
    {
        int i = 0, j, k, size = 0,  as, bs;
        long long data[40] = {}, comp[40] = {}, ans[20] = {}, base[20], max, min;
        char *test = strtok(buf, " ");
        while (test != NULL)
        {
            data[size] = atoll (test);
            test = strtok(NULL, " ");
            size++;
        }

        sort(data, size);

        as = sqrt(size) - 1;

        max = sqrt(data[size-1]);
        min = sqrt(data[0]);

        j=0;

        if(as == 0)
        {
            ans[0] = min;
        }
        if(as == 1)
        {
            ans[0] = min;
            ans[1] = max;
        }
        if(as == 2)
        {
            ans[0] = min;
            ans[1] = data[1]/min;
            ans[2] = max;
        }
        if(as == 3)
        {
            ans[0] = min;
            ans[1] = data[1]/min;
            ans[2] = data[size-2]/max;
            ans[3] = max;
        }
        if(as == 4)
        {
            ans[0] = min;
            ans[1] = data[1]/min;
            ans[3] = data[size-2]/max;
            ans[4] = max;
            if(data[3] == data[4]){
                ans[2] = data[3]/ans[0];
            }
            if(data[size-4] == data[size-5]){
                ans[2] = data[size-4]/ans[4];
            }
            if(data[3] != data[4] && data[size-4] != data[size-5]){
                ans[2] = data[4]/ ans[0];
            }
        }

        j = 0;
        for(i = 0; i<=as; i++)
        {
            for(k = 0; k <=as; k++)
            {
                comp[j] = ans[i]*ans[k];
                j++;
            }
        }
        sort(comp, size);
        for(i = 0; i < size; i++)
        {
            if(data[i] != comp[i])
            {
                printf("No\n");
                break;
            }
            if(i == size -1)
            {
                printf("Yes\n");
                for(j = 0; j<=as; j++)
                {
                    printf("%lli ", ans[j]);
                }
            }
        }
    }
    return 0;
}
