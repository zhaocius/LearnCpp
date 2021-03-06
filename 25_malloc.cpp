//
// Created by zhaozi on 2020/10/31.
//

#include <cstdio>
#include <cstdlib>
#include "common/structs.h"

void malloc_test(){
    double *ptd;
    ptd=(double *)malloc(30*sizeof(double));
    if (ptd == NULL)
    {
        printf("未能分配到要求的内存");
    }
    free(ptd);


    //calloc()函数把块中的所有位都设置为0
    int *p;
    p=(int *)calloc(30,sizeof(int));
    if(NULL==p){
        printf("未能分配到要求的内存");
    }
    free(p);

    //变长数组，和动态申请内存不同，变长数组是自动存储类型，离开块时自动释放，不用free。
    int n;
    scanf("%d",&n);
    int ar[n];

    //二维数组：
    int o=3;
    int m;
    scanf("%d",&m);
    int (*p1)[m];
//    p1=(int(*)[m])malloc(o*m*sizeof(int));   //key 不可以这样写
}

void malloc_test1() {
    Book *ptd;
    ptd = (Book *) malloc(sizeof(Book));
    if (ptd == NULL) {
        printf("未能分配到要求的内存");
    }
    free(ptd);
}

