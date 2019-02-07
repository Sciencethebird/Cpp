#include<iostream>
#include<vector>
using namespace std;

void printvector(const vector<int> &s)
{
    vector<int>::const_iterator i;
    for(i = s.cbegin(); i != s.cend(); i++)
        cout << *i << " ";
    cout << endl;
}
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
    char trans[5]; //, data[3][100];
    cin >> t;
    for(int k = 0; k < t; k++)
    {
        for(int i = 0; i < 3; i++)
        {
            cin >> sz[i];
            for (int j = 0; j< sz[i] ; j++)
            {
                cin >> trans; ///cin read stuff before space
                temp.push_back(atoi(trans));
            }
            data.push_back(temp);
            temp.clear();
        }

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j <sz[i]; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
        for(int i = 0; i < 3; i++)
        {
            cin >> sq[i][110];
            for (int j = 0; j< sq[i][110] ; j++)
                cin >> sq[i][j];
        }

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j <sq[i][110]; j++)
            {
                cout << sq[i][j] << " ";
            }
            cout << endl;
        }



        cout << endl;

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
            printvector(data[k]);
        }

        cout << endl;
        long round = 1;
        int pickid, t, seqid, i = 0, pick, nx;
        while(round < 100000)
        {

            nx  = (i+1)%3;
            cout << "round = " << round << endl;
            printvector(data[0]);
            printvector(data[1]);
            printvector(data[2]);

            seqid = (round - 1) % sq[i][110];
            cout <<"secret sequence number = " << sq[i][seqid] << endl;

            t = data[nx].size();
            cout << "lololololol    " <<  t <<  endl;
            pickid = (sq[i][seqid] + t - 1) % t; ///+1-1 is removed

            pick = data[nx][pickid];
            cout <<  pickid <<"th in data is picked = " << pick << endl;

            ///add new card into data[i]
            data[i].push_back(pick);
            printvector(data[i]);

            cout << "removing duplicates" << endl;
            for(int h = 0; h < data[i].size() - 1 ; h++)
            {
                if (data[i][h] == pick)
                {
                    data[i].erase(data[i].cbegin() + h);
                    data[i].erase(data[i].cend() - 1);
                    break;
                }
            }
            cout << "after = ";
            printvector(data[i]);

            ///remove card from data[i+1]
            data[nx].erase(data[nx].cbegin() + pickid);

            cout << endl;
            if(data[nx].size() == 0 || data[i].size() == 0 || data[(i+2)%3].size() == 0 )
            {

                if(findzero(data[0]) == true)
                    cout << "Alice"<< endl;
                if(findzero(data[1]) == true)
                    cout << "Bob"<< endl;
                if(findzero(data[2]) == true)
                    cout << "Carol"<< endl;
                break;

            }
            i ++;
            if(i > 2){
                i-=3;
                round ++;
            }
            if(round == 20){
                cout << " GG " << endl;
                break;
            }
            cout <<endl <<endl;
        }
        data.clear();
    }

    return 0;
}
/*
1
1 5
2 6 6
3 8 9 3

4
18 7D 11H 5C 2D 5D 3D 6H 9D 2H 3H 10C 11S 10H 6C 7C 1D 1C J
18 7S 9H 10S 8S 8D 8H 7H 6D 4S 11C 13C 4H 4D 13D 1S 12H 4C 12S
17 3S 11D 9C 6S 5H 13H 12D 2C 1H 5S 2S 9S 10D 13S 3C 8C 12C
2 1 1
3 3 2 2
2 1 2
18 2C 8H 2H 9S 6S 10S 4D 9D 11S 3H 9H 3D 12H 12C 13D 11C 7S 10H
18 8C 4C 2D 6D 13C 8D 1C 12S 13H J 10D 11H 5D 3C 11D 10C 1D 2S
17 7H 7C 5C 4H 1S 6C 5S 4S 9C 3S 7D 1H 12D 6H 13S 8S 5H
29 1 1 4 1 2 2 3 1 3 4 3 3 2 1 1 3 4 3 3 3 3 2 4 4 4 1 1 1 2
5 3 2 3 2 3
10 4 4 1 3 2 3 3 3 2 3
17 4S 7C 1C 10C 11D 7S 7H 12D 13S J 1S 4C 6D 12S 13D 1H 2H
18 8C 9S 13C 5C 10D 8H 2D 6H 11S 3H 8S 2C 1D 3S 13H 2S 8D 5D
18 10S 3D 12H 7D 6S 11H 10H 3C 4H 4D 5S 6C 9D 5H 9H 12C 11C 9C
48 1 2 2 2 2 2 1 2 2 1 1 1 1 2 2 2 1 1 2 1 2 1 2 1 1 2 2 2 2 1 1 1 1 1 2 1 2 2 1 2 2 2 2 2 2 1 2 1
5 2 2 2 1 1
4 2 1 1 2
18 12C 8S 3H 1C 8H 9C 6H 4S 7D 13S 5S 3C 9S 6S 3D 11D 1S 6D
17 7H 6C 1H 8D 2H 8C 12D 2D 5H 7C 2S 11S 12S 13H J 10S 13C
18 2C 3S 4H 12H 9H 11H 7S 10H 5D 4D 11C 13D 9D 4C 1D 10C 5C 10D
1 1
1 1
1 1


1
18 1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 5 5
17 10 10 10 10 11 11 11 11 12 12 12 12 13 13 13 13 0
18 5 5 6 6 6 6 7 7 7 7 8 8 8 8 9 9 9 9
1 1
1 1
1 1
*/
