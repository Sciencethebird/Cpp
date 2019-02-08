//
//  main.cpp
//  testbench
//
//  Created by Sciencethebird on 2019/2/8.
//  Copyright © 2019 Sciencethebird. All rights reserved.
//

#include <iostream>
#define hexnum 0x123

void test(){
    static int stc = 1;
    std::cout << stc << std::endl;
    stc++;
}

class testclass{
public:
    void non_static_func() {std::cout << "lol" << std::endl;}
    static void static_func() {std::cout << "lol" << std::endl;}
};
int main(int argc, const char * argv[]) {
    
    std::cout << hexnum;
    for(int i = 0; i< 10; i++){
        test();
        //std::cout << stc << std::endl; // won't work cuz static does not changr scope
    }
    
    testclass::static_func(); // call static function directly
    //testclass::non_static_func(); // can't do this with non-static member
    return 0;
}
