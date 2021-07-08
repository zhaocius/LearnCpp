#include <iostream>
#include "common/structs.h"


void pointer_test(){
    int * pt;//key 未初始化的指针
    *pt = 5;   // 严重的错误


    int *p = 0;  //初始化指针
    double *p1 = NULL;  //初始化指针
    double *p2 = nullptr;//初始化指针


    p = 0; //使用完，手动赋值给0
    int ZERO  = 0;
//    p = ZERO; //key 不能用变量，即使变量的值为0。


    //所有指针的值都是一个内存地址，不同数据类型指针的唯一不同是指针所指向的变量的数据类型不同。
    std::cout<< sizeof(p) << std::endl;   //key 指针的大小，64位设备，输出8
    std::cout<< sizeof(*p) << std::endl;  //key 指向的int的大小，输出4

    int var = 20;
    int *pp = &var;
    void *void_p = pp;
    int *int_pp = (int *)void_p; //key void *


    int tuple[3]={1,2,3};
    int *ppp = tuple;      //把数组的起始地址给到指针。
    for(int i=0;i<3;i++){
        std::cout << *ppp <<std::endl;
        ppp++;       //ppp +1  等于 &tuple[1]
    }

    long addr = 12241241221L;
    char * test=(char *)addr; //key 直接把long视为一个指针地址

    const int a = 1;
//    int *p3 = &a; //key p3是普通指针，不能指向常量
    const int * p4 = &a;

    int arr[] = {1,2,3,4,5};
    int * p5 = &arr[5];
    int * p6 = std::end(arr);
    printf("%d", p6 == p5);  //key end只想数组之后

}

void (*pf)(int a );
void function(int a ){
    printf("fuction pointer %d",a);

}
void testFunctionPointer(){   //key 函数指针
    pf = function;
    pf(1);
}


void ptr_of_ptr(Bean_test** bean){  //key !!!! 为什么要使用二级指针？
    *bean = new Bean_test(3,3);
}

void test_ptr_of_ptr(){
    Bean_test* p = nullptr;
    ptr_of_ptr(&p);
    printf("%d, ",p->getWidth());
}

//key !!!! 实参是一个空指针p，形参为bean，把p赋给bean，然后执行bean = new Bean()；这时bean指向一段内存。
//key !!!! 但是因为形参改变不会影响到实参的值，p的值并没改变，还是NULL，所以下面拷贝不成功。
void ptr(Bean_test* bean){
    bean = new Bean_test(3,3);
}

void test_ptr(){
    Bean_test* p = nullptr;
    ptr(p);
    printf("%d, ",p->getWidth());
}
