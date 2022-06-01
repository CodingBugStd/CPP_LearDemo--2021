#include <iostream>
#include <string>
#include <cstdlib>
#include "INCLUDE/demo_head.h"

/***************************************
 * 一般不推荐直接使用using namespace
 * 使用多个using namespace时,只要不产生
 * 歧义,可以省略成员前的命名空间
 * point::Point a--> Point a
 * std::cout --> cout
 * namespace的意义在于大项目时解决重名的
 * 问题,对协同分工合作完成项目时十分有用.
 * using nameSpace::name;
 * 可以省略name前的域解析符,只在{}中有效
 * 一般using只用在函数开头使用.
 * Ex:
 * void aka(void)
 * {
 *      using namespace std;
 *      using nameSpace::name;
 *      xxxxxxx;
 * }
 *  2021/7/29   CodingBugStd
***************************************/

using namespace std;
//using point::Point;

int main(void)
{
    using namespace point;
    Point a;
    cout<<a<<endl;
    cout<<"HelloWorld!"<<endl;
    system("pause");
    return 0;
}
