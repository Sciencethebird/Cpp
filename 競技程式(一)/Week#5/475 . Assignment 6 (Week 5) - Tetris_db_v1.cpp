#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

void print2dvector(const vector<vector<char> > &s)
{
    for ( vector< vector<char>>::size_type i = s.size()-1; i != -1; i-- )///why != -1 ??????
    {
        for ( vector<char>::size_type j = 0; j < s[i].size(); j++ )
        {
            cout << s[i][j] << " ";
        }
        cout << std::endl;
    }
}

vector < vector<char> > pg;
vector <char> temp;
int main()
{
    int P, W, start = 1;

    cin >> P >> W;
    int vW = W-1;
    cout << "P = " << P <<" W = "<< W << endl;

    for(int i = 0; i<W ; i++){
        temp.push_back('B');
    }
    pg.push_back(temp);
    temp.clear();

    for(int r = 0; r < P ; r++)
    {
        cout << "lol";
        for(int s = 0; s < 4 ; s++)
        {
            for(int t = 0; t < W ; t++)
            {
                temp.push_back('x');
            }

            pg.push_back(temp);
            temp.clear();
        }
        //print2dvector(pg);
        char tpy;
        string mv;
        cin >> tpy;
        cout <<"Input Char = " << tpy << endl;

        cin.ignore();///getline will continue to read immediately after cin
        ///So your getline will get nothing
        ///cin.ignore() will clear the buffer until change line.

        getline(cin, mv);
        int shift = 0;
        for(int i = 0; i < mv.length(); i++)
        {
            if(mv[i] == '<')
            {
                shift++;
            }
            if(mv[i] == '>')
            {
                shift--;
            }
        }
        if(shift < 0)
        {
            shift = 0;
        }
        if(shift > W)
        {
            shift = W;
        }
        cout <<"Left Shift Amount = " << shift << endl;
        if(tpy == 'L')
        {
            if(vW - 1 - shift < 0)
            {
                shift = (vW - 1);
            }
            cout << "L shift = " << shift <<  endl;
            pg[start][vW - shift] = 'L';
            pg[start][vW - shift -1] = 'L';
            pg[start+1][vW - shift -1] = 'L';
            pg[start+2][vW - shift -1] = 'L';

            pg.pop_back();
            start --;

        }
        if(tpy == 'J')
        {
            if(vW - 1 - shift < 0)
            {
                shift = (vW - 1);
            }
            cout << "J shift = " << shift <<  endl;
            pg[start][vW - shift] = 'J';
            pg[start+1][vW - shift] = 'J';
            pg[start+2][vW - shift] = 'J';
            pg[start][vW - shift -1] = 'J';
            pg.pop_back();
            start --;
        }
        if(tpy == 'O')
        {
            if(vW - 1 - shift < 0)
            {
                shift = (vW - 1);
            }
            cout << "O shift = " << shift <<  endl;
            pg[start][vW - shift] = 'O';
            pg[start][vW - shift -1] = 'O';
            pg[start+1][vW - shift ] = 'O';
            pg[start+1][vW - shift -1] = 'O';
            pg.pop_back();
            pg.pop_back();
            start -=2;
        }
        if(tpy == 'I')
        {
            cout << "I shift = " << shift <<  endl;
            pg[start][vW - shift] = 'I';
            pg[start+1][vW - shift] = 'I';
            pg[start+2][vW - shift] = 'I';
            pg[start+3][vW - shift] = 'I';
        }
        if(tpy == 'Z')
        {
            if(vW - 2 - shift < 0)
            {
                shift = (vW - 2);
            }
            cout << "Z shift = " << shift <<  endl;
            pg[start][vW - shift] = 'Z';
            pg[start][vW - shift -1] = 'Z';
            pg[start+1][vW - shift -1] = 'Z';
            pg[start+1][vW - shift -2] = 'Z';
            pg.pop_back();
            pg.pop_back();
            start -= 2;
        }
        if(tpy == 'S')
        {
            if(vW - 2 - shift < 0)
            {
                shift = (vW - 2);
            }
            cout << "S shift = " << shift <<  endl;
            pg[start+1][vW - shift] = 'S';
            pg[start+1][vW - shift -1] = 'S';
            pg[start][vW - shift -1] = 'S';
            pg[start][vW - shift -2] = 'S';
            pg.pop_back();
            pg.pop_back();
            start -= 2;
        }
        if(tpy == 'T')
        {
            if(vW - 2 - shift < 0)
            {
                shift = (vW - 2);
            }
            cout << "T shift = " << shift <<  endl;
            pg[start+1][vW - shift] = 'T';
            pg[start+1][vW - shift -1] = 'T';
            pg[start+1][vW - shift -2] = 'T';
            pg[start][vW - shift -1] = 'T';
            pg.pop_back();
            pg.pop_back();
            start -= 2;
        }
        start += 4;
        print2dvector(pg);
    }
    /*
    7 3
    L
    >
    J
    <<
    O
    <>
    I
    <<
    Z
    <>>>
    S
    ><><<
    T
    >><<<


    */
    return 0;
}
