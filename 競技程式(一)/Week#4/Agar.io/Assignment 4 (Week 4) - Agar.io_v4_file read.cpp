#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

bool check(long long data[], long long start, long long sz)
{
    long long cnt = 0, sum;
    sum = start;
    while(sum != 0)
    {
        if(cnt == sz)
        {
            return true;
            break;
        }
        if(sum == data[cnt])
        {
            cnt++;
            continue;
        }

        if(sum > data[cnt])
        {
            sum = sum + ceil(0.5*data[cnt]);
            cnt++;
            continue;
        }

        if(sum < data[cnt])
        {
            sum = sum * 0.5;
            cnt++;
            if(sum == 0)
            {
                return false;
            }
        }
    }
}

int main()
{

    FILE * fp;
    char a[1100000];
    char trans[15];
    long long data[100000];
    fp = fopen("testdata.txt", "r");
    while(fgets(a, 1100000, fp) != NULL)
    {
        int j = 0;
        long long sz = 0;
        int k = 1;
        cout << "string length = "<<strlen(a) << endl;
        long long lgn = strlen(a);
        for(long long i = 0; i< lgn; i++)
        {
            /*if(i == k * lgn/100){
                printf("%d%% done\n", k);
                k++;
            }*/
            if(a[i] == ' ' || a[i] == '\n')
            {
                data[sz] = atol(trans);
                sz++;
                j = 0;
                memset(trans, '\0', sizeof(trans)); ///this line is needed!!! or you will get elements for previous number
            }
            trans[j] = a[i];
            j++;
        }
        long long start, lb = *min_element(data, data+ sz), hb = *max_element(data, data +sz), rng;
        int bk = 0, ac;
        rng = (hb - lb)/4;

        while(bk != 1)

        {
            for(int k = 0; k <= 4; k++)
            {
               if(check(data, lb + rng*k, sz) == false && check(data, hb - rng*(3-k), sz) == true)
                {
                    lb = lb + rng*k;
                    hb = hb - rng*(3-k);

                    rng = (hb - lb)/4;
                    if(rng  <= 1)
                    {
                        bk = 1;

                        break;
                    }
                    break;
                }
            }
            if(bk == 1)
            {
                for( ac = 0; ac <= hb - lb; ac++)
                {
                    if(check(data, lb + ac, sz) == false && check(data, lb + ac + 1 , sz) == true)
                    {
                        break;
                    }
                }
                break;
            }
        }
        cout << lb + ac +1 << endl;
    }
    fclose(fp);
    exit(EXIT_SUCCESS);
    return 0;
}
