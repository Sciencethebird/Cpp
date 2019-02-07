#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
bool check(long long data[], long long start, long long zz)
{
    long long sum =start;
    for(long long cnt = 0; cnt<=zz; cnt++)
    {
        if(sum > data[cnt])
        {
            sum +=  ceil(0.5*data[cnt]);
            continue;
        }
        if(sum < data[cnt])
        {
            sum *= 0.5;
            if(sum == 0)
                return false;
        }
    }
    return true;
}
int main()
{
    char a[1100000], trans[20];
    long long data[100500];
    while(fgets(a, 1100000, stdin) != NULL)
    {
        int j = 0;
        long long sz = 0, len = strlen(a);
        for(long long i = 0; i < len ; i++)
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
        long long lb = 0, hb = *max_element(data, data + sz), mid = hb*0.5;
        //cout << hb << " max boiii " << endl;
        while(hb > lb+1)
        {
            bool coml = check(data, lb, sz), comh = check(data, hb, sz), comm = check(data, mid, sz);
            cout << "lb = " << lb << " hb = " << hb << endl;
            cout <<"T/F " << coml << endl;
            if(comm == false && comh == true)
            {
                cout << "bigger is true " << comm  << " " << comh << endl;
                lb = mid;
                mid = (hb + lb)*0.5;
                continue;
            }
            else
            {
                cout << "smaller is true " << coml  << " " << comm << endl;
                hb = mid;
                mid = (hb + lb)*0.5;
                continue;
            }
        }
        memset(data, '\n', 100500);
    }
    return 0;
}
