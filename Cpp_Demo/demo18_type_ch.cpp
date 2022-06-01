#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/************************************
 * dynamic_cast<要转换的类名*>(指针)
 * 返回一个指针类型,如果为NULL则表示
 * 类型转换失败
 *  2021/7/28   CodingBugStd
************************************/

class Point
{
friend class ExPoint;
public:
    Point();
    Point(int x,int y,string name);
    virtual void ShowPoint(void);
protected:
    string name;
private:
    int x;
    int y;
};
Point::Point()
{
    x = y = 0;
    name = "noName";
}
Point::Point(int x,int y,string name)
{
    this->x = x;
    this->y = y;
    this->name = name;
}
void Point::ShowPoint(void)
{
    cout<<name<<'('<<x<<','<<y<<')'<<endl;
}

class ExPoint:public Point
{
public:
    ExPoint(int x,int y,int z,string name);
    void ShowPoint(void);
    void ShowX(void);
private:
    int z;
};
ExPoint::ExPoint(int x,int y,int z,string name):Point(x,y,name){this->z = z;}
void ExPoint::ShowPoint(void)
{
    cout<<name<<'('<<x<<','<<y<<','<<z<<')'<<endl;
}
void ExPoint::ShowX(void)
{
    cout<<x<<endl;
}

int main(void)
{
    Point*a = NULL;
    ExPoint*b = NULL;
    a = new ExPoint(1,2,3,"Test");
    b = (ExPoint*)a;
    b = dynamic_cast<ExPoint*>(a);  //相比直接强制类型转换,dynamic_cast带有检查功能
    a = dynamic_cast<Point*>(b);
    if(a==NULL)
    {
        cout<<"err"<<endl;
        system("pause");
        return 0;
    }
    a->ShowPoint();
    b->ShowPoint();
    b->ShowX();
    delete (ExPoint*)a;
    a = b = NULL;
    system("pause");
    return 0;
}
