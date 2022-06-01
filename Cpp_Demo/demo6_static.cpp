#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/************************************************************************************
 * 子类方法覆盖父类方法 就算定义的参数不同也会覆盖
 * 子类方法重载父类方法 没有重载一说,只能使用using BaseClass::方法名;然后定义"重载"方法
 * 子类在方法中使用父类的方法需要加上父类域(有些子类方法需要访问父类的private成员,则需要
 * 调用父类的方法(接口)来实现访问,或者声明子类为父类的friend class来实现访问)
 *                          2021/7/20   CodingBugStd
***********************************************************************************/

class Point
{
public:
    friend class ExPoint;
    Point(void);
    Point(int x,int y,string name);
    ~Point(void);
    void Show_Position(void);
    void Move_Position(int x,int y);
    static unsigned short ReadPointNum(void);
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
    //如果子类定义了父类的同名方法,则无法调用父类的同名方法(既覆盖)
    //可以使用 using BaseClass::方法名; 语句来使用父类的方法
    //使用后父类的方法可以被覆盖和重载
    using Point::Move_Position;
    void Move_Position(int x,int y,int z);
    void Show_Position(void);
private:
    int z;
};

ExPoint::ExPoint(void):Point(){z=0;}
ExPoint::ExPoint(int x,int y,int z,string name):Point(x,y,name){this->z = z;}
void ExPoint::Move_Position(int x,int y,int z)
{
    //子类在方法中使用父类的方法需要加上父类域
    //Point::Move_Position(x,y);
    this->x += x;
    this->y += y;
    this->z += z;
}

void ExPoint::Show_Position(void)
{
    Point::Show_Position();
    cout<<"z:"<<z<<endl;
}

unsigned short Point::pointCount = 0;

void Point::Show_Position(void)
{
    cout<<"PointName:"<<name<<endl;
    cout<<"x:"<<x<<"\ty:"<<y<<endl;
}

void Point::Move_Position(int x,int y)
{
    this->x += x;
    this->y += y;
}

Point::~Point(void)
{
    pointCount--;
}

unsigned short Point::ReadPointNum(void)
{
    return pointCount;
}

Point::Point(int x,int y,string name)
{
    this->x = x;
    this->y = y;
    this->name = name;
    pointCount++;
}

Point::Point(void)
{
    x = y = 0;
    name = "NoName";
    pointCount++;
}

int main(void)
{
    ExPoint a;
    a.Move_Position(12,1);      //使用的是父类的Move_Position方法
    a.Move_Position(0,0,12);    //使用的是子类重载父类的Move_Position()方法
    a.Show_Position();
    system("pause");
    return 0;
}
