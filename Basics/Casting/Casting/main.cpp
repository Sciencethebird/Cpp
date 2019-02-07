//
//  main.cpp
//  Casting
//
//  Created by Sciencethebird on 2018/9/30.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    double a = M_PI;
    const double cunt = M_E;
   
    //double lol = const_cast<double&>(cunt);
    double lol = cunt;
    lol = 69;
    //int lol = static_cast<int>(a);
    cout << lol << endl;
    return 0;
}
