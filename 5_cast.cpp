#include <iostream>
void cast_test(){

    int a = 3;
    int b = 5;
    double c = static_cast<double>(b)/a;  // static_cast 较大算数类型赋给小类型
    std::cout<< c << std::endl;

    void *p = &a;
    int * pp = static_cast<int*>(p);  //static_cast 找回void* 指针为 int *
    std::cout<< *pp << std::endl;


    //const_cast


    //reinterpret_cast 运行时才检查
    int *ip;
    char *pc = reinterpret_cast<char *>(ip);   // C写法 char* pc = (char *)ip
    std::string str(pc); // 报错！！！！！ pc真正指向的是一个int


}

