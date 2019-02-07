#include<iostream>
#include<string>

using namespace std;
struct movement{
int x, y;
};
enum direction {N, E, S, W};

void Path(const int m, const int p){
    mark[][];
    mark[1][1] = 1;


}

int main(){

movement *M = new movement[4];
M[N].x = -1;
M[N].y = 0;
M[E].x = 0;
M[E].y = 1;
M[S].x = 1;
M[S].y = 0;
M[W].x = 0;
M[W].y = -1;
cout << M[N].x << endl;
    return 0;
}
