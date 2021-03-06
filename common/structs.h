//
// Created by zhaozi on 2021/3/4.
//

#ifndef C_TEST_STRUCTS_H
#define C_TEST_STRUCTS_H

#include <cstdlib>
#include <stdio.h>
#include <iostream>


typedef struct Book
{
    char title[50];
    char *author;
    int book_id;
} Book;

typedef struct Malloc_Test
{
    int a, b;
    int *p;

    void hello();

    Malloc_Test()
    {
        p = (int *) malloc(sizeof(int) * 100000);
    }

    Malloc_Test(int a, int b)
    {
        this->a = a;
        this->b = b;
        p = (int *) malloc(sizeof(int) * 100000);
    }

    ~Malloc_Test()
    {
        free(p);
    }
} SP_Test;

class New_Test
{
    friend void print(New_Test); //友元声明
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
    //key 指针需要深拷贝，否则默认是前拷贝，两个对象会指向一块内存，在析构时会造成悬挂指针
    New_Test(const New_Test &orig) : id(orig.id), page(orig.page), ptr(new int(*orig.ptr))
    {}

    ~New_Test()
    {
        delete ptr;
    }

    int get_page() const; //key 常量成员函数,作用在this上，不可以修改指向对象的内容
    int get_id();
};

class Screen
{
public:
    Screen(int w, int h) : w(w), h(h)
    {}

    Screen() : Screen(0, 0)  //key 委托构造函数
    {};
    Screen &move(int dw, int dh){
        this->w = this->w+dw;
        this->h = this->h+dh;
        return *this;
    }

    inline void print(){
        printf(" %d , %d ",this->w,this->h);
    }

private:
    int w;
    int h;
};
#endif //C_TEST_STRUCTS_H
