#include <stdio.h>
#include <iostream>


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


    int *i[10]; //key 含有10个整形指针的数组；
    int (*j)[10]; //key 指向一个数组的指针


    int *p = new int[6]{1,2,3,4,5,6};  //动态数组









}
