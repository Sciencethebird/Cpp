#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>

///1234 26 3456 85678 4 324523 4333
using namespace std;
int main()
{
    static char a[1000000];
    char trans[10];

    long long data[100000];

    while(fgets(a, sizeof(a), stdin) != NULL)
    {
        //cout << "input = " << a <<endl;

        int j = 0, sz=0 ;

        for(long i = 0; i<strlen(a); i++)
        {
            if(a[i] == ' ' || a[i] == '\n')
            {
                data[sz] = atoll(trans);
                sz++;
                j = 0;
                memset(trans, '\0', sizeof(trans)); ///this line is needed!!! or you will get elements for previous number
            }
            trans[j] = a[i];
            j++;
        }


        long long start, sum, last = 0;
        //start = *max_element(data, data+sz);
        //cout << "max element " << start;
        start = 0;
        sum = start;

        while(last != sz)
        {
            //cout << "last = " << last << " ";
            if(sum == data[last])
            {
                last++;
                continue;
            }

            if(sum > data[last])
            {
                sum = sum + ceil(0.5*data[last]);
                last++;
                //cout << "sum(eat) = " << sum << " ";
                continue;
            }

            if(sum < data[last])
            {
                sum = sum * 0.5;
                //cout << "sum(eaten) = " << sum <<" ";
                last ++;
                if(sum == 0)
                {
                    start++;
                    sum = start;
                    //cout << "start = " << start << endl;
                    last = 0;
                }

            }
        }
        cout << start << endl;

    }
    return 0;
}
