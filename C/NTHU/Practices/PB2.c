#include <stdio.h>

int main()
{
    int *aPtr, a = 17;
    aPtr = &a;

    printf("Address of a : %p\n", &a);
    printf("Value of aPtr: %p\n", aPtr);
    printf("\n");

    printf("Address of aPtr : %p\n", &aPtr);
    printf("\n");

    printf("Value of a    : %d\n", a);
    printf("Value of *aPtr: %d\n", *aPtr);
    printf("\n");

    printf("&*aPtr: %p\n", &*aPtr);
    printf("*&aPtr: %p\n", *&aPtr);
    printf("\n");

    return 0;
}
