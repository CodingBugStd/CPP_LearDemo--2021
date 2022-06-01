#include <iostream>
#include <string>
#include <cstdlib>
#include "INCLUDE/demo_head.h"

using namespace std;

/******************************
 * 模块化编程
 * libName.h负责声明
 * libName.cpp负责实现
 * vscode可以通过task.json中更改
 * g++参数来编译多个文件
 *  2021/7/29   CodingBugStd
******************************/

int main(void)
{
    Point a(1,30);
    ExPoint b(2,4,1);
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<"ab distance:"<<a.GetLen(b)<<endl;
    system("pause");
    return 0;
}
