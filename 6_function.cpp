//
// Created by zhaozi on 2020/10/20.
//
#include <iostream>

typedef struct Book{
    int id;
    int* test;
}Book;

Book test_return(){  //key 返回的是局部对象的拷贝，而test对应的地址已经无效
    Book book;
    book.id = 3;
    int aar[] ={1,2,3};
    book.test=aar;
    return book;
}

Book* test_return_ptr(){  //key 不要返回局部对象的指针
    Book book;
    book.id = 3;
    int aar[] ={1,2,3};
    book.test=aar;
    return &book;
}

Book& test_return_ref(){  //key 不要返回局部对象的引用
    Book book;
    book.id = 3;
    int aar[] ={1,2,3};
    book.test=aar;
    return book;
}


void test_obj(Book book){   //key 形参是对应实参的拷贝，比较低效，有的类甚者不支持。
    book.id = 9;
    book.test[2]=9;
}

void test_ref(Book& book){   //key 引用形参是对应实参的别名，在函数内部就是对实参进行操作。

    book.id = 10;
    book.test[2]=10;
}

void test_p(Book* book){  //key 拷贝的是指针的值，实参和形参是两个不同的指针，指向同一个地址。

    book->id = 9;
    book->test[2]=9;
    book= 0;           //key 只改变了book的局部拷贝，不改变实参
}


void function_test()
{
    Book book;
    book.id = 1;
    int aar[] ={1,2,3};
    book.test=aar;
    test_p(&book);
    test_ref(book);

    printf("main %d \n",book.id);
    printf("main %d \n",book.test[2]);

    book = test_return_ref();

    printf("main %d \n",book.id);
    printf("main %d \n",book.test[2]);
}


