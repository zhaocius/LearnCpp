struct A{
    int c;
}A1;  //A1是一个变量；

struct AA{
    int c;
};
AA A2; //A2是个变量

typedef struct B{
    int c;
}B1;  //B1是一个结构体类型 == struck B

typedef struct {
    int c;
} B2;  //B2是一个结构体类型，可以省略struck的标签

typedef int arr[43];  // arr 就是 int [43]
int * arrP = new arr;

//告诉编译 alias_name是int的另一个名称
typedef int alias_name;
alias_name i=1;

//告诉编译 alias_name1是int的另一个名称
using alias_name1 = int;

alias_name1 j = 1;

