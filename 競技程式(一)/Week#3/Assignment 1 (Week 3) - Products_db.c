#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

 sort(long long A[], int n)
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
///1 3 3 4 4 9 12 12 16
///
/*
16
4 8 10 14 8 16 20 28 10 20 25 35 14 28 35 49

4 9 6 6
1 2 3 4
3 3 5 6 9 15 18 15 18 30 3 3 5 6 9 15 18 15 18 30 1 9 9 25 36
4 6 8 12 6 9 12 18 8 12 16 24 12 18 24 36
16 24 48 24 36 72 48 72 144 1 4 6 12 4 6 12     ///1 4 6 12 產生可除但不是除數產生的元素
4 8 12 12 8 16 24 24 12 24 36 36 12 24 36 36
*/
static char buf[550] = {};

int main()
{
    while(fgets(buf, sizeof(buf), stdin) != NULL)
    {
        int i = 0, j, k, size = 0,  as, bs;
        //fgets(buf, sizeof(buf), stdin);
        long long data[40] = {}, comp[40] = {} , ans[20] = {}, base[20], max, min;
        printf("\ninput (using fgets) = %s", buf);
        char *test = strtok(buf, " ");

        printf("\nusing strtok to seperate string\n");
        while (test != NULL)
        {
            printf("%s\n", test);
            data[size] = atoll (test);
            test = strtok(NULL, " ");
            size++;
        }
        //scanf("%d", &size);

        /*for(i = 0; i<size; i++)
        {
            scanf("%d", &data[i]);
        }*/
        printf("size = %d\n\n", size);


        sort(data, size);

        printf("sorted data[] below\n\n");
        for(i = 0; i<size; i++)
        {
            printf("%lli ", data[i]);
        }

        as = sqrt(size) - 1;

        max = sqrt(data[size-1]);
        min = sqrt(data[0]);

        printf("\nstart: %lli, end: %lli\n\n", min, max);

        j=0;

        //printf("\n\n\ni don't know what i'm doing down there\n\n\n\n");

        for(i = 0; i< size; i++)
        {

            if(data[i] == data[i+1])
            {
                i++;
            }
            if(data[i] % max == 0)
            {

                ans[j] = data[i] / max;
                //printf()
                printf("yeah~ found : %d\n", ans[j]);
                j++;
            }

        }
        bs = j;
        printf("\nbase element number = %d\n", bs);

        j = 0;
        printf("\nas(elements number -1) = %d\n",as);

        for(i = 0; i<=as; i++)
        {
            for(k = 0; k <=as; k++)
            {
                comp[j] = ans[i]*ans[k];
                j++;
            }
        }

        sort(comp, size);
        printf("\n\nthis is compare seq(generated by found elements)\n\n");

        for(i = 0; i<size; i++)
        {
            printf("%lli ", comp[i]);
        }

        for(i = 0; i < size; i++)
        {
            if(data[i] != comp[i])
            {
                printf("\nhelllllllll no\n");
                break;
            }
            if(i == size -1)
            {
                printf("\nyes\n");
                for(j = 0; j<=as; j++)
                {
                    printf("%d ", ans[j]);
                }
            }
        }
    }
    return 0;
}
