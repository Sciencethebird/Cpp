#include<iostream>
#include<string>
using namespace std;

int* failure(string &in)
{
    int* f = new int[1000];
    int n = in.length();
    f[0] = 0;
    int len = 0;
    int i = 1;
    while(i < n)
    {
        if(in[i] == in[len])
        {
            len++;
            f[i] = len;
            i++;
        }
        else
        {
            if(len>0)
            {
                len = f[len - 1];
            }
            else
            {
                f[i] = 0;
                i++;
            }
        }
    }
    for(int i = 0; i<n;i++){
        f[i] -=1;
    }
    return f;
}
int main()
{
    string in;
    cout << "Enter string to search:  "<< endl;
    cin >> in;
    cout << in;
    int* fptr = failure(in);
    for(int i = 0; i< in.length(); i++)
    {
        cout << fptr[i]<<  " ";
    }

    return 0;
}
/*
apple is good,//0
eat apple everyday \0
*/
