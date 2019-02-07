#include<stdio.h>
#include<stdlib.h>

Sort(int A[], int n, int req)
{
    int i, j, k,t=1, Temp, sp, ac;
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
    req = A[req-1];
    return req;
}

int main()
{
    int asize, qnumber, a[150], q[250][3], cap[150], ans;
    int i, j, s, m;

    scanf("%d %d", &asize, &qnumber);

    for(i = 1; i <= asize; i++)
    {
        scanf("%d", &a[i]);
    }
    for(i = 1; i <= qnumber; i++)
    {
        for(j = 0; j < 3; j++)
            scanf("%d", &q[i][j]);
    }

    for(i = 1; i <= qnumber ; i++)
    {
        s = 0;
        for(j = q[i][0]; j <= q[i][1]; j++)
        {
            cap[s] = a[j];
            s++;
        }
        ans = Sort(cap, q[i][1] - q[i][0]+1, q[i][2]);
        printf("%d\n", ans);
    }
    return 0;
}

