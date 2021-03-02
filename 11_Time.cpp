//
// Created by zhaozi on 2020/10/21.
//

#include <iostream>
#include <ctime>
#include <time.h>

//使用的标准C的结构体和函数
//tm结构体
void time_test(){
    time_t now =time(0); //返回time_t类型
    char* dt = ctime(&now); //返回char*指针
    std::cout << "本地日期" <<dt << std::endl;

    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    std::cout << "UTC日期" <<dt << std::endl;

    tm *ltm=localtime(&now);
    std::cout << "当前的小时" <<ltm->tm_hour << std::endl;
    std::cout << "当前的分钟" <<ltm->tm_min << std::endl;



    clock_t start,finish;
    double time;
    start=clock();
    std::cout << "测试函数执行时间"<< std::endl;
    finish=clock();    //结束
    time=(double)(finish - start) *1000 / CLOCKS_PER_SEC;
    std::cout << time<< std::endl;





}
