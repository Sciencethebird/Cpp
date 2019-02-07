#include<iostream>
#include<vector>
using namespace std;

bool findzero(vector<int> &lol)
{
    for(int i = 0; i< lol.size(); i++)
    {
        if(lol[i] == 0)
            return true;
    }
    return false;
}
int main()
{
    vector <vector<int> > data;
    vector <int> temp;
    int t, sz[3], sq[3][150];
    char trans[5];
    cin >> t;
    for(int k = 0; k < t; k++)
    {
        for(int i = 0; i < 3; i++)
        {
            cin >> sz[i];
            for (int j = 0; j< sz[i] ; j++)
            {
                cin >> trans;
                temp.push_back(atoi(trans));
            }
            data.push_back(temp);
            temp.clear();
        }
        for(int i = 0; i < 3; i++)
        {
            cin >> sq[i][110];
            for (int j = 0; j< sq[i][110] ; j++)
                cin >> sq[i][j];
        }
        for(int k = 0; k< 3; k++)
        {
            int last = data[k].size();
            for(int i = 0 ; i < last ; i++)
            {
                for(int j = i+1; j < last ; j++)
                {
                    if(data[k][j] == data[k][i])
                    {
                        data[k].erase(data[k].cbegin()+ j);
                        data[k].erase(data[k].cbegin()+ i);
                        i--;
                        break;
                    }
                }
                last = data[k].size();
            }
        }

        long round = 1;
        int pickid, t, seqid, i = 0, pick, nx;
        while(round < 100000)
        {
            nx  = (i+1)%3;
            seqid = (round - 1) % sq[i][110];
            t = data[nx].size();
            if(t == 0 || data[i].size() == 0 || data[(i+2)%3].size() == 0)
            {
                if(findzero(data[0]) == true)
                    cout << "Alice"<< endl;
                if(findzero(data[1]) == true)
                    cout << "Bob"<< endl;
                if(findzero(data[2]) == true)
                    cout << "Carol"<< endl;
                break;
            }
            pickid = (sq[i][seqid] + t - 1) % t;
            pick = data[nx][pickid];
            data[i].push_back(pick);
            for(int h = 0; h < data[i].size() - 1 ; h++)
            {
                if (data[i][h] == pick)
                {
                    data[i].erase(data[i].cbegin() + h);
                    data[i].erase(data[i].cend() - 1);
                    break;
                }
            }
            data[nx].erase(data[nx].cbegin() + pickid);
            i++;
            if(i > 2){
                i-=3;
                round ++;
            }
            if(round == 50000){
                cout << "Good Game" << endl;
                break;
            }
        }
        data.clear();
    }
    return 0;
}


