#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char s[] = "Speech is si1ver, silence is gold.";
    char t[] = " ";
    int data[10], i = 0, size = 0;


    static char buf[40];
    fgets(buf, sizeof(buf), stdin);
    printf("input = %s", buf);
    char *test = strtok(buf, " ");

    while (test != NULL)
    {
        printf("%s\n", test);
        data[size] = atoi (test);
        test = strtok(NULL, " ");
        printf("\!!!!%d\n", data[size]);
        size++;
    }
    for(i = 0; i<size; i++){
        printf("%d size:%d  ", data[i], size);
    }
    return 0;
}
