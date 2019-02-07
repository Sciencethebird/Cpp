//
//  timer.h
//  Sorting
//
//  Created by Sciencethebird on 2018/8/31.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//

#ifndef timer_h
#define timer_h
#include <chrono>
#include <iostream>
using namespace std::chrono;
#define t_start auto t1 = steady_clock::now()
#define t_end auto t2 = steady_clock::now();auto span = duration_cast<duration<double>>(t2 - t1)
#define time span.count()
#define show_time std::cout << time << "s" << std::endl
#endif /* timer_h */
