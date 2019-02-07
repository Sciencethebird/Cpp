#include<stdio.h>

int main()
{
    int i, j, shift;///A-Z=65-90; a-z=97-122
    char str[100] ;
    printf("Enter message to be encrypted: ");

    fgets(str, 100, stdin);


    printf("Enter shift amount (1-25): ");

    scanf("%d", &shift);

    for(i=0; i<100; i++)
    {
        if(str[i]>64 && str[i]<91)
        {
            str[i]=shift+str[i]-26;
            if(str[i]<65)
            {
                str[i]=str[i]+26;
            }
        }

        if(str[i]>96 && str[i]<123)
        {
            str[i]=shift+str[i]-26;
            if(str[i]<97)
            {
                str[i]=str[i]+26;
            }
        }
    }
    printf("Encrypted message: ");
    printf("%s",str);

    return 0;
}
