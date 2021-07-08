#include <iostream>
#include "common/structs.h"

//new 和malloc()
//key 不推荐malloc()，new不仅分配了内存，还创建了对象。
void tuple_malloc_and_free()
{
    int SIZE = 10;
    int *p = (int *) malloc(sizeof(int) * SIZE);
    memset(p, 1, sizeof(int) * SIZE);
    std::cout << *p << std::endl;
    free(p);
}

void tuple_new_and_delete()
{
    //一维数组
    char *p = NULL;
    p = new char[10];
    delete[] p;

    //二维数组
    char **array = new char *[3];
    for (int i = 0; i < 3; i++)
    {
        array[i] = new char[3];
    }

    for (int i = 0; i < 3; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}

//key unique_ptr动态分配数组
void tuple_unique_ptr_test()
{
    std::unique_ptr<int[]>up(new int[3]);
    up[0]=1; //up定义了下标运算
}

//key shared_ptr动态分配数组,需要传删除器
void tuple_shared_ptr_test()
{
    std::shared_ptr<int> sp(new int[10](), std::default_delete<int[]>());

}




