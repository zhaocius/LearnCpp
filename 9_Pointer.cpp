#include <iostream>


void getSeconds(int *c);
void getSeconds(int c);

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
    *pp=3;
    std::cout << *pp <<std::endl;

    void *void_p = pp;
    int *void_pp = (int *)void_p; //key void *


    int tuple[3]={1,2,3};
    int *ppp = tuple;      //把数组的起始地址给到指针。
    for(int i=0;i<3;i++){
        std::cout << *ppp <<std::endl;
        ppp++;       //ppp +1  等于 &tuple[1]
    }


    int sec=0;
    getSeconds(sec);  //传值，不会改变本地变量
    getSeconds(&sec); //传地址，会改变。
    std::cout << sec;

    long addr = 12241241221L;
    char * test=(char *)addr; //key 直接把long视为一个指针地址

    const int a = 1;
//    int *p3 = &a; //key p3是普通指针，不能指向常量
    const int * p4 = &a;


    int arr[] = {1,2,3,4,5};
    int * p5 = &arr[5];
    int * p6 = std::end(arr);
    printf("%d", p6 == p5);




}

void getSeconds(int *c ) {
    *c= time(NULL);
}
//传递指针给函数
void getSeconds(int a){
    a=100;
}

//函数返回指针
//不支持在函数外部返回局部变量的地址，除非定义了static
int * getSeconds(){
    static int r[3]={1,2,3};
    return r;
}

void function(int a );
void function(int a ){

}
void testFunctionPointer(){
    void (*pf)(int a );
    pf = function;
}
