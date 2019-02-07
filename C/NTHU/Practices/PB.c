#include<stdio.h>
#include <string.h>

void comp ( char  a[150], char b[150], int La, char cut[150])
{
    int i, count, countmax=0, lenb=0;
    for(lenb=1; lenb<=La; lenb++)
    {
        count=0;
        for(i=0; i<lenb; i++)
        {
            if(a[La-lenb+i]== b[i])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        if(count>countmax)
        {
            countmax=count;
        }
    }
    for(i=0; i<countmax; i++)
    {
        cut[i]=b[i];
    }
    cut[countmax]='\0';
}

int a, i, c ;
char name1[150], name2[150], name3[150], cut1[150],cut2[150];

int main()
{
    scanf("%d", &a);
    for(c=1; c<=a; c++)
    {
        scanf("%s %s %s", name1, name2, name3);
        comp(name1, name2, strlen(name1),cut1);
        comp(name2, name3, strlen(name2),cut2);
        printf("%s...%s\n",cut1, cut2);
    }
    return 0;
}
