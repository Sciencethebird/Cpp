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
        if(cnt == sz+1)
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
            sum +=  ceil(0.5*data[cnt]);
            cnt++;
            continue;
        }
        if(sum < data[cnt])
        {
            sum *= 0.5;
            cnt++;
            if(sum == 0)
                return false;
        }
    }
}
int main()
{
    char a[1100000], trans[20];
    long long data[100500];
    while(fgets(a, 1100000, stdin) != NULL)
    {
        int j = 0;
        long long sz = 0, len = strlen(a);
        for(long long i = 0; i<len ; i++)
        {
            if(a[i] == ' ' || a[i] == '\n')
            {
                data[sz] = atoll(trans);
                sz++;
                j = 0;
                memset(trans, '\0', 20);
            }
            trans[j] = a[i];
            j++;
        }
        long long start, lb = 0, hb = *max_element(data, data + sz), rng;
        int bk = 0, ac;
        rng = (hb - lb)*0.25;
        while(bk != 1)
        {
            for(int k = 0; k < 4; k++)
            {
                bool com1 = check(data, lb + rng*k, sz), com2 = check(data, hb - rng*(3-k), sz);
                if(rng  <= 1)
                {
                    bk = 1;
                    break;
                }
                if(com1 == false && com2 == true)
                {
                    lb += rng*k;
                    hb -= rng*(3-k);
                    rng = (hb - lb)*0.25;
                    break;
                }
            }
            if(bk == 1)
            {
                for( ac = 0; ac < hb - lb; ac++)
                {
                    bool com1 = check(data, lb + ac, sz), com2 = check(data, lb + ac + 1, sz);
                    if(com1 == false && com2 == true)
                        break;
                }
                break;
            }
        }
        cout << lb + ac + 1 << endl;
    }
    return 0;
}
