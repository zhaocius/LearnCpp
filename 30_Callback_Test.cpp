//
// Created by zhaozi on 2021/3/26.
//
#include <istream>

//具体实现
void impl(void (*callback)(int sum),int x,int y){
    int z = x+y;
    callback(z);
}


//回调结果
void my_callback(int sum){
    printf("test sum = %d",sum);
}

void test_callback()
{
    int a = 1;
    int b = 2;
    impl(my_callback,a,b);
}
