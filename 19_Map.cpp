//
// Created by zhaozi on 2021/1/12.
//

#include <map>

void map_test(){
    std::map<int,int> test{{1,2},{2,3},{3,4}};
    printf("size = %d",test.size());
    std::pair<int,int> test1{1,2};
    printf("first %d, second %",test1.first,test1.second);
}