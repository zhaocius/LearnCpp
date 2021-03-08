//
// Created by zhaozi on 2020/10/20.
//
#include <iostream>
#include "common/structs.h"

//传递的是拷贝
Malloc_Test test_return(){  //key 返回的是局部对象的拷贝，而test对应的地址已经无效
    Malloc_Test malloc_Test;
    malloc_Test.a = 3;
    char aar[] ={'1','2','3','\0'};
    malloc_Test.p=aar;
    return malloc_Test;
}

Malloc_Test* test_return_ptr(){  //key 不要返回局部对象的指针
    Malloc_Test malloc_Test;
    malloc_Test.a = 3;
    char aar[] ={'1','2','3','\0'};
    malloc_Test.p=aar;
    return &malloc_Test;
}

Malloc_Test& test_return_ref(){  //key 不要返回局部对象的引用
    Malloc_Test malloc_Test;
    malloc_Test.a = 3;
    char aar[] ={'1','2','3','\0'};
    malloc_Test.p=aar;
    return malloc_Test;
}


void test_obj(Malloc_Test malloc_Test){   //key 形参是对应实参的拷贝，比较低效，有的类甚者不支持。
    malloc_Test.a = 9;
    malloc_Test.p[2]=9;
}

void test_ref(Malloc_Test& malloc_Test){   //key 引用形参是对应实参的别名，在函数内部就是对实参进行操作。

    malloc_Test.a = 10;
    malloc_Test.p[2]=10;
}

void test_p(Malloc_Test* malloc_Test){  //key 拷贝的是指针的值，实参和形参是两个不同的指针，指向同一个地址。

    malloc_Test->a = 9;
    malloc_Test->p[2]=9;
    malloc_Test= 0;           //key 只改变了Malloc_Test的局部拷贝，不改变实参
}


void function_test()
{
    Malloc_Test malloc_Test;
    malloc_Test.a = 1;
    char aar[] ={'1','2','3','\0'};
    malloc_Test.p=aar;
    test_p(&malloc_Test);
    test_ref(malloc_Test);

    printf("main %d \n",malloc_Test.a);
    printf("main %c \n",malloc_Test.p[2]);

    malloc_Test = test_return_ref();

    printf("main %d \n",malloc_Test.a);
    printf("main %c \n",malloc_Test.p[2]);
}


