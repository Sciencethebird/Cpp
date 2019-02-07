//
//  main.cpp
//  2D Array
//
//  Created by Sciencethebird on 2018/10/10.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//
#define sz 10
#include <iostream>
using namespace std;

void print_f(int a [][sz], int k){
    for(int i = 0; i< k;i++){
        for(int j = 0; j< sz; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[10][10];
    for(int i = 0; i< 10;i++)
        for(int j = 0; j< 10; j++)
            a[i][j] = (i+j)%(i+1);
    print_f(a, 10);
    return 0;
}
