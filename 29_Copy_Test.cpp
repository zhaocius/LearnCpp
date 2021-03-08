//
// Created by zhaozi on 2021/3/6.
//

#include "common/structs.h"

//合成拷贝赋值运算符
Copy_Test & Copy_Test::operator=(const Copy_Test &rhs)
{
    a = rhs.a;
    return *this;
}

