#include <stdio.h>

void foo()
{
    int a = 10;
    static int sa = 10;

    a += 5;
    sa += 5;

    printf("a = %d, sa = %d\n", a, sa);
}


int main()
{
    int i;

    for (i = 0; i < 10; ++i)
        foo();
        char str[100] = "November";
    printf("Length of String is %d\n", strlen(str));
    printf("Size of String is %d\n", sizeof(str));
}
