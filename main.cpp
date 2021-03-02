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
#include "test.cpp"

int main()
{
    myspace::Singleton::GetInstance().setCamereWidth(1);
    printf("%d",myspace::Singleton::GetInstance().getCameraWidth());
    test();
    printf("%d",myspace::Singleton::GetInstance().getCameraWidth());
    return 0;
}

