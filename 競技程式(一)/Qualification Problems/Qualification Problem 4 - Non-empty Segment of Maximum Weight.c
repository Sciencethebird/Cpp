#include<stdio.h>
#include<stdlib.h>

int main()
{
    int data[1100], i, size, start, range, max, sum;


    scanf("%d", &size);

    for(i=0; i<size; i++)
        scanf("%d", &data[i]);

    /*for(i=0; i<size; i++)
        printf("%d", data[i]);*/

    max = data[0];
    for(range = 1; range <= size; range++)
    {
        //printf("\n\n Range = %d", range);
        for(start = 0; start < size - range + 1; start ++)
        {
            //printf("\n  Start:%d", start);
            sum = 0;
            for(i = 0; i < range; i++)
            {
                sum = sum + data[start+i];
                //printf("  sum:%d", sum);
            }
            if(sum > max)
            {
                max = sum;
                //printf("  max = %d", max);
            }
        }
    }
    printf("%d", max);
    return 0;
}
