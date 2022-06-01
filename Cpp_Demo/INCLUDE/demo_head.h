#ifndef _DEMO_HEAD_H_
#define _DEMO_HEAD_H_

#include <iostream>
#include <cmath>
#include <string>

/*******************************************
Creat by 庞碧璋
Github: https://github.com/CodingBugStd
csdn:   https://blog.csdn.net/RampagePBZ
fileType:c++head
Encoding: utf-8
namespace:point
date: 2021/7/29
平面点 空间点
********************************************/

namespace point
{

class Point;
class ExPoint;

static int a = 16;

class Point
{
friend std::ostream& operator<<(std::ostream&os,Point&p);
friend class ExPoint;
public:
    Point(void);
    Point(int x,int y);
    Point(int x,int y,std::string name);
    double GetLen(Point&p);
    double GetLen(ExPoint&p);
protected:
    int x;
    int y;
    std::string name;
};

class ExPoint:public Point
{
friend std::ostream& operator<<(std::ostream&os,ExPoint&a);
friend class Point;
public:
    ExPoint(void);
    ExPoint(int x,int y,int z);
    ExPoint(int x,int y,int z,std::string name);
    double GetLen(Point&p);
    double GetLen(ExPoint&p);
protected:
    int z;
};

std::ostream& operator<<(std::ostream&os,Point&a);
std::ostream& operator<<(std::ostream&os,ExPoint&a);

} // namespace name

#endif
