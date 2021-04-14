#include <future>
#include <thread>
#include <iostream>
#include <zconf.h>

//
// Created by zhaozi on 2021/1/25.
//


void test1(){
    std::cout << "test1 pid= " << getpid() << std::endl;
    sleep(1); //秒
    usleep(1000);//毫秒
    std::cout << "test1 tid=" << std::this_thread::get_id() << std::endl;
}
int test2(){
    std::cout << "test2 pid= " << getpid() << std::endl;
    sleep(2);
    std::cout << "test2 tid=" << std::this_thread::get_id() << std::endl;
    return 100;
}

int test3(){
    std::cout << "test3 pid= " << getpid() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "test3 tid=" << std::this_thread::get_id() << std::endl;
    return 100;
}

void async_test(){
    std::future<int> async_test= std::async(std::launch::async,test3);
    test1();
    int a = async_test.get();
    printf("async_test: %d",a);
}
