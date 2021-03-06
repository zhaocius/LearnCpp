#include <iostream>


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