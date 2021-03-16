#include <iostream>
void cast_test(){

    /*
     *
     static_cast
用于非多态类型的转换
不执行运行时类型检查（转换安全性不如 dynamic_cast）
通常用于转换数值数据类型（如 float -> int）
可以在整个类层次结构中移动指针，子类转化为父类安全（向上转换），父类转化为子类不安全（因为子类可能有不在父类的字段或方法）
向上转换是一种隐式转换。

dynamic_cast
用于多态类型的转换
执行行运行时类型检查
只适用于指针或引用
对不明确的指针的转换将失败（返回 nullptr），但不引发异常
可以在整个类层次结构中移动指针，包括向上转换、向下转换


const_cast
用于删除 const、volatile 和 __unaligned 特性（如将 const int 类型转换为 int 类型 ）


reinterpret_cast
用于位的简单重新解释
滥用 reinterpret_cast 运算符可能很容易带来风险。 除非所需转换本身是低级别的，否则应使用其他强制转换运算符之一。
允许将任何指针转换为任何其他指针类型（如 char* 到 int* 或 One_class* 到 Unrelated_class* 之类的转换，但其本身并不安全）
也允许将任何整数类型转换为任何指针类型以及反向转换。
reinterpret_cast 运算符不能丢掉 const、volatile 或 __unaligned 特性。
reinterpret_cast 的一个实际用途是在哈希函数中，即，通过让两个不同的值几乎不以相同的索引结尾的方式将值映射到索引。
     *
     * */

    int a = 3;
    int b = 5;
    double c = static_cast<double>(b)/a;  // static_cast 较大算数类型赋给小类型
    std::cout<< c << std::endl;

    void *p = &a;
    int * pp = static_cast<int*>(p);  //static_cast 找回void* 指针为 int *
    std::cout<< *pp << std::endl;


    //const_cast


    //reinterpret_cast 运行时才检查
    int *ip;
    char *pc = reinterpret_cast<char *>(ip);   // C写法 char* pc = (char *)ip
    std::string str(pc); // 报错！！！！！ pc真正指向的是一个int


}

