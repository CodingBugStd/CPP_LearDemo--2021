#include <iostream>
#include <cmath>
#include <cstdlib>

/*******************************
 * C++ 复习
 * Point ExPoint Line LineCount类
 * 2021/10/29
*******************************/

class Point;
class ExPoint;
class Vector;
class Line;
//对<<重载,返回ostream&(&表示引用)类型
//cout<<a<<endl; -> 如果不返回ostream的引用
//连续的<<不会按照预期在控制台上打印
//cout是ostream的一个对象
std::ostream& operator<<(std::ostream&os,Point p);
std::ostream& operator<<(std::ostream*os,ExPoint p);

class Point
{
friend class ExPoint;
friend class Vector;
public:
    Point(void);
    Point(double x,double y);
    double X(void);
    double Y(void);
    void print(void);       //打印坐标
    //给Point类加法运算定义
    //返回值Point
    Point operator+(Point p);
private:
    double x;
    double y;
};

class Vector : public Point
{
public:
    Vector();
    Vector(Point p);
    Vector(double x,double y);
    double len(void);
};
Vector::Vector():Point(){}
Vector::Vector(double x,double y):Point(x,y){}
Vector::Vector(Point p){x=p.x;y=p.y;}

class ExPoint : public Point
{
public:
    ExPoint();
    ExPoint(double x,double y,double z);
    ExPoint(Point p,double z);
    void print(void);
    double Z(void);
    ExPoint operator+(ExPoint p);
private:
    double z;
};

void Point::print(void){std::cout<<"x="<<x<<" y="<<y<<std::endl;}   //打印Point
double Point::X(){return x;};      ////坐标返回
double Point::Y(){return y;};
Point::Point(){x = 0;y = 0;}        //无参Point构造函数
Point::Point(double x,double y){this->x = x;this->y = y;}     //有参Point构造函数

Point Point::operator+(Point p)
{
    int x = this->x + p.x;
    int y = this->y + p.y;
    return Point(x,y);
}

ExPoint::ExPoint():Point(){z=0;}
ExPoint::ExPoint(Point p,double z){this->x = p.X();this->y = p.Y();this->z = z;}
ExPoint::ExPoint(double x,double y,double z):Point(x,y){this->z = z;}
double ExPoint::Z(){return z;}

double Vector::len(void)
{
    return std::sqrt(x*x+y*y);
}

ExPoint ExPoint::operator+(ExPoint p)
{ 
    return ExPoint(this->x+p.x,this->y+p.y,this->z+p.z);
}
void ExPoint::print(){std::cout<<"x="<<x<<" y="<<y<<" z="<<z<<std::endl;}


//'<<'运算符重载
//左边ostream对象的(引用),右边Point对象
//返回ostream(引用)
std::ostream& operator<<(std::ostream&os,Point p)
{
    os<<"("<<p.X()<<','<<p.Y()<<')';
    return os;
}
std::ostream& operator<<(std::ostream&os,ExPoint p)
{
    os<<"("<<p.X()<<','<<p.Y()<<','<<p.Z()<<')';
    return os;
}


int main(void)
{
    using namespace std;

    Point a(1.8,1);
    Vector v(a);
    ExPoint*b;
    ExPoint c;

    b = new ExPoint(a,0);

    cout<<v.len()<<endl;
    cout<<*b+*b<<endl;
    cout<<b->X()<<endl;
    cout<<b->Y()<<endl;
    cout<<b->Z()<<endl;

    system("pause");
    return 0;
}
