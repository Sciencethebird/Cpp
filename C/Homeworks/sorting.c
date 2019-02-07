#include<stdio.h>

void swap(int *aptr, int *bptr)///
{
    int temp;
    temp = *aptr;///用temp紀錄aptr 指向的數值
    *aptr=*bptr;
    *bptr= temp;

}
int sort(int array[], int size)
{
    int i, j;
    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(array[j]<array[i])
            {
                swap( &array[j], &array[i]);///輸入的是"位置"
            }
        }

    }
}

int main()
{

    int element[50],size=0, i, result[10][50], count=0;
    element[0]=0;
    printf("Enter the values in the list (-1 to end):\n");
    while(1)
    {
        scanf("%d", &element[size]);

        if(element[size]== -1)
        {
            break;
        }
        size++;
    }


    sort(element, size);

    printf("N count");
    for(i=0; i<size; i++)
    {
        count++;
        if(element[i+1]!=element[i])
        {
            printf("\n%-5d %-4d", element[i], count);
            count =0;
        }

    }

    return 0;
}
