//
// Created by zhaozi on 2020/10/31.
//

int global_var = 0; //key 声明并定义,所有文件可用

static int static_var =0; //key static 修饰全局变量，使变量的作用限制在声明他的文件内

void storage_class()
{
    static int e =0;  //key 在函数调用之间保持局部变量的值

}


extern int c; //key extern不是定义，是声明。 可以不引用别的头文件，直接使用其他文件的全局变量。

extern int d =1 ; //key extern加上显示的初始化，就是定义，抵消了extern的作用。

namespace Wahaha {
    class Wahuhu{
        void huhu();
    };
    class Walulu{
        void lulu();
    };
} //namespace Wahaha

void namespace_test(){
    Wahaha::Wahuhu wahuhu;
}



