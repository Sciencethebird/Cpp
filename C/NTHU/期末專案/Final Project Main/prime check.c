#include<stdio.h>
#include<math.h>

int main()
{
    long long int num=1, i,j,count=0;
    int s1,s2,s3,s4,s5;

    while(num!=0)
    {
        printf("\nEnter a number:");
        scanf("%d",&num);
        if(num==0)
        {
            printf("\nprogram ended\n");
            return 0;
        }
        if(num==2)
        {
            printf("\n%d is a prime\n",num);
        }

        if(num==1)
        {
            printf("\n%d is not a prime\n",num);
        }

        s1=num*0.1;
        s2=num*0.25;
        s3=num*0.5;
        s4=num*0.75;
        s5=num*0.90;

        for(i=2; i*i<=num; i++)
        {

            if(num%i==0)
            {
                printf("\n%d is not a prime\n",num);
                count++;
                break;
            }

            /*if(num>100000000)
            {
                if(i*i==s1)
                {
                    printf("\n10%%");
                }
                if(i*i==s2)
                {
                    printf(" 25%%");
                }
                if(i*i==s3)
                {
                    printf(" 50%%");
                }
                if(i*i==s4)
                {
                    printf(" 75%%");
                }
                if(i*i==s5)
                {
                    printf(" 90%%\n");
                }
            }*/

        }
        if(count==0)
        {
            printf("\n%d is a prime\n",num);
        }
        count=0;
    }

}
///1909660513
///2038072819
