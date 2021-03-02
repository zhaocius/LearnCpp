//
// Created by zhaozi on 2020/10/21.
//
#include <iostream>
#include <vector>
class Book {
    friend void print_Book(Book); //友元声明
private:
    int id;
    int page;
    int* ptr;
public:
    Book()=default;   //key 如果没有 不能默认初始化
    Book(int _id):id(_id),ptr(new int(1)){}
    Book(int _id,int _page):id(_id),page(_page),ptr(new int(1)){}
    //key 拷贝构造函数，需要用const
    //key 指针需要深拷贝，否则默认是前拷贝，两个对象会指向一块内存，在析构时会造成悬挂指针
    Book(const Book& orig):id(orig.id),page(orig.page),ptr(new int(*orig.ptr)){}
    ~Book(){
        delete ptr;
    }
    int get_page () const; //key 常量成员函数,作用在this上，不可以修改指向对象的内容
    int get_id ();
};

int Book::get_page() const {
//    page = 3;     //key 不可修改
    return page;
}

int Book::get_id()  {
    id = 3;
    return id;
}

void print_Book(Book book){  //key 友元 允许函数和其他类访问类的私有成员
    printf("%d", book.id);

}

void book_test()
{
    //key 定义并初始化，调用1次构造函数
    Book book0=Book(1,2);//栈中分配，系统自动delete。
    Book book1(0,10); //栈中分配，系统自动delete。

    //key 先定义，再赋值，调用了2次构造函数
    Book book3;//调用Book()
    book3 = {1,2}; //调用Book(int _id,int _page)

    Book* book2; //指针，堆中分配，需要手动delete
    book2 = new Book(1,5);
    delete book2;

    Book book6=book0; //调用Book(const Book& book)
    Book book7(book0); //调用Book(const Book& book)

    std::vector<Book> books;
    books.push_back(book1);
    books.push_back({1,2}); //隐式转换
    books.push_back(1); //隐式转换

};
//key --------------------------------------------------------------------
//key --------------------------------------------------------------------
//key --------------------------------------------------------------------

class Screen {
public:
    Screen(int w, int h) : w(w), h(h) {}
    Screen():Screen(0,0){}; //key 委托构造函数
    Screen &move(int dw, int dh);
    inline void print();
private:
    int w;
    int h;
};

Screen & Screen::move(int dw, int dh) {
    this->w = this->w+dw;
    this->h = this->h+dh;
    return *this;
}
void Screen::print(){
    printf(" %d , %d ",this->w,this->h);
}

void screen_test() {
    Screen screen(3,3);
    screen.move(1,2).print();


}



