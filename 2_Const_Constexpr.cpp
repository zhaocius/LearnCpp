#include <iostream>

const int WIDTH = 5;     //限定一个变量为只读。
constexpr int HEIGHT = 5; //这是一个常量，编译期间就确定了。

void const_test() {

    double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};
    double * const pc = rates;
    *pc = 92.99;
//    pc = &rates[2]; //key 顶层const， pc的值不可变，即指向的地址不可变。

    const double * p = rates;
    p=&rates[2];
//    *p = 11;  //key 底层const，p能指向别处，但是解引用后的值不可变

    const double * const p1 =rates; //都不能变。
}

//------------------------------------
// 如果不想改变入参，加上const修饰
void print_tuple(const int *tuple, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << *(tuple + i) << std::endl;
    }
}

void change_tuple(int *tuple, int length) {
    for (int i = 0; i < length; i++) {
        *(tuple + i) = 0;
    }
}

//-----------------------------------

void constexpr_test()
{
    int i;
    std::cin>>i;
    const int j = i+1;  //key constexpr 语义是只读
//    constexpr int k = i+1; //key constexpr 语义是常量

}

