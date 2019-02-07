#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
void clearline(vector<vector<int> > &s, int &start, int W)
{
    int cnt1 = 0, cnt0 = 0;
    for(int i = 1; i< s.size(); i++ )
    {
        for(int j = 0; j < W; j++)
        {
            if(s[i][j] == 1)
                cnt1++;
            else
                cnt0++;
        }
        if(cnt1 == W)
        {
            s.erase(s.cbegin() + i);
            start --;
            i--;
        }
        if(cnt0 == W)
        {
            s.erase(s.cbegin() + i);
            start --;
            i--;
        }
        cnt0 = 0;
        cnt1 = 0;
    }
}

int shiftf(string mv,  int ofst, int W)
{
    int shift = 0;
    for(int i = 0; i < mv.length(); i++)
    {
        if(mv[i] == '<')
        {
            shift++;
            if(shift + ofst > W)
                shift = W - ofst;
        }
        if(mv[i] == '>')
        {
            shift--;
            if(shift < 0)
                shift = 0;
        }
    }
    return shift;
}

vector < vector<int> > pg;
vector <int> temp;

int main()
{
    int P, W, start = 1;
    cin >> P >> W;
    int vW = W-1;
    for(int i = 0; i < W ; i++)
        temp.push_back(1);

    pg.push_back(temp);
    temp.clear();
    for(int r = 0; r < P ; r++)
    {
        for(int s = 0; s < 4 ; s++)
        {
            for(int t = 0; t < W ; t++)
                temp.push_back(0);
            pg.push_back(temp);
            temp.clear();
        }
        char tpy;
        string mv;
        cin >> tpy;
        cin.ignore();
        getline(cin, mv);
        int shift;
        if(tpy == 'L')
        {
            shift = shiftf(mv, 2, W);
            int hsft = 0;
            while(1)
            {
                if(pg[start-1 - hsft][vW - shift] == 1)
                    break;
                if(pg[start -1 - hsft][vW - shift -1] == 1)
                    break;
                hsft ++;
            }
            pg[start - hsft][vW - shift] = 1;
            pg[start - hsft][vW - shift -1] = 1;
            pg[start+1 - hsft][vW - shift -1] = 1;
            pg[start+2 - hsft][vW - shift -1] = 1;
            pg.pop_back();
            start --;
        }
        if(tpy == 'J')
        {
            shift = shiftf(mv, 2, W);
            int hsft = 0;
            while(1)
            {
                if(pg[start -1 - hsft][vW - shift] == 1)
                    break;
                if(pg[start -1 - hsft][vW - shift -1] == 1)
                    break;
                hsft ++;
            }
            pg[start - hsft][vW - shift] = 1;
            pg[start+1 -hsft][vW - shift] = 1;
            pg[start+2 -hsft][vW - shift] = 1;
            pg[start -hsft][vW - shift -1] = 1;
            pg.pop_back();
            start --;
        }
        if(tpy == 'O')
        {
            shift = shiftf(mv, 2, W);
            int hsft = 0;
            while(1)
            {
                if(pg[start -1 - hsft][vW - shift] == 1)
                    break;
                if(pg[start -1 - hsft][vW - shift -1] == 1)
                    break;
                hsft ++;
            }
            pg[start - hsft][vW - shift] = 1;
            pg[start - hsft][vW - shift -1] = 1;
            pg[start+1 - hsft][vW - shift ] = 1;
            pg[start+1 -hsft][vW - shift -1] = 1;
            pg.pop_back();
            pg.pop_back();
            start -=2;
        }
        if(tpy == 'I')
        {
            shift = shiftf(mv, 1, W);
            int hsft = 0;
            while(1)
            {
                if(pg[start-1 - hsft][vW - shift] == 1)
                    break;
                hsft ++;
            }
            pg[start - hsft][vW - shift] = 1;
            pg[start+1 - hsft][vW - shift] = 1;
            pg[start+2 - hsft][vW - shift] = 1;
            pg[start+3 - hsft][vW - shift] = 1;
        }
        if(tpy == 'Z')
        {
            shift = shiftf(mv, 3, W);
            int hsft = 0;
            while(1)
            {
                if(pg[start -1 - hsft][vW - shift] == 1)
                    break;
                if(pg[start -1 - hsft][vW - shift - 1] == 1)
                    break;
                if(pg[start+1  -1 - hsft][vW - shift - 2] == 1)
                    break;
                hsft ++;
            }
            pg[start - hsft][vW - shift] = 1;
            pg[start -hsft][vW - shift -1] = 1;
            pg[start+1 - hsft][vW - shift -1] = 1;
            pg[start+1 - hsft][vW - shift -2] = 1;
            pg.pop_back();
            pg.pop_back();
            start -=2;
        }
        if(tpy == 'S')
        {
            shift = shiftf(mv, 3, W);
            int hsft = 0;
            while(1)
            {
                if(pg[start+1 -1 - hsft][vW - shift] == 1)
                    break;
                if(pg[start-1 - hsft][vW - shift - 1] == 1)
                    break;
                if(pg[start-1 - hsft][vW - shift - 2] == 1)
                    break;
                hsft ++;
            }
            pg[start+1 - hsft][vW - shift] = 1;
            pg[start+1 -hsft][vW - shift -1] = 1;
            pg[start - hsft][vW - shift -1] = 1;
            pg[start - hsft][vW - shift -2] = 1;
            pg.pop_back();
            pg.pop_back();
            start -=2;
        }
        if(tpy == 'T')
        {
            shift = shiftf(mv, 3, W);
            int hsft = 0;
            while(1)
            {
                if(pg[start+1 -1 - hsft][vW - shift] == 1)
                    break;
                if(pg[start - hsft -1][vW - shift - 1] == 1)
                    break;
                if(pg[start+1  -1 - hsft][vW - shift - 2] == 1)
                    break;
                hsft ++;
            }
            pg[start+1 - hsft][vW - shift] = 1;
            pg[start+1 - hsft][vW - shift -1] = 1;
            pg[start+1 - hsft][vW - shift -2] = 1;
            pg[start - hsft][vW - shift -1] = 1;
            pg.pop_back();
            pg.pop_back();
            start -=2;
        }
        clearline(pg, start, W);
        start += 4;
    }
    cout << pg.size() - 1 << endl;
    return 0;
}
