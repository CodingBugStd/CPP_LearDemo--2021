#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/***********************************
 * 建立的指针变量要赋值为NULL
 * delete指针后也要设置为NULL
 * 这是为了方便标识那些指针没有被释放
 * 是一个特别重要的编程习惯
 * 
 * 若delete后没有将指针设置成NULL,虽然
 * 指针指向的地址不变,但是地址中储存的值
 * 可能会被覆盖!!
 * 使用new分配内存后,地址中存放了垃圾数
 * 据,我们需要重新赋值为0或者使用class
 * 的构造器重新赋值！！
 * 
 * 有new必有delete,要求成对存在,防止内
 * 存泄漏!!
 * 
 * 如果内存不足,程序会抛出一个std::???类
 * 的异常,可以catch这个异常
 *  2021/7/25   CodingBugStd
***********************************/

class Point;
ostream& operator<<(ostream& os,Point& f);

class Point
{
public:
    Point(void);
    Point(int x,int y);
    Point operator+(Point&a);
    friend ostream& operator<<(ostream& os,Point& f);
private:
    int x;
    int y;
};

ostream& operator<<(ostream& os,Point& f)
{
    os<<'('<<f.x<<','<<f.y<<')';
}

Point::Point(void)
{
    x = y = 0;
}
Point::Point(int x,int y)
{
    this->x = x;
    this->y = y;
}
Point Point::operator+(Point&a)
{
    Point re(a.x+this->x,a.y+this->y);
    return re;
}

int main(void)
{
    void*a;
    int*b;
    Point*p;
    //void*a = NULL;
    //int*b = NULL;
    cout<<"a addr: "<<a<<endl;
    cout<<"b addr: "<<b<<endl;
    cout<<"p addr: "<<p<<endl;
    a = new int;
    b = new int;
    p = new Point(1,1);
    cout<<"a new addr:"<<a<<endl;
    cout<<"b new addr:"<<b<<endl;
    cout<<"p new addr:"<<p<<endl;
    cout<<"*a new:"<<*(int*)a<<endl;
    cout<<"*b new:"<<*b<<endl;
    cout<<"*p new:"<<*p<<endl;
    *(int*)a = 168;
    *b = 45;
    cout<<"*a:"<<*(int*)a<<endl;
    cout<<"*b:"<<*b<<endl;
    cout<<"*p:"<<*p<<endl;
    delete a;
    delete b;
    delete p;
    cout<<"a delete addr:"<<a<<endl;
    cout<<"b delete addr:"<<b<<endl;
    cout<<"p delete addr:"<<p<<endl;
    cout<<"*a delete:"<<*(int*)a<<endl;
    cout<<"*b delete:"<<*b<<endl;
    cout<<"*p delete:"<<*p<<endl;
    a = NULL;
    b = NULL;
    p = NULL;
    system("pause");
    return 0;
}