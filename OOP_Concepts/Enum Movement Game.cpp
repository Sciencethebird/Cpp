#include<iostream>
using namespace std;

enum coordinate {x, y}; ///coordinate is like a variable type

template <class T, int N>
void printmap(T Map[N][N])
{

    for(int i = 0; i<N; i++)
    {
        for(int j= 0; j< N; j++)
        {
            cout << Map[i][j] << " ";
        }
        cout << endl;
    }

}
int main()
{

    char Map[20][20];


    for(int i = 0; i<20; i++)
    {

        for(int j= 0; j< 20; j++)
        {
            Map[i][j] = '.';
        }
    }
    char M;
    int position[2] = {0, 0};
    while( 1 )
    {
        cin >> M;

        if(M == 'a')
        {
            position[0] -= 1;
            position[y] = position[y];
        }
        if(M == 's')
        {
            position[x] = position[x];
            position[y] +=1;

        }
        if(M == 'd')
        {
            position[x] +=1;
            position[y] = position[y];

        }
        if(M == 'w')
        {
            position[x] = position[x];
            position[y] -= 1;
        }
        Map[position[y]][position[x]] = '#';
        printmap(Map);
    }


    return 0;
}
