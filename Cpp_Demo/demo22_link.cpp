#include <iostream>
#include <string>
#include <cstdlib>
#include "INCLUDE/demo_head.h"

extern int point::a;

/*****************************
 * 使用extern使用其它翻译单元的
 * 变量(注意命名空间)
 *  2021/7/31   CodingBugStd
******************************/

int main(void)
{
    using namespace std;
    cout<<point::a<<endl;
    system("pause");
    return 0;
}
