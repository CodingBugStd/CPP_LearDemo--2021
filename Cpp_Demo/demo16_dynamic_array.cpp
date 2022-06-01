#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/*****************************************
 * p[n] 与 *(p+n) 等价
 * 因为数组在编译器的视角下
 * 数组名[下标] = *(数组名+下标)
 * 数组名 -> 指向数组基类型的一个指针
 * 数组访问 和 解地址 原理相同!
 * 注意:地址偏移量=基类型大小 基类型大小与操
 * 作系统和硬件有关,所以经常使用sizeof().
 * 虽然数组名是一个指针,但是使用sizeof()时,
 * 返回的是整个数组的大小,一个指针通过new分配
 * 一段动态数组时,使用sizeof()返回的不是动态
 * 数组的大小,而是指针的大小!!
 * **************************************
 * 使用动态数组时,释放内存需要告知释放内存的
 * 大小
 * 申请: p = new typeName[count];
 * 释放: delete [count]p;
 * count的值非常重要,因为释放内存时不能通过p
 * 删除整个动态数组!需要count来告诉编译器!
 *  2021/7/26   CodingBugStd
*****************************************/

int main(void)
{
    int count = 10;
    int arry[10];
    int*p;
    p = new int[count];
    cout<<sizeof(p)<<endl;
    cout<<sizeof(arry)<<endl;
    p[0] = 160;
    p[9] = 111;
    cout<<p[0]<<endl<<p[9]<<endl;
    delete []p;
    cout<<p[9]<<endl;
    system("pause");
    return 0;
}
