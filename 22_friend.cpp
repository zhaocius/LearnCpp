//
// Created by zhaozi on 2021/3/12.
//

#include "common/structs.h"

void print(New_Test& new_test){
    printf("new _test: %d",new_test.id);
}

void test_friend(){
    New_Test newTest;
    print(newTest);
}
