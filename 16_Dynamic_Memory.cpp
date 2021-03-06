#include <iostream>
#include "common/structs.h"

//new 和malloc()
//key 不推荐malloc()，new不仅分配了内存，还创建了对象。
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


