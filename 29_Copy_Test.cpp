//
// Created by zhaozi on 2021/3/6.
//

#include "common/structs.h"

//key copy assignment运算符
Copy_Test & Copy_Test::operator=(const Copy_Test &rhs) //key assignment操作符返回一个ref
{
    if(this == &rhs)
        return *this;

    a = rhs.a;
    delete p;
    p = new char(*rhs.p);
    return *this;
}


Copy_Test::Copy_Test()
{

}

Copy_Test::Copy_Test(const Copy_Test & copy_test)

{

}

void copy_test(){
    Copy_Test copy_test; //调用default构造函数
    Copy_Test copy_test1(copy_test); //key 调用copy构造函数
    copy_test = copy_test1; //key 调用copy assignment运算符
    Copy_Test copy_test2 = copy_test; //key 调用copy构造函数
}


