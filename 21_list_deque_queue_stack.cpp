#include <stdio.h>
#include <cstdio>
#include <vector>
#include <list>
#include <forward_list>
#include <queue>
#include <deque>
#include <array>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>

void list_deque_tests(){

    std::list<int> list0;  //双向链表，在任何位置插入/删除操作都很快。
    std::cout<<list0.size()<<std::endl;
    list0.push_back(2);
    list0.push_front(0);

    std::list<int> list1(10,5);  // list 10个元素，每个元素都是5。
    std::list<int> list2;
    list2.assign(list1.begin(),list1.end());  //key 使用list初始化

    int arr[10]={1,2,3,4,5,6,7,8,9,0};
    std::list<int>list3(std::begin(arr),std::end(arr));   //key 使用tuple初始化

    auto val = list2.front(); //第一个元素的引用
    auto val1 = list2.end();//最后一个元素的引用




    std::forward_list<int>forwardList0(10,5); //forward_list 10个元素，每个元素都是5。
    forwardList0.erase_after(forwardList0.begin());


}