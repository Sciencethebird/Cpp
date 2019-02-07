#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

void print2dvector(const vector<vector<int> > &s)
{
    for ( vector< vector<int>>::size_type i = s.size()-1; i != -1; i-- )///why != -1 ??????
    {
        for ( vector<int>::size_type j = 0; j < s[i].size(); j++ )
        {
            cout << s[i][j] << " ";
        }
        cout << std::endl;
    }
}
void clearline(vector<vector<int> > &s, int &start, int W)
{
    int cnt1 = 0;
    for(int i = 1; i< s.size(); i++ )
    {
        for(int j = 0; j < W; j++)
        {
            if(s[i][j] == 1)
            {
                cnt1++;
            }
            else
            {
                break;
            }
        }
        cout << i <<"th 1 count = " << cnt1  << endl;
        if(cnt1 == W)
        {
            cout << i << " th line clearing!!" << endl;
            s.erase(s.cbegin() + i);
            start --;
            i--;
        }
        cnt1 = 0;
    }
}

vector < vector<int> > pg;
vector <int> temp;
int main()
{
    int P, W, start = 1;

    cin >> P >> W;
    int vW = W-1;
    cout << "P = " << P <<" W = "<< W << endl;

    for(int i = 0; i < W ; i++)
    {
        temp.push_back(1);
    }
    pg.push_back(temp);
    temp.clear();

    for(int r = 0; r < P ; r++)
    {
        for(int s = 0; s < 4 ; s++)
        {

            for(int t = 0; t < W ; t++)
            {
                temp.push_back(0);
            }
            pg.push_back(temp);
            temp.clear();
        }
        //print2dvector(pg);
        char tpy;
        string mv;
        cin >> tpy;
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



//////////////// Blocks Interaction  //////////////////
        cout << "start = "<< start << endl;
        if(tpy == 'L')
        {
            if(vW - 1 - shift < 0)
            {
                shift = (vW - 1);
            }
            int hsft = 0;
            while(1)  /// collision detection
            {
                cout << "hsft = " << hsft;
                if(pg[start -1 - hsft][vW - shift] == 1)
                {
                    break;
                }
                if(pg[start -1 - hsft][vW - shift -1] == 1)
                {
                    break;
                }
                hsft ++;
            }
            cout << "L shift = " << shift << " hsft = " << hsft <<  endl;
            pg[start - hsft][vW - shift] = 1;
            pg[start - hsft][vW - shift -1] = 1;
            pg[start+1 - hsft][vW - shift -1] = 1;
            pg[start+2 - hsft][vW - shift -1] = 1;
            clearline(pg, start, W);
            pg.pop_back();
            start --;
        }
        if(tpy == 'J')
        {

            if(vW - 1 - shift < 0)
            {
                shift = (vW - 1);
            }
            int hsft = 0;
            while(1)  /// collision detection
            {
                if(pg[start -1 - hsft][vW - shift] == 1)
                {
                    break;
                }
                if(pg[start -1 - hsft][vW - shift -1] == 1)
                {
                    break;
                }
                hsft ++;
            }
            cout << "J shift = " << shift <<  endl;
            pg[start - hsft][vW - shift] = 1;
            pg[start+1 -hsft][vW - shift] = 1;
            pg[start+2 -hsft][vW - shift] = 1;
            pg[start -hsft][vW - shift -1] = 1;
            clearline(pg, start, W);
            pg.pop_back();
            start --;
        }
        if(tpy == 'O')
        {
            if(vW - 1 - shift < 0)
            {
                shift = (vW - 1);
            }
            int hsft = 0;
            while(1)  /// collision detection
            {
                if(pg[start -1 - hsft][vW - shift] == 1)
                {
                    break;
                }
                if(pg[start -1 - hsft][vW - shift -1] == 1)
                {
                    break;
                }
                hsft ++;
            }
            cout << "O shift = " << shift <<  endl;
            pg[start - hsft][vW - shift] = 1;
            pg[start - hsft][vW - shift -1] = 1;
            pg[start+1 - hsft][vW - shift ] = 1;
            pg[start+1 -hsft][vW - shift -1] = 1;
            clearline(pg, start, W);
            pg.pop_back();
            pg.pop_back();
            start -=2;
        }
        if(tpy == 'I')
        {

            int hsft = 0;
            while(1)  /// collision detection
            {
                cout <<"I loled" << hsft<< endl;
                if(pg[start-1 - hsft][vW - shift] == 1)
                {
                    break;
                }
                hsft ++;
            }
            cout << "I shift = " << shift <<  endl;
            pg[start - hsft][vW - shift] = 1;
            pg[start+1 - hsft][vW - shift] = 1;
            pg[start+2 - hsft][vW - shift] = 1;
            pg[start+3 - hsft][vW - shift] = 1;
        }
        if(tpy == 'Z')
        {
            if(vW - 2 - shift < 0) ///shift overflow detection
            {
                shift = (vW - 2);
            }
            int hsft = 0;
            while(1)  /// collision detection
            {
                if(pg[start -1 - hsft][vW - shift] == 1)
                {
                    break;
                }
                if(pg[start -1 - hsft][vW - shift - 1] == 1)
                {
                    break;
                }
                if(pg[start+1  -1 - hsft][vW - shift - 2] == 1)
                {
                    break;
                }
                hsft ++;
            }
            cout << "Z shift = " << shift <<  endl;
            pg[start - hsft][vW - shift] = 1;
            pg[start -hsft][vW - shift -1] = 1;
            pg[start+1 - hsft][vW - shift -1] = 1;
            pg[start+1 - hsft][vW - shift -2] = 1;
            clearline(pg, start, W);
            pg.pop_back(); /// clear excessive lines
            pg.pop_back();
            start -=2;
        }
        if(tpy == 'S')
        {
            if(vW - 2 - shift < 0)
            {
                shift = (vW - 2);
            }
            int hsft = 0;
            while(1)  /// collision detection
            {
                if(pg[start+1 -1 - hsft][vW - shift] == 1)
                {
                    break;
                }
                if(pg[start -1 - hsft][vW - shift - 1] == 1)
                {
                    break;
                }
                if(pg[start  -1 - hsft][vW - shift - 2] == 1)
                {
                    break;
                }
                hsft ++;
            }
            cout << "S shift = " << shift <<  endl;
            pg[start+1 - hsft][vW - shift] = 1;
            pg[start+1 -hsft][vW - shift -1] = 1;
            pg[start - hsft][vW - shift -1] = 1;
            pg[start - hsft][vW - shift -2] = 1;
            clearline(pg, start, W);
            pg.pop_back();
            pg.pop_back();
            start -=2;
        }
        if(tpy == 'T')
        {
            if(vW - 2 - shift < 0)
            {
                shift = (vW - 2);
            }
            int hsft = 0;
            while(1)  /// collision detection
            {
                if(pg[start+1 -1 - hsft][vW - shift] == 1)
                {
                    break;
                }
                if(pg[start - hsft][vW - shift - 1] == 1)
                {
                    break;
                }
                if(pg[start+1  -1 - hsft][vW - shift - 2] == 1)
                {
                    break;
                }
                hsft ++;
            }
            cout << "T shift = " << shift <<  endl;
            pg[start+1 - hsft][vW - shift] = 1;
            pg[start+1 - hsft][vW - shift -1] = 1;
            pg[start+1 - hsft][vW - shift -2] = 1;
            pg[start -hsft][vW - shift -1] = 1;
            clearline(pg, start, W);
            pg.pop_back();
            pg.pop_back();
            start -=2;
        }
        cout << "before" << endl;
        print2dvector(pg);

        clearline(pg, start, W);
        start += 4;
        cout << "after" << endl;
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
