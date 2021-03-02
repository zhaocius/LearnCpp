//
// Created by zhaozi on 2021/1/25.
//

#include <map>

void test1(int,int){}
void test2(int,int){}
void test3(int,int){}

using ModelHandleFunc = std::function<void(int,int)>;



void function_bind_test(){
    std::map<int,ModelHandleFunc> test{{1,std::bind(test1,std::placeholders::_1,std::placeholders::_2)},
                                       {2,std::bind(test2,std::placeholders::_1,std::placeholders::_2)},
                                       {3,std::bind(test3,std::placeholders::_1,std::placeholders::_2)}};

    auto beg = test.begin();
    while(beg!=test.end()){
        ModelHandleFunc func = beg->second;
        func(3,4);
        beg++;
    }
}
