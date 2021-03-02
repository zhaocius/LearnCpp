#include <iostream>
#include <vector>

//vector的capacity和size
//size指真实占用的大小，
//capacity是指发生realloc之前能允许的最大元素数、
//reserve(n)只修改capacity的值，
//resize(n)真正扩容，
//key []下标可以访问容器内对象，但是可能越界。而且不能用于添加元素

struct Vec_Test {
    int a;
    float b;
};

void vector_test() {
    std::vector<int> vec;
    for (int i = 0; i < 5; i++) {
        vec.push_back(i);
    }
    std::cout << vec.size() << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << vec[i] << std::endl;
    }

    std::vector<int>::iterator v = vec.begin();
    while (v != vec.end()) {
        std::cout << *v << std::endl;
        *v=3; //interator 能改变元素。
        v++;
    }

    std::vector<int>::const_iterator  c_v = vec.begin();
    while (c_v != vec.end()) {
        std::cout << *c_v << std::endl;
//        *c_v=3; //key const_interator 不能改变元素。
        c_v++;
    }

    auto c_v1 = vec.cbegin();
    while (c_v1 != vec.end()) {
        std::cout << *c_v1 << std::endl;
//        *c_v1=3; //key const_interator 不能改变元素。
        c_v1++;
    }

    //key 存放自定义对象，还是存指针好一点，存对象的话，会涉及到拷贝问题。
    std::vector<Vec_Test *> vec1;
    for (int i = 0; i < 5; i++) {
        Vec_Test *t1 = new Vec_Test;
        t1->a = 10;
        t1->b = 12;
        vec1.push_back(t1);
    }

    std::vector<Vec_Test> vec2;
    for (int i = 0; i < 5; i++) {
        Vec_Test t;
        t.a = 10;
        t.b = 12;
        vec2.push_back(t);
    }


    int aaa[4] = {1, 2, 3, 4};
    std::vector<int> vec3(std::begin(aaa), std::end(aaa)); //使用数组初始化vector

    std::vector<int> vec4(15,3);  //小括号，15个元素，每个元素都是3。
    std::vector<int> vec5{15,3};   // 大括号，2个元素， 15 和 3
    std::vector<int> vec6 = vec5;   // 副本
    std::vector<int> vec7(vec6);   // 副本



    //vector pop 和 erase，不改变capicity，只改变size
    //remove改变size，不建议使用
    vec5.erase(vec5.begin() + 1);//erase the 1th element
    vec5.erase(vec5.begin(), vec5.begin() + 1);
    vec5.pop_back();
    for (int i = 0; i < vec5.size(); i++) {
        std::cout << vec5[i] << std::endl;   //下标不会检查范围
    }

    for (int i = 0; i < vec5.size(); i++) {
        std::cout << vec5.at(i) << std::endl;//at()会检查范围,超了会报错。
    }


}