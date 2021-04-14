//
// Created by zhaozi on 2020/10/21.
//

#include <iostream>
#include <ctime>
#include <time.h>
#include <chrono>
#include <thread>

//只需要在函数开头初始化一个timer，自动计时
typedef struct Timer{
    std::chrono::time_point<std::chrono::steady_clock> start;
    Timer(){
        std::cout<<"functions start "<<std::endl;
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer(){
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end -start;
        std::cout<<"function end ,time = "<<duration.count()<<std::endl;
    }

}Timer;

//使用的标准C的结构体和函数
//tm结构体
void time_test1(){
    clock_t start,finish;
    double time;
    start=clock(); //开始

    std::this_thread::sleep_for(std::chrono::seconds(2));

    finish=clock();    //结束
    time=(double)(finish - start) *1000 / CLOCKS_PER_SEC;
    std::cout << time<< std::endl;
}

//使用chrono库
void time_test2(){
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>  duration = end -start;
    std::cout<<duration.count()<<std::endl;
}

