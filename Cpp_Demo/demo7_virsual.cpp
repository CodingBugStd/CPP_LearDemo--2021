#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/************************************************************
 * 虚方法
 * new关键字可以理解为malloc()函数的进一步封装版本
 * delete关键字可以理解为free()函数的进一步封装版本
 * 
 * 父类的指针可以通过new关键字定义为指向子类实例的指针,但是无法调用
 * 子类的方法,就算子类对父类的方法进行了覆盖,调用的也是父类的被覆盖
 * 方法,这是编译器优化运行速度所导致的,可以将父类的被覆盖函数声明为
 * 虚方法的方式,使指针调用的是子类的方法!
 * 子类的指针无法通过new关键字定义为父类实例的指针!!!
 * virtual(虚拟的) 关键字 ->(可简单理解为,可被覆盖的,析构器除外)
 * 尽可能多的定义虚方法,它只会影响运行速度
 * (为了节省资源,只有当类是基类时,才声明类里面的某些方法为虚方法)
 *                      2021/7/21 CodingBugStd
*************************************************************/

class Point
{
public:
    friend class ExPoint;
    Point(void);
    Point(int x,int y,string name);
    ~Point();
    static int Get_Count(void);
    virtual void Show_Position(void);
    virtual void Move_Position(int x,int y);
protected:
    static unsigned short pointCount;
    string name;
private:
    int x;
    int y;
};
class ExPoint:public Point
{
public:
    ExPoint(void);
    ExPoint(int x,int y,int z,string name);
    void Show_Position(void);
    void Move_Position(int x,int y);
private:
    int z;
};
ExPoint::ExPoint(void):Point(){z=0;}
ExPoint::ExPoint(int x,int y,int z,string name):Point(x,y,name){this->z = z;}
void ExPoint::Move_Position(int x,int y)
{
    Point::Move_Position(x,y);
    this->z += 100;
}
void ExPoint::Show_Position(void)
{
    cout<<"name: "<<name<<endl;
    cout<<x<<'\t'<<y<<'\t'<<z<<endl;
}
unsigned short Point::pointCount = 0;
Point::Point(void)
{
    pointCount++;
    x = y = 0;
    name = "No Name";
}
Point::Point(int x,int y,string name)
{
    pointCount++;
    this->x = x;
    this->y = y;
    this->name = name;
}
Point::~Point()
{
    pointCount--;
}
void Point::Show_Position(void)
{
    cout<<"Name: "<<name<<endl;
    cout<<x<<"\t"<<y<<endl;
}
void Point::Move_Position(int x,int y)
{
    this->x += x;
    this->y += y;
}
int Point::Get_Count(void){return pointCount;}

int main(void)
{
    Point *ptr1;
    Point *ptr2;
    ptr1 = new ExPoint;
    ptr2 = new Point;
    ptr1->Move_Position(1,1);
    ptr1->Show_Position();
    ptr2->Show_Position();
    delete ptr1;
    delete ptr2;
    system("pause");
    return 0;
}
