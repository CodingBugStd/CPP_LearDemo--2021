#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/*****************************
 * new申请的内存不会因为作用域自
 * 动回收,必须使用delete来释放内
 * 存!因此,使用new申请的内存必须
 * 保存好它的地址,在使用完成后通
 * 过地址释放内存!
 * 动态内存无视作用域,可以通过指
 * 针在任何位置访问它.相比于全局
 * 变量和局部变量更灵活,但是需要
 * 注意返还内存.
 * Tips:
 * 保存动态指针的变量还是受到作
 * 用域影响.
 *  2021/7/28   CodingBugStd
*****************************/

class Point
{
public:
    Point(int x,int y,string name);
protected:
    int x;
    int y;
    string name;
};
Point::Point(int x,int y,string name)
{
    this->x = x;
    this->y = y;
    this->name = name;
}

Point* NewClass(void)
{
    Point*a;
    a = new Point(1,1,"aaa");
    return a;
}

int main(void)
{
    Point* a = NewClass();
    delete a;
    system("pause");
    return 0;
}
