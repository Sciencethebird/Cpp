#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int main()
{

    int t, data[3][100], sq[3][150];
    char temp[5]; //, data[3][100];
    vector<vector <int> > people;
    cin >> t;
    for(int k = 0; k < t; k++)
    {
        for(int i = 0; i < 3; i++)
        {
            cin >> data[i][87];
            for (int j = 0; j< data[i][87] ; j++)
            {
                cin >> temp; ///cin read stuff before space
                data[i][j] = atoi(temp);
            }

        }
        for(int i = 0; i < 3; i++)
        {
            cin >> sq[i][110];
            for (int j = 0; j< sq[i][110] ; j++)
                cin >> sq[i][j];
        }

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
*/
