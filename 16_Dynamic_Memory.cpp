#include <iostream>
#include <stdio.h>


class String {
public:
    std::string * str;
    String(const std::string& param):str(new std::string(param)){}
    String(const String& string):str(string.str){}
    ~String() {
        delete str;
    }
};

String delete_test(String str){
    String str1 = str;
}

//是如果析构函数里用delete释放内存指针的时候可能会报错, 完整的代码必须重载运算符"=", 并在其中处理内存释放
void illigel_deleter_test(){
    String str("1234");
    delete_test(str);  //key 调用之后，str对应的指针已经被销毁了。 那应该怎么设计？？？
    std::cout<<*str.str<<std::endl;
}


//new 和malloc()
//不推荐malloc()，new不仅分配了内存，还创建了对象。
void tuple_malloc_and_delete() {
    int SIZE = 10;
    int *p = (int *)malloc(sizeof(int)*SIZE);
    memset(p,1,sizeof(int)*SIZE);
    std::cout << *p << std::endl;
    free(p);
}

void tuple_new_and_delete(){
    //一维数组
    char* p=NULL;
    p=new char[10];
    delete [] p;

    //二维数组
    char** array=new char* [3];
    for(int i=0;i<3;i++){
        array[i]=new char[3];
    }

    for(int i=0;i<3;i++){
        delete [] array[i];
    }
    delete [] array;
}


