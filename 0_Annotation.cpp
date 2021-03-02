#include <iostream>

//使用 #if 和 #endif 可以当作注释
//如果是 #if 1 则会执行
void annotation()
{
    std::cout << "hello";
#if 0
    这是一个注视
#endif
}

//定义常量  ---------------------------------------------
#define PI 3.1415

//定义参数宏  ---------------------------------------------
#define MIN(a, b) (a<b?a:b)
void define_test() {
    int i = 0;
    int j = 1;
    std::cout << MIN(i, j) << std::endl;
}

//条件编译  ---------------------------------------------
#define DEBUG

void define_test2() {
#ifdef DEBUG
    std::cout<<"wawa"<<std::endl;   //能编译进去，前面定义了。
#else
    std::cout<<"haha"<<std::endl;   //不能编译进去
#endif


#ifndef DEBUG
    std::cout<<"wawa"<<std::endl;   //不能编译进去
#else
    std::cout<<"haha"<<std::endl;   //能编译进去，前面定义了。
#endif

}

//定义了 能编译进去
DEBUG void define_test3(){

}
