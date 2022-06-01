#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/**********************************
 * 运算符重载
 * 关键字 operator
 * 返回类型 operator 运算符 (参数) 
 * 一般返回类型和参数为该class的实例
 * a opr b 运算符左边的将会当成隐性传递
 * 进入重载函数,右边相当于第一个参数
 * -------------------------------
 * 本例子中,打印了两次Point Delete
 * 一次是运算符重载中k的析构器打印的
 * 一次是传入参数d的析构器打印的.
 * c=a+b; 先创建了一个d和k的Point
 * 实例,并且在返回时全部析构,可以
 * 在运算符重载函数中声明参数为引
 * 用参数来避免建立d,减少内存占用.
 *  2021/7/21   CodingBugStd
**********************************/

class Point
{
public:
    Point(void);
    Point(int x,int y);
    ~Point();
    Point operator+(Point d);
    void ShowPoint(void);
private:
    int x;
    int y;
};
Point::~Point(void)
{
    cout<<"Point delet"<<endl;
}
void Point::ShowPoint(void)
{
    cout<<"("<<x<<','<<y<<')'<<endl;
}
Point::Point(int x,int y)
{
    this->x = x;
    this->y = y;
}
Point::Point(void)
{
    x = y = 0;
}
Point Point::operator+(Point d)
{
    Point k;
    k.x = x + d.x;
    k.y = y + d.y; 
    return k;
}

int main(void)
{
    Point a(1,1),b(3,7),c;
    Point* addr1 = new Point(1,1);
    c.ShowPoint();
    c = a + *addr1;
    c.ShowPoint();
    system("pause");
    return 0;
}

