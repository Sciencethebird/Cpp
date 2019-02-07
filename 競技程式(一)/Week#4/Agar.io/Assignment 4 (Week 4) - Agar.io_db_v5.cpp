#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
    char a[1100000], trans[15];
    long long data[100000];
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
                memset(trans, '\0', 15);
            }
            trans[j] = a[i];
            j++;
        }
        long long start, sum, last = 0;
        start = 0;
        sum = start;
        while(last != sz)
        {
            if(sum == data[last])
            {
                last++;
                continue;
            }
            if(sum > data[last])
            {
                sum += ceil(0.5*data[last]);
                last++;
                continue;
            }
            if(sum < data[last])
            {
                sum = sum * 0.5;
                last ++;
                if(sum == 0)
                {
                    start++;
                    sum = start;
                    last = 0;
                }
            }
        }
        cout << start << endl;
    }
    return 0;
}
