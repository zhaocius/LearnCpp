//
// Created by zhaozi on 2021/3/4.
//

#ifndef C_TEST_STRUCTS_H
#define C_TEST_STRUCTS_H

#include <cstdlib>
#include <stdio.h>
#include <iostream>

typedef struct Malloc_Test
{
    int a;
    char *p;

    void hello();

    Malloc_Test()
    {
        p = (char *) malloc(sizeof(char) * 100000);
    }

    Malloc_Test(int a):a(a)   //key 使用a(a) member initialization list
    {
//        this->a = a;        //key 不要使用这种，这不是初始化 是赋值
        p = (char *) malloc(sizeof(char) * 100000);
    }

    ~Malloc_Test()
    {
        free(p);
    }
} SP_Test;

class New_Test
{
    friend void print(New_Test&); //友元声明
private:
    int id;
    int page;
    int *ptr;
public:
    New_Test() = default;   //key 如果没有 不能默认初始化
    New_Test(int _id) : id(_id), ptr(new int(1))
    {}
    New_Test(int _id, int _page) : id(_id), page(_page), ptr(new int(1))
    {}

    //key 拷贝构造函数，需要用const
    //key 指针需要深拷贝，否则默认是浅拷贝，两个对象会指向一块内存，在析构时会造成悬挂指针
    New_Test(const New_Test &orig) : id(orig.id), page(orig.page), ptr(new int(*orig.ptr))
    {}

    ~New_Test()   //析构函数不得抛出异常
    {
        delete ptr;
    }

    int get_page() const; //key 常量成员函数,作用在this上，不可以修改指向对象的内容
    int get_id();
};


class Copy_Test
{
public:
    Copy_Test();                   //key default构造函数
    Copy_Test(const Copy_Test&);    //key copy构造函数
    Copy_Test& operator=(const Copy_Test&);  //key copy assignment操作符
    int a;
    char* p;
};
const Copy_Test operator*(const Copy_Test&,const Copy_Test&); //key 需要定义在class外面

#endif //C_TEST_STRUCTS_H
