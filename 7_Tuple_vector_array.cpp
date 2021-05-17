#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>
#include "common/structs.h"

/*
 (1.）都和数组相似，都可以使用标准数组的表示方法来访问每个元素（array和vector都对下标运算符[ ]进行了重载）
（2.）三者的存储都是连续的，可以进行随机访问
        不同点
（0.）数组是不安全的，array和vector是比较安全的（有效的避免越界等问题）
（1.）array对象和数组存储在相同的内存区域（栈）中，vector对象存储在自由存储区（堆）
（2.）array可以将一个对象赋值给另一个array对象，但是数组不行
（3.）vector属于变长的容器，即可以根据数据的插入和删除重新构造容器容量；但是array和数组属于定长容器
（4.）vector和array提供了更好的数据访问机制，即可以使用front()和back()以及at()（at()可以避免a[-1]访问越界的问题）访问方式，使得访问更加安全。而数组只能通过下标访问，在写程序中很容易出现越界的错误
（5.）vector和array提供了更好的遍历机制，即有正向迭代器和反向迭代器
（6.）vector和array提供了size()和Empty()，而数组只能通过sizeof()/strlen()以及遍历计数来获取大小和是否为空
（7.）vector和array提供了两个容器对象的内容交换，即swap()的机制，而数组对于交换只能通过遍历的方式逐个交换元素
（8.）array提供了初始化所有成员的方法fill（）
（9.）由于vector的动态内存变化的机制，在插入和删除时，需要考虑迭代的是否有效问题
（10.）vector和array在声明变量后，在声明周期完成后，会自动地释放其所占用的内存。对于数组如果用new[ ]/malloc申请的空间，必须用对应的delete[ ]和free来释放内存
*/

int sum(int *ar, int n);  //入参是1维数组
int sum(int ar[], int n);//入参是1维数组
int sum(int (&ar)[], int n);//入参是1维数组,形参是数组的引用

int sum(int arr[][3],int a);//入参是2维数组
int sum(int (*arr)[3],int a);//入参是2维数组

void tuple_test() {
    int arr[10]; //key 未赋值，随机赋值

//    int arr1[10] = arr; //key 不允许使用一个数组初始化另一个数组
//    arr1 =arr ; //key 数组不支持拷贝
//    arr1[10] = {1, 2, 3}; //key 除了初始化的时候，不可以再用这种方式初始化。

    char arr2[50] = "fweafwe";
    char arr3[50]("fweafwe");
    char arr4[50]{"fweafwe"};


    auto beg = std::begin(arr2);
    auto end = std::end(arr2);
    while(beg!=end){
        std::cout<< *beg++ <<std::endl;
    }

    int *h = arr;
    (h + 2) == &h[2];
    *(h + 2) == h[2];

    int g[2][3] = {{1, 2, 3},{3, 4, 5}};
    g == &g[0];  // g代表g[0]的地址，是指针的指针。
    g[0] == &g[0][0]; //g[0]代表g[0][0]的地址。
    *g == g[0];
    **g == g[0][0];
    int (*ppp)[3] =g;    //key ---编译器就知道 ppp+1是在地址上+ 3*4个字节
    g[1][2] == *(*(g+1)+2);
    ppp[1][2] == *(*(ppp+1)+2);


    int arr5[10];
    int (*pppp)[10] = &arr5; //key 含有10个整形指针的数组；
}


//vector的capacity和size
//size指真实占用的大小，
//capacity是指发生realloc之前能允许的最大元素数、
//reserve(n)只修改capacity的值，
//resize(n)真正扩容，
//key []下标可以访问容器内对象，但是可能越界。而且不能用于添加元素


void vector_test() {
    std::vector<int> vec;
    for (int i = 0; i < 5; i++) {
        vec.push_back(i);
    }
    std::cout << vec.size() << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << vec[i] << std::endl;   //key 不检查下标 尽量不使用下标访问
    }



    std::vector<int>::iterator v = vec.begin();
    while (v != vec.end()) {
        std::cout << *v << std::endl;
        *v=3; //key iterator 能改变元素。
        v++;
    }

    for(auto &item:vec){ //key 范围for语句，通过 & 能改变元素。
        item *=2;
    }


    std::vector<int>::const_iterator  c_v = vec.begin();
    while (c_v != vec.end()) {
        std::cout << *c_v << std::endl;
//        *c_v=3; //key const_iterator 不能改变元素。
        c_v++;
    }

    auto c_v1 = vec.cbegin();
    while (c_v1 != vec.end()) {
        std::cout << *c_v1 << std::endl;
//        *c_v1=3; //key const_iterator 不能改变元素。
        c_v1++;
    }


    //key 存放自定义对象，还是存指针好一点，存对象的话，会涉及到拷贝问题。
    std::vector<Malloc_Test *> vec1;
    for (int i = 0; i < 5; i++) {
        Malloc_Test *t1 = new Malloc_Test;
        t1->a = 10;
        vec1.push_back(t1);
    }

    std::vector<Malloc_Test> vec2;
    for (int i = 0; i < 5; i++) {
        Malloc_Test t;
        t.a = 10;
        vec2.push_back(t);
    }


    int aaa[4] = {1, 2, 3, 4};
    std::vector<int> vec3(std::begin(aaa), std::end(aaa)); //key 使用数组初始化vector
    std::vector<int> vec4(15,3);  //小括号，15个元素，每个元素都是3。
    std::vector<int> vec5{15,3};   // 大括号，2个元素， 15 和 3
    std::vector<int> vec6 = vec5;   //key 副本
    std::vector<int> vec7(vec6);   //key 副本



    //vector pop_back 和 erase，不改变capicity，只改变size
    //remove改变size，不建议使用
    vec5.erase(vec5.begin() + 1);//erase the 1th element
    vec5.erase(vec5.begin(), vec5.begin() + 1);
    vec5.pop_back();

    for (int i = 0; i < vec5.size(); i++) {
        std::cout << vec5.at(i) << std::endl;//key at(index)会检查范围,超了会报错。
    }
}

void array_test(){
    std::array<int,5> array1 = {1,2,3,4,5};
    std::array<int,5> array2 = array1; //正确，array支持拷贝。


    std::array<int,5> array3;
    array3.swap(array1);// 比拷贝快。


}
