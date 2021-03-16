#include <iostream>

/*
 * 和指针不同
 * 1 不存在空引用，指针可以空指针。
 * 2 一旦引用被初始化成一个对象，就不能被指向另一个对象。指针可以任何之后指向另一个对象。
 * 3 引用必须在创建时被初始化，指针可以在任何时候初始化
 * 4 引用就是别名
 *  */


void ref_test() {
    int arr[3]{1, 2, 3};
    int (&arr_ref)[3] = arr;  //key arr_ref是一个数组的引用

    // int &ref_aar[2];      //key ref_aar是引用的数组，不合法


}


void ref_test1(){
    int a = 0;
    const int b = 0;
    const int &r = a;   //key 允许const绑定到普通int上
    const int &r1 = b;  // r1是一个常量引用

//    r = 3;  //key a的值不能通过常量引用r1改变
//    int &r3 = b; //key 非常量引用不可以指向一个常量
}




