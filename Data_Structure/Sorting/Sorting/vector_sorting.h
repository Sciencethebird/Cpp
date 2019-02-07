//
//  Sorting.h
//  Sorting
//
//  Created by Sciencethebird on 2018/8/28.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//

#ifndef Sorting_h
#define Sorting_h
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "timer.h"

using namespace std::chrono;
template<typename T>
void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
class my_vector: public std::vector<T>{
public:
    void selection_sort(){
        std::cout<<"selection Sort"<<std::endl;
        size_t size = this->size(), swap_cnt = 0;
        t_start;
        for(size_t start = 0; start < size - 1; start++){
            size_t min_idx = start;
            for(size_t i = start+1; i < size; i++)
                if((*this)[i]< (*this)[min_idx])
                    min_idx = i;
            swap((*this)[min_idx], (*this)[start]);
            swap_cnt++;
        }
        t_end;
        show_time;
        
        std::cout << "swap " << swap_cnt << " times" << std::endl;
    }
    
    void weird_bubble_sort(){
        std::cout << "Bubble Sort (Weird Version)" << std::endl;
        size_t size = this->size(),swap_cnt = 0;
        t_start;
        for(size_t i = 0; i< size; i++)
            for(size_t j = i+1; j< size; j++)
                if((*this)[i] > (*this)[j]){
                    swap((*this)[i], (*this)[j]);
                    swap_cnt++;
                }
        t_end;
        show_time;
        std::cout << "swap " << swap_cnt << " times" << std::endl;
    }
    
    void bubble_sort(){
        std::cout << "Bubble Sort" << std::endl;
        size_t size = this->size(), swap_cnt = 0;
        t_start;
        for(size_t i = 0; i< size; i++)
            for(size_t j = 0; j< size-1-i; j++)
                if((*this)[j+1] < (*this)[j]){
                    std::swap((*this)[j+1], (*this)[j]);
                    //swap((*this)[j+1], (*this)[j]);
                    swap_cnt++;
                }
        t_end;
        show_time;
        std::cout << "swap " << swap_cnt << " times" << std::endl;
    }
    
    void v_insert(const T &n, size_t i){
        this->std::vector<T>::insert(this->begin(), n);
        while(n< (*this)[i-1])
            i--;
        this->erase(this->begin());
        this->std::vector<T>::insert(this->begin()+i, n);
    }
    void insertion_v_sort(){
        std::cout << "insertion sort by vector insert()" << std::endl;
        t_start;
        const size_t size = this->size();
        for(size_t sorted = 0; sorted< size; sorted++){
            v_insert((*this)[sorted], sorted);
            this->erase(this->begin()+sorted+1);
        }
        t_end;
        show_time;
    }
    void insert(const T &a, int i){
        
    }
    void insertion_sort(){
        std::cout << "insertion sort(built-in insert)" << std::endl;
        const size_t size = this->size();
        for(int j = 2; j<=size; j++){
            //T temp = (*
        }
    }
    void quick_sort(){
        std::cout << "Quick Sort" << std::endl;
        const size_t size = this->size();
        t_start;
        q_sort(*this, 1, (int)size);
        t_end;
        show_time;
    }
    void std_sort(){
        std::cout << "Std Built-In Sort" << std::endl;
        t_start;
        std::sort(this->begin(), this->end());
        t_end;
        show_time;
    }
private:
    std::string secret = "NUDS";
};
template<typename T>
void q_sort(std::vector<T> &a, const int left, const int right){
    if(left<right){
        int i = left,
        j = right + 1,
        pivot = a[left];
        
        do{
            do i++; while(a[i]<pivot);
            do j--; while(a[j]>pivot);
            if(i<j)std::swap(a[i], a[j]);
        }while(i<j);
        std::swap(a[left], a[j]);
        q_sort(a, left, j-1);
        q_sort(a, j+1, right);
    }
}
#endif /* Sorting_h */

