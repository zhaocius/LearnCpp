#include <stdio.h>
#include <climits>


void var_and_type() {
    bool a = true; //%d
    char char_max = CHAR_MAX;  //%c 8位
    char char_min = CHAR_MIN;  //%c 8位
    printf("%c ",char_max);
    printf("%c ",char_min);


    int int_max = INT_MAX;
    int int_min = INT_MIN;
    unsigned uint_max = UINT_MAX;  //%u 无符号十进制, unsigned 和 signed一起使用， 则signed自动改为unsigned
    size_t e = 1; //%zu
    printf("%d ",int_max);
    printf("%d ",int_min);
    printf("%u ",uint_max);


    float f = 1.0F;  //%f
    printf("%f ",f);


    long l_max = LONG_MAX; // 3L
    long l_min = LONG_MIN;
    unsigned long  ul_max = ULONG_MAX; // 3UL
    printf("%ld ",l_max);
    printf("%ld ",l_min);
    printf("%lu",ul_max);


    long long ll_max = LLONG_MAX;  // 3LL
    long long ll_min = LLONG_MIN;
    unsigned long long ull_max = ULLONG_MAX;// 3ULL
    printf("%lld ",ll_max);
    printf("%lld ",ll_min);
    printf("%llu",ull_max);


    double k = 1.0L;  //%lf
    long double l = 1LL; //%llf;


}



