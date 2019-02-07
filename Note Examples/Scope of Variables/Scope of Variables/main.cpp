//
//  main.cpp
//  Scope of Variables
//
//  Created by Sciencethebird on 2018/9/28.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//

#include <iostream>
using namespace std;
int x = 22;
void a_function(int n){
    static int x = 0;
    x++;
    std::cout << x << '\n';
}

int main(int argc, const char * argv[]) {
    a_function(x);
    int x = 10;
    a_function(x);
    for(int i = 0; i< 10; i++){
        int x = 100;
        a_function(::x);
        a_function(x);
    }
    
    return 0;
}
