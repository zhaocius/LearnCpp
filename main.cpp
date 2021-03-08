#include <cstdio>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <time.h>
#include <sstream>
#include <fstream>
#include <map>
#include <future>
#include <zconf.h>

#include "common/Singleton.h"
#include "common/structs.h"


int main()
{
    printf("hello world");

    Screen scr1,scr2;
    scr1=scr2;
    Screen scr3(scr1);
    return 0;
}

