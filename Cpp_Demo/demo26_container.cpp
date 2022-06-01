#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

/**************************************
 * 能存放两个以上的数据的成员称之为容器
 * 数组是C++唯一提供的容器
 * C99标准后加入了STL库,里面提供了丰富的
 * 容器和算法
 *  2021/8/1    CodingBugStd
**************************************/

int main(void)
{
    using namespace std;
    vector<string> a;       //vector->向量容器 本质是一个模板类
    a.push_back("Test");    //添加Test向量成员
    a.push_back("Slll");    //添加Slll向量成员
    cout<<a.size()<<endl;   //.size方法返回容器中的成员个数

    for(int temp=0;temp<a.size();temp++)
        cout<<a[temp]<<endl;    //可以通过数组来访问容器中的成员

    system("pause");
    return 0;
}

