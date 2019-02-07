#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
    FILE *f = fopen("file.txt", "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    /* print some text */
    /*const char *text = "Write this to the file";
    fprintf(f, "Some text: %s\n", text);*/

    for(long long i = 0; i<120000; i++){
        fprintf(f, "%lli ", i);
    }

    fclose(f);;
}
