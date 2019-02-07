//
//  main.cpp
//  Cin.ignore()
//
//  Created by Sciencethebird on 2018/9/25.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
using std::cout;
using std::cin;
using namespace std;
int main(int argc, const char * argv[]) {
    char c_in[500];
    std::string in;
   // getline(std::cin, in, '#');
    //std::cin >> c_in;
    //std::cout << in << std::endl;
    //std::cout << c_in << std::endl;
    /*while(getline(std::cin, in)){
        std::cin.getline(c_in, 500);
        std::cout << in <<"\n\n" <<c_in <<"\n";
    }*/
    int a = 5;
    double g = 5.222222;
    cout << std::setprecision(4)
    <<static_cast<double>(a) << std::endl;
    cout << std::setprecision(8)
    <<g<< std::endl;
    cout << std::fixed << setprecision(4) << 3.234234 << std::endl;
    cout << 3.123123 << std::endl;
    //getline(std::cin, in);
    //cin>>in;
    //cout << in <<'\n';
    //cout <<"end boii\n";
    //std::cin.ignore();
    //std::cin>>a;
    return 0;
}
