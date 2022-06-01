#include "demo_head.h"

namespace point
{

Point::Point(void)
{
    x = y = 0;
    name = "noName";
}

Point::Point(int x,int y)
{
    this->x = x;
    this->y = y;
    name = "noName";
}

Point::Point(int x,int y,std::string name)
{
    this->x = x;
    this->y = y;
    this->name = name;
}

ExPoint::ExPoint(void):Point(){}
ExPoint::ExPoint(int x,int y,int z):Point(x,y){this->z = z;}
ExPoint::ExPoint(int x,int y,int z,std::string name):Point(x,y,name){this->z = z;}

double Point::GetLen(Point&a)
{
    double len;
    int lx,ly;
    lx = a.x - x;
    ly = a.y - y;
    len = lx*lx + ly*ly;
    len = std::sqrt(len);
    return len;
}

double Point::GetLen(ExPoint&a)
{
    double len;
    int lx,ly;
    lx = a.x - x;
    ly = a.y - y;
    len = lx*lx + ly*ly + a.z*a.z;
    len = std::sqrt(len);
    return len;
}

double ExPoint::GetLen(ExPoint&a)
{
    double len;
    int lx,ly,lz;
    lx = a.x - x;
    ly = a.y - y;
    lz = a.z - z;
    len = lx*lx + ly*ly + lz*lz;
    len = std::sqrt(len);
    return len;
}

double ExPoint::GetLen(Point&p)
{
    double len;
    int lx,ly;
    lx = x - p.x;
    ly = y - p.y;
    len = lx*lx + ly*ly + z*z;

}

std::ostream& operator<<(std::ostream&os,Point&p)
{
    os<<p.name<<'('<<p.x<<','<<p.y<<')';
    return os;
}

std::ostream& operator<<(std::ostream&os,ExPoint&p)
{
    os<<p.name<<'('<<p.x<<','<<p.y<<','<<p.y<<')';
    return os;
}


} // namespace Point

