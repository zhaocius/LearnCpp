//
// Created by zhaozi on 2020/10/21.
//

class Box{
public:
    virtual int getID(){};
    char* getName(){
        return 0;
    }
    Box();
    ~Box();
};
class Rectangle: public Box{
public:
    int getID(){
        return 2;
    }
};

