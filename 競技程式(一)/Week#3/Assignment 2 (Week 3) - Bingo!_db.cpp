#include<iostream>
#include<string.h>

using namespace std;

/*
    Problems Encountered (WA): array size too small
*/

/*
+-----------------------------------------------------------+
|         B         i         N         G         o         |
+---------+---------+---------+---------+---------+---------+
|024979444|861648771|623690080|433933446|476190628|262703496|
+---------+---------+---------+---------+---------+---------+
|211047201|971407774|628894324|731963981|822804783|450968416|
+---------+---------+---------+---------+---------+---------+
|430302155|982631931|161735901|880895727|923078536|707723856|
+---------+---------+---------+---------+---------+---------+
|189330738|910286917|802329210|404539678|303238505|317063339|
+---------+---------+---------+---------+---------+---------+
|492686567|773361867|125660015|650287939|839296262|462224592|
+---------+---------+---------+---------+---------+---------+
|492601448|384836990|191890309|576823354|782177067|404011430|
+---------+---------+---------+---------+---------+---------+
404539678
404011430
433933446
24979444
923078536
125660015
191890309
839296262
450968416
822804783
650287939
628894324
707723856
773361867
861648771
982631931
492601448
492686567
910286917
462224592
384836990
623690080
317063339
782177067
262703496
971407774
430302155
476190628
576823354
880895727
161735901
189330738
211047201
731963981
802329210
303238505
*/

int printA(long long a[50][50], int siz)
{
    int i, j;
    for( i = 0; i < siz; i++)
    {
        for( j = 0; j < siz; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    static char a[550], b[10];
    long long data[50][50], req[2500];
    int q = 2; ///q is a special operator I came up with!
               ///

    while(fgets(a, sizeof(a), stdin) != NULL)
    {
        int row[50] = {}, col[50] = {}, rowc, colc; /// clear raw[], col[], is necessary!!
        int sz, k, i, j, di = 0, dj = 0, ri = 0, halt = 0;
        sz = (strlen(a)-1)/ 10;

        for(k = 1; k <= 2*sz + q ; k++)
        {
            fgets(a, sizeof(a), stdin);
            if ( a[2] == ' ')
            {
                cout <<"\n\nbingo line is ignored\n\n";
                continue;  /// ignore the b i n g o line
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


        printA(data, sz);
        for(i = 0; i<ri; i++){
            cout <<"\nreq data = " << req[i];
        }
        int resultc = 0;
        rowc = 0;
        colc = 0;
        for(k = 0; k<ri ; k++)
        {
            printf("\n\n!!!!!!!!!req data = %lli\n\n", req[k]);
            for( i = 0; i < sz; i++)
            {
                for( j = 0; j < sz; j++)
                {
                    if(req[k] == data[i][j])
                    {
                        resultc ++;
                        data[i][j] = 111111111;
                        //cout <<  "\n\n\nNumber = "<< resultc <<"\n\n"<<"row = "<<"\n";

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
                        printf("\n\nresult %d (row/col) = %d %d\n\n",resultc, rowc, colc);
                        int m;
                        for(m = 0; m < sz; m++)
                        {
                            printf("%d\n", row[m]);
                        }
                        cout << "\n\n col=";
                        for(m = 0; m < sz; m++)
                        {
                            printf("%d ", col[m]);
                        }
                        cout << "\n\n";

                        printA(data, sz);
                    }
                }
            }
        }

        cout << "\n\ncode not done yet i am fucked lol\n\n";

        if(halt == 1)
        {
            return 0;
        }
    }
    return 0;
}
