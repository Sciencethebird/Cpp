#include<stdio.h>
#include<math.h>


int main()
{

    int i, j, k, a=3, count, countp=0, countt=0;
    printf("請輸入邊界:\n");
    scanf("%d",&k);
    printf("\n2\n");
    for(j=3; j<k; j++)
    {
        count=0;
        for(i=2; i*i<=j; i++)
        {
            if(j%i==0)
            {
                count++;
                break;
            }
        }
        if(count==0)
        {
            printf("%d\n",j);
            if(j==a+2)
            {
                printf("找到孿生質數:(%d,%d)\n",a,j);
                countt++;
            }
            countp++;
            a=j;

        }

    }
    printf("\n\n質數:%d個\n對孿生質數:%d對\n\n",countp+1,countt);

    return 0;
}
