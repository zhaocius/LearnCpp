//
// Created by zhaozi on 2021/1/12.
//

#include <map>

void map_test(){
    std::map<int,int> map0{{1,2},{2,3},{3,4}};
    printf("size = %d",map0.size());
    std::pair<int,int> pair0{1,2};
    printf("first %d, second %",pair0.first,pair0.second);
    map0.insert(pair0);
}