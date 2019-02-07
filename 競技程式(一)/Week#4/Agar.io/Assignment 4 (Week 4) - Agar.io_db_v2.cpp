#include<iostream>
#include<string.h>
#include<vector>
#include<math.h>
#include<algorithm>
/*
42 40 35 68 46 97 58 87 105 54
98 50 101 91 31 16 63 53 72 35
40 96 10 15 104 42 99 109 86 21
40 74 97 89 127 37 10 95 102 116
103 71 42 32 34 99 113 4 120 58
49 114 59 6 54 46 80 54 32 113
50 109 98 103 109 1 68 49 36 124
98 100 11 31 44 9 109 90 100 27
39 85 35 12 43 107 83 64 127 41
54 15 59 84 94 72 15 96 51 41
*/
using namespace std;

bool check(long long data[], int start, int sz)
{
    long long cnt = 0, sum;
    sum = start;
    cout <<" ***Executing check function*** " << endl;
    while(sum != 0)
    {
        //cout << "cnt =  " << cnt << " ";
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
            //cout << "sum(eat) = " << sum << " ";
            continue;
        }

        if(sum < data[cnt])
        {
            sum = sum * 0.5;
            //cout << "sum(eaten) = " << sum <<" ";
            if(sum == 0)
            {
                return false;
                break;
            }
        }
    }
}

int main()
{
    static char a[1000000];
    char trans[10];

    long long data[100000];

    while(fgets(a, sizeof(a), stdin) != NULL)
    {
        cout << "input = " << a <<endl;

        int j = 0;
        long long sz = 0;

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
        long long start, lb = *min_element(data, data+ sz), hb = *max_element(data, data +sz), rng, mid;

        cout << "result = " << check(data, start, sz)<< endl;
        rng = (hb - lb)/4;
        mid = (lb+hb)/2;
        while(hb - lb >2)
        {

            hb = mid + rng;
            lb = mid - rng;
            printf("\n\n\nhb = %lli, lb = %lli, mid = %lli", hb, lb, mid);
            if(check(data, lb, sz) == false && check(data, hb, sz) == false)
            {
                mid = hb;
                if(rng > 4)
                {
                    rng /= 4;
                }
                else
                {
                    rng = 1;
                }
                cout << "mid(ff) = " << mid <<"range = " << rng <<endl;
                continue;
            }
            if(check(data, lb, sz) == true)
            {
                mid = lb;
                if(rng > 4)
                {
                    rng /= 4;
                }
                else
                {
                    rng = 1;
                }
                cout << "mid(lb) = " << mid <<"range = " << rng <<endl;
                continue;
            }
            if(check(data, lb, sz) != true)
            {
                mid = hb;
                if(rng > 4)
                {
                    rng /= 4;
                }
                else
                {
                    rng = 1;
                }

                cout << "mid(hb) = " << mid <<"range = " << rng <<endl;
                continue;
            }

            else
            {
                cout << "error" <<endl;
            }

        }
        cout << "value of mid =" <<check(data, mid, sz) <<endl;
        cout << "the ans is " << mid << " boiiii"<< endl;



    }
    return 0;
}
