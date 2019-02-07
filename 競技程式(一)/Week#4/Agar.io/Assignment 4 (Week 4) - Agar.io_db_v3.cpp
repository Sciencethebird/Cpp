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

bool check(long long data[], long long start, long long sz)
{
    long long cnt = 0, sum;
    sum = start;
    //cout <<" ***Executing check function*** " << endl;
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
            cnt++;
            //cout << "sum(eaten) = " << sum <<" ";
            if(sum == 0)
            {
                return false;
            }
        }
    }
}

int main()
{
    static char a[1000000];
    char trans[15];

    long long data[100000];

    while(fgets(a, sizeof(a), stdin) != NULL)
    {
        cout << "input = " << a <<endl;

        int j = 0;
        long long sz = 0;
        long long len = strlen(a);
        for(long long i = 0; i< len; i++)
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
        long long start, lb = 0, hb = *max_element(data, data +sz), rng;
        int bk = 0, ac;
        //cout << "result = " << check(data, start, sz)<< endl;
        rng = (hb - lb)/4;
        cout << "\nrange" << rng;
        //mid = (lb+hb)/2;
        while(bk != 1)

        {
            //cout << "lb/hb = "<< lb <<" "<<hb << endl;
            cout <<"\n\n\n";
            printf("lb = %lli hb = %lli rng = %lli\n",lb, hb, rng );
            for(int l = 0; l < 4; l++)
            {
                cout <<check(data, lb + rng*l, sz) << " ";
            }
            cout << endl;
            for(int k = 0; k <= 4; k++)
            {
                //cout <<check(data, lb + rng*k, sz) << " ";
                if(rng  <= 1)
                {
                    bk = 1;
                    //cout <<"adfasdf";
                    break;
                }
                if(check(data, lb + rng*k, sz) == false && check(data, hb - rng*(3-k), sz) == true)
                {
                    lb = lb + rng*k;
                    hb = hb - rng*(3-k);

                    rng = (hb - lb)/4;

                    break;
                }
                if(check(data, lb + rng*k, sz) == true && check(data, hb - rng*(3-k), sz) == true){
                    break;
                }

                //printf("lb = %lli hb = %lli rng = %lli\n",lb, hb, rng );
            }
            printf("lb = %lli hb = %lli rng = %lli\n",lb, hb, rng );
            if(bk == 1)
            {
                for( ac = 0; ac <= hb - lb; ac++)
                {
                    //cout << "\nasdf asdfasdf = " << ac << endl;
                    cout <<check(data, lb + rng*ac, sz) << " ";
                    if(check(data, lb + ac, sz) == true && check(data, lb + ac + 1, sz) == true)
                    {
                        ac = -1;
                        break;
                    }
                    if(check(data, lb + ac, sz) == false && check(data, lb + ac + 1, sz) == true)
                    {
                        break;
                    }
                }
                break;
            }
        }
        //cout << "value of mid =" <<check(data, mid, sz) <<endl;
        /*if(len == 2){
            cout << "\nthe ans is " << data[0] << " boi"<< endl;
            continue;
        }*/
        cout << "\nthe ans is " << lb + ac +1 << " boiiii"<< endl;

    }
    return 0;
}
