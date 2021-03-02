//
// Created by zhaozi on 2020/10/21.
//
#include<cstring>
#include<iostream>


typedef struct Book {
    char title[50];
    char author[50];
    int book_id;
}Book;

//传递的是拷贝
struct Book get_book(void){
    struct Book book1={{1,3,5},{2,4,5},12};
    return book1;
}

//结构体作为入参，传递的是拷贝
void print_book(struct Book book){
    std::cout << book.title << book.author << book.book_id << std::endl;
}
//结构体的指针作为入参
void print_book(Book* book){
    std::cout << book->title << book->author << book->book_id << std::endl;
}

void struck_test() {
    Book book1;

    std::strcpy(book1.title, "C++");
    std::strcpy(book1.author, "zhao");
    book1.book_id = 19;
    std::cout << book1.title << book1.author << book1.book_id << std::endl;

    print_book(book1);

    Book* p;
    p=& book1;        //指向结构的指针
    print_book(p);

    Book book2={{1,2,3,4,5},18
    };
    print_book(book2);

    Book bookss[12];

    struct Book book3=get_book();  //key 为什么出了函数后，还可以使用？？？
    printf("%d \n",book2.book_id);
}