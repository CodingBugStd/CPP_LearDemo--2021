#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/*******************************************
 * 副本构造器
 * 若一个对象中有指针成员,将它赋值
 * 给一个对象变量后,两个对象的指针
 * 成员指向同一个地址!(逐位赋值)
 * 当删除其中一个对象时(析构器释放
 * 指针),另一个对象的指针成员的内存
 * 也会被释放!当析构第二个对象时就
 * 会出现错误(无法释放已被释放的内存)
 * 解决方案1
 * 重载类的赋值运算符'='来避免
 * 注意:传入的参数要使用引用传递,否
 * 则析构传入参数的时候会把原对象的
 * 指针成员释放掉,同时也应该声明为
 * const,防止篡改'='右边的值!!返回
 * 值为class的引用(引用隐形传递进来
 * 的this).同时需要判断this指针是否
 * 和参数的地址一致,否则会释放指针!
 * 返回值要为this的引用的理由:
 * 如果返回值为void,连等赋值会出现错误(a=b=c)
 * 即a=((b=c)的返回值),a=void出错
 * 所以(b=c)的返回值要是b的引用!!
 * 通过重载赋值运算符不能解决在声明的时候赋值!
 * 方案2 副本构造器!
 * className(const className& cp) -> 本质上是一个构造器
 *  2021/7/26   CodingBugStd
******************************************/

#define UseReload   1      //运算符重载测试

class Point
{
public:
    Point();
    Point(int x,int y);
    Point(const Point&cp);
    ~Point();
    void ShowPoint(void);
    #if UseReload == 1
    Point& operator=(const Point&p);
    #endif
private:
    int*x;
    int*y;
};
Point::Point()
{
    x = new int;
    y = new int;
    *x = *y = 0;
}
Point::Point(int x,int y)
{
    this->x = new int;
    this->y = new int;
    *this->x = x;
    *this->y = y;
}
Point::Point(const Point& cp)
{
    x = new int;
    y = new int;
    *x = *cp.x;
    *y = *cp.y;
}
Point::~Point()
{
    cout<<"delet"<<endl;
    delete x;
    delete y;
}

#if UseReload == 1
Point& Point::operator=(const Point&p)
{
    Point& k = *this;
    if(this == &p)
        return k;
    *this->x = *p.x;
    *this->y = *p.y;
    return k;
}
#endif

void Point::ShowPoint(void)
{
    cout<<"("<<*x<<','<<*y<<')'<<endl;
}

int main(void)
{
    Point *a,*b,*c;
    a = new Point(1,16);
    b = new Point(16,1);
    c = new Point(16,16);
    Point d = *c;
    a->ShowPoint();
    b->ShowPoint();
    c->ShowPoint();
    d.ShowPoint();
    *c = *b = *a = *a;
    a->ShowPoint();
    b->ShowPoint();
    c->ShowPoint();
    d.ShowPoint();
    delete a;
    delete b;
    delete c;
    system("pause");
    return 0;
}
