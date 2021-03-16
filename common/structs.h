//
// Created by zhaozi on 2021/3/4.
//

#ifndef C_TEST_STRUCTS_H
#define C_TEST_STRUCTS_H

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <vector>

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

    ~Malloc_Test()    //key 绝不在构造和析构过程中调用 virtual 函数（因为这类调用从不下降至 derived class
    {
        free(p);
    }
} Malloc_Test;

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

    ~New_Test()   //key 别让异常逃离析构函数（析构函数应该吞下不传播异常，或者结束程序，而不是吐出异常；如果要处理异常应该在非析构的普通函数处理）
    {
        delete ptr;
    }

    int get_page() const; //key 常量成员函数,作用在this上，不可以修改指向对象的内容
    int get_id();
};

class Bean_test{
private:
    int width;
    const int height;    //key const 修饰的field必须在构造函数初始化
    const static int a ;  //key const static修饰的field可以在外部初始化

public:
    Bean_test(int w ,int h):width(w),height(h){}

    int getWidth() const  //key const 修饰的函数，内部不允许修改普通变量。允许修改static变量
    {
        return width;
    }

    void setWidth(int width)
    {
        Bean_test::width = width;
    }

    int getHeight() const
    {
        return height;
    }

    void setHeight(int height)
    {
        Bean_test::height = height;
    }
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



template <class T>
typedef struct Initializer_List{
    std::vector<T> v;
    Initializer_List(std::initializer_list<T> l):v(l){}
};

#endif //C_TEST_STRUCTS_H
