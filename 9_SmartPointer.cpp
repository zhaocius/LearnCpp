#include <memory>
#include <iostream>
#include <vector>

struct SP_Test
{
    int a, b;
    int *p;

    void hello();

    SP_Test()
    {
        p = (int *) malloc(sizeof(int) * 100000);
    }

    SP_Test(int a, int b)
    {
        this->a = a;
        this->b = b;
        p = (int *) malloc(sizeof(int) * 100000);
    }

    ~SP_Test()
    {
        free(p);
    }
};

//拥有管理内存的所有权，没有拷贝构造函数、只有移动构造函数、不能多个unique_ptr对象共享一段内存。可自定义delete函数。
//不支持普通的拷贝或者赋值操作
void unique_ptr_test()
{
    SP_Test *test = new SP_Test();
    std::unique_ptr<SP_Test> up(test); //key 先普通指针，再智能指针

    std::unique_ptr<SP_Test> up0(new SP_Test()); //key 直接使用
    std::unique_ptr<SP_Test> up1 = std::make_unique<SP_Test>(); //key 使用make_unique代替new

    std::unique_ptr<SP_Test> up4 = std::make_unique<SP_Test>(1, 2); //key 使用make_unique代替new

    std::unique_ptr<std::string> up5 = std::make_unique<std::string>(2, 'c'); //key 使用make_unique代替new

    std::vector<std::string> list = {"1", "2"};
    auto up6 = std::make_unique<std::vector<std::string>>(list);

    std::unique_ptr<SP_Test> up2(up.release()); //key 将up释放，并赋给up3。

    std::unique_ptr<SP_Test> up3;
    up3.reset(up1.release()); //key 赋值方案1： 将up3释放，up4重置为up3。
    up3 = std::move(up1);  //key 赋值方案2： move




//    std::unique_ptr<SP_Test>up4(up); //key 不支持拷贝。
//    std::unique_ptr<SP_Test>up5 = up; //key 不支持赋值。


    std::unique_ptr<SP_Test[]> tests(new SP_Test[3]);


}

//多个shared_ptr对象共享一段内存,计数为0时，内存被删除。可自定义delete函数。
void shared_ptr_test()
{
    SP_Test *test = new SP_Test();
    std::shared_ptr<SP_Test> sp(test);  //绑定已有的指针。最好不好混合使用普通指针和智能指针。

    std::shared_ptr<std::string> sp1 = std::make_shared<std::string>(9, 'c'); //make_shared生成指针

    std::shared_ptr<std::string> sp2(new std::string("ccc")); //直接初始化，

    sp2.reset();  //

//    std::shared_ptr<std::string> sp3 = new std::string("ccc"); //不能使用这种方式初始化

//    std::shared_ptr<std::string> sp4 = sp; //不能使用这种方式初始化

//    std::shared_ptr<std::string> sp5(sp); //不能使用这种方式初始化


}


void process(std::shared_ptr<int> sp)
{
    //使用sp
} //sp离开作用域，被销毁


//不要混合使用普通指针和智能指针。
void shared_ptr_test1()
{

    std::shared_ptr<int> p(new int(43)); //引用计数为1
    process(p); //在process 中引用计数为2
    //现在计数为1
    int i = *p;  //正确

    int *x(new int(1024));
    process(std::shared_ptr<int>(x)); //进入process,出来后内存被释放。
    int j = *x;  //未定义，x是空悬指针。 被智能指针接管后， 就不要再使用内置指针了。

}