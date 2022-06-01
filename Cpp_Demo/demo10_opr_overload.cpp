#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/*******************************************************
 * 重载<<符号 使Point可以通过cout<<PointClass打印
 * <<的两个运算成员分别是ostream类的引用和Point类的引
 * 用,因为对Point输出的重载没有在ostream类里头声明,所
 * 以要定义为(因此不能使用this指针)
 * std::ostream& operator<<(std::ostream& os,Point& f);
 * 注意:这个重载方法是属于ostream类的,不是Point类的
 *          2021/7/22   CodingBugStd
*******************************************************/

class Point;
std::ostream& operator<<(std::ostream& os,Point& f);

class Point
{
    friend std::ostream& operator<<(std::ostream& os,Point& f);
public:
    Point(void);
    Point(int x,int y);
    Point(int x,int u,string name);
    ~Point();
    Point operator+(Point&d);
    void ShowPoint(void);
protected:
    string name;
private:
    int x;
    int y;
};

Point::Point(int x,int y,string name)
{
    this->x = x;
    this->y = y;
    this->name = name;
}

Point::~Point(void)
{
    cout<<name<<" Point delet"<<endl;
}
void Point::ShowPoint(void)
{
    cout<<name<<"("<<x<<','<<y<<')'<<endl;
}
Point::Point(int x,int y)
{
    name = "NoName";
    this->x = x;
    this->y = y;
}
Point::Point(void)
{
    name = "NoName";
    x = y = 0;
}
Point Point::operator+(Point&d)
{
    Point k;
    k.x = x + d.x;
    k.y = y + d.y; 
    k.name = "Add";
    return k;
}

std::ostream& operator<<(std::ostream& os,Point& f)
{
    os <<f.name<<'('<<f.x<<','<<f.y<<')';
    return os;
}

int main(void)
{
    Point*ptr1,*ptr2;
    Point ptr3(1,1,"ptr3");
    ptr1 = new Point(11,11,"a");
    ptr2 = new Point(10,-50,"b");
    ptr3 = *ptr1 + *ptr2;
    cout<<*ptr1<<*ptr2<<endl;
    cout<<*ptr2<<endl;
    cout<<ptr3<<endl;
    system("pause");
    return 0;
}
