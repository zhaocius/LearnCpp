#include <iostream>
#include <fstream>
void io(){
    int  a,b;
    std::cin >> a >> b;
    std::cout << "a == "<<a <<",b == "<< b  << std::endl;
}

void io1(){
    int a,b;
    scanf("%d,%d",&a,&b);  //输入的时候输入 1,2 ，基本类型，需要加 &
    printf("a == %d, b == %d \n",a,b);

    char name[50];
    scanf("%s",name);    //读入字符串数组，不需要加 &
    printf("name == %s \n",name);

}

void io2(){
    int a;
    a=getchar();
    putchar(a);
}

std::string read_file(char *file_name) {
    std::string str;
    std::ifstream infile;
    infile.open(file_name);
    infile >> str;
    infile.close();
    return str;
}

void write_string(char *file_name) {
    std::string str = "hello,world";
    std::ofstream outfile;
    outfile.open("/sdcard/_TestCases/bctc-petrol-pro/2020_08_31/common.yuv");
    outfile << str << std::endl;
    outfile.close();
}


void write_char(){
    char chars[] = {'a','b','c'};
    FILE *fp;
    fp = fopen( "/sdcard/_TestCases/bctc-petrol-pro/2020_08_31/common.yuv" , "w" );
    fwrite(chars, 640 * 480 * 3 / 2 , 1, fp );
    fclose(fp);
}
