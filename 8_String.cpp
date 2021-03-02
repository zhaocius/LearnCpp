#include <iostream>
#include <string>
void string()
{
    char greeting[6]={'H','e','l','l','o','\0'};
    char greeting1[]="helloworld";
    const char * greeting2 = "helloworld";   //建议在把指针初始化为字符串字面 量时使用const限定符:

    char str1[11]="hello";
    char str2[11]="world";
    char str3[11];

    printf("%d \n",strlen(str1));    //字符串长度 strlen


    strcpy(str3,str1);  //字符串复制
    strncpy(str3,str1,sizeof(str3)-1);  //避免str1太长，str3超出

    strcat(str1,str2);  //字符串连接
    strncat(str1,str2,sizeof(str1)-strlen(str1)-1);  //避免str2太长，连结后str1超出

    printf("%d",str1<str2);  //key 表达式无意义，比较两个无关地址
    printf("%d \n ",strcmp(str1,str2)<0); //字符串比较 strcap ,和string1<string2的意义一样。

    std::string str4 = "hello";  //拷贝初始化
    std::string str5 = "world";
    std::string str6 = str4+str5;
    printf("%d \n",str6.size());     //字符串长度  size()
    for(auto beg = str6.begin();beg != str6.end();++beg){  //key 使用iter遍历
        *beg = std::toupper(*beg);
    }
    printf("%s \n", str6.c_str());
    for(auto &c:str6){   //key 使用foreach遍历，使用引用
        c = std::tolower(c);
    }
    printf("%s \n", str6.c_str());

    for(auto c:str6){  //key 使用foreach遍历，使用变量
        printf("%c \n", c);
    }


    printf("%d",str4<str5);  //key 表达式有意义，比较string大小。



    std::string str7 = "tset";
    std::string str8 = str7+"common";
//    std::string str9 ="common"+"tset1"; //key 不能直接使用字符串。

    std::string str11(greeting2); //正确 直接初始化
    std::string str12 = str11.substr(0,5); // 返回的是原始string的副本

    auto pos1 = str11.find("ll");//返回第一个ll出现的位置
    auto pos2 = str11.rfind("ll"); //返回最后一个ll出现的位置

    std::string str13("0123456789");
    std::string str14("rrrrrr2d3");
    std::string str17(10,'s');


    auto pos3 = str14.find_first_of(str13,0);

    int before = 32;
    std::string str15 = std::to_string(before);
    int after = std::stoi(str15);

    long before1 = 32L;
    std::string str16 = std::to_string(before1);
    long after1 = std::stol(str16);







}



