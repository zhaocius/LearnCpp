#include <future>
#include <thread>
#include <iostream>
#include <zconf.h>

//
// Created by zhaozi on 2021/1/25.
//
void test1();
int test2();

void async_test(){

    std::future<int> async_test= std::async(std::launch::async,test2);
    test1();
    async_test.get();

}

void test1(){
    std::cout << "test1 pid= " << getpid() << std::endl;
    std::cout << "test1 tid=" << std::this_thread::get_id() << std::endl;
}
int test2(){
    std::cout << "test2 pid= " << getpid() << std::endl;
    std::cout << "test2 tid=" << std::this_thread::get_id() << std::endl;
}