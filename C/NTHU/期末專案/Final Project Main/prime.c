#include<stdio.h>
#include<math.h>


int main()
{

    int i,j,k, a=3,countp=0,countt=0;
    printf("�п�J���:\n");
    scanf("%d",&k);
    printf("\n2\n");
    for(j=3; j<k; j++)
    {
        for(i=2; i<j; i++)
        {
            if(i==j-1)
            {
                printf("%d\n",j);
                if(j==a+2)
                {
                    printf("����p�ͽ��:(%d,%d)\n",a,j);
                    countt++;
                }
                countp++;
                a=j;

            }
            if(j%i==0)
            {
                break;
            }
        }

    }
    printf("\n\n���:%d��\n���p�ͽ��:%d��\n\n",countp+1,countt);

    return 0;
}
