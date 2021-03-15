//
// Created by zhaozi on 2020/10/21.
//

class Box
{
public:
    virtual int getID()
    {}; //key 虚函数需要空实现，纯虚函数不用
    virtual int getAge() = 0;//key 纯虚函数不用实现
    char *getName()
    {
        return 0;
    }

    Box();

    ~Box();
};

class Rectangle : public Box
{
public:
    int getID()
    {
        return 2;
    }

    int getAge()
    {
        return 3;
    }
};


class Circle : public Box
{
public:
    int getID()
    {
        return 3;
    }

    int getAge()
    {
        return 4;
    }
};


void anstract_class_test()
{
//    Box box;    //key 有纯虚函数的类是抽象类，不可初始化
    Box *rectangle = new Rectangle;
    Box *circle = new Circle;

}

