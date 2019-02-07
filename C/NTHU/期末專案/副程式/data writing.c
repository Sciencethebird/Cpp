#include <stdio.h>

int main()
{
    FILE *fin;
    int a, b, c;

    fin = fopen("trainingData.txt","r");
    if(NULL==fin){
        printf("File not found!!\n");
        return 0;
    }

    fscanf(fin, "%d %d %d", &a, &b, &c);
    printf("a + b + c is %d\n", a+b+c);

    fclose(fin);

    return 0;
}

/*#include <stdio.h>

int main()
{
    FILE *fPtr;

    fPtr = fopen("test.txt","w");
    fprintf(fPtr, "Hello World!!\n");
    fclose(fPtr);

    return 0;
}*/
