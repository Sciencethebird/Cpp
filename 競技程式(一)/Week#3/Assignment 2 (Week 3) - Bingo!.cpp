#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    static char a[550];
    long long data[50][50], req[2500];
    int q = 2;

    while(fgets(a, sizeof(a), stdin) != NULL)
    {
        int row[50] = {}, col[50] = {}, rowc, colc;
        int sz, k, i, j, di = 0, dj = 0, ri = 0, halt = 0;
        sz = (strlen(a)-1)/ 10;

        for(k = 1; k <= 2*sz + q ; k++)
        {
            fgets(a, sizeof(a), stdin);
            if ( a[2] == ' ')
            {
                continue;
            }
            if(a[0] == '+')
            {
                continue;
            }
            if(a[0] == '|')
            {
                int start;
                char cpy[10];
                for(start = 1; start < sz*10 ; start = start +10)
                {
                    for(i = 0; i<9; i++)
                    {
                        cpy[i] = a[start +i];
                    }
                    data[di][dj] = atoll(cpy);
                    dj++;
                }
                dj = 0;
                di++;
            }
        }
        q = 1;
        ri = 0;
        while(1)
        {
            if(fgets(a, sizeof(a), stdin) == NULL)
            {
                halt = 1;
                break;
            }
            if(a[0] == '+')
            {
                break;
            }
            req[ri] = atoll(a);
            ri++;
        }
        rowc = 0;
        colc = 0;
        int lol = 0;
        for(k = 0; k<ri ; k++)
        {
            for( i = 0; i < sz; i++)
            {
                for( j = 0; j < sz; j++)
                {
                    if(req[k] == data[i][j])
                    {
                        row[i] = row[i] + 1;
                        col[j] = col[j] + 1;
                        if(row[i] == sz)
                        {
                            rowc = rowc +1;
                        }
                        if(col[j] == sz)
                        {
                            colc = colc +1;
                        }
                        lol++;
                        printf("%d %d\n",rowc, colc);
                    }

                }
            }
        }
        if(halt == 1)
        {
            return 0;
        }
    }
    return 0;
}
