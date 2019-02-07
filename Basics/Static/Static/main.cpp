//
//  main.cpp
//  Static
//
//  Created by Sciencethebird on 2018/9/30.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//

#include <iostream>
using namespace std;

extern int boiii;
static int global_vari = 0;
void a_function(){
    static int func_vari = 0;
    global_vari++;
    boiii++;
    func_vari++;
    cout << "func_cnt" <<func_vari << endl;
}
int main(int argc, const char * argv[]) {

    cout << boiii << endl;
    for(int i =0; i< 10; i++)
        a_function();
    cout << "global = " << global_vari;
    ///< "main = " << main_vari;
    ///< "Function = " << func_vari;
    return 0;
}
