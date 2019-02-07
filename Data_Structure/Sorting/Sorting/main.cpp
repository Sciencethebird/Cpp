//
//  main.cpp
//  Sorting
//
//  Created by Sciencethebird on 2018/8/28.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//

#include <iostream>
#include "vector_sorting.h"
#include "tool_functions.h"
#include <vector>
#include <cstdio>
#include <ctime>
#include <algorithm>

#define type int
int main(int argc, const char * argv[]) {

    my_vector<type> test;
    //srand((unsigned)time(NULL));
    srand(6);
    for(long long i = 0; i< 50000; i++){
        auto num = (type)rand()%101;
        //auto num = (type)rand()/RAND_MAX;
        test.push_back(num);
    }
    my_vector<type> test1(test), test2(test), test3(test), test4(test), test5(test), test6(test);
    //std::cout << test << std::endl;

    test.selection_sort();
    //std::cout << test << std::endl;
    test1.weird_bubble_sort();
    //std::cout << test1 << std::endl;
    //std::cout <<test4 << std::endl;
    test3.insertion_v_sort();
    //std::cout << test4 << std::endl;
    test4.quick_sort();
    //std::cout << test5 << std::endl;
    test2.std_sort();
    test6.bubble_sort();
    //std::cout << test2 << std::endl;
    return 0;
}
