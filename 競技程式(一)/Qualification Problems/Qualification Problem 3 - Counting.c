#include<stdio.h>
#include<stdlib.h>
int main()
{
    char s[150];
    int  i, count1 = 0;
    scanf("%s", s);
    for(i = 0; i < strlen(s); i++)
    {
        if(s[i] == '1')
        {
            count1++;
        }
    }
    printf("%d %d", strlen(s) - count1, count1);
    return 0;
}
