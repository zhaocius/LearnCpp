//
// Created by zhaozi on 2021/2/22.
//
#include <iostream>


class CxString{
public:
    char * _pstr;
    int _size;
    explicit CxString(int size){
        _size=size;
        _pstr= static_cast<char *>(malloc(size + 1));
        memset(_pstr,0,size+1);
    }
    CxString(const char* pstr){
        int size = strlen(pstr);
        _pstr = static_cast<char *>(malloc(size+1));
        strcpy(_pstr,pstr);
        _size=strlen(_pstr);
    }
};

void explicit_test() {

//    CxString cxString1 = 1;//key 使用explicit，不可以使用 =
    CxString cxString2(1);


}