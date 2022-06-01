#include <iostream>
#include <string>
#include <cstdlib>

/***********************************
 * 模板类声明也需要template关键字
 * 模板类实例化的时候必须指定类型
 * className<type>
 * 模板类的实现也需要template关键字
 *  2021/7/31   CodingBugStd
**********************************/

//声明模板类
template <class T>
class PointLink;
//声明模板类的符号重载函数
template <class T>
std::ostream& operator<<(std::ostream&os,PointLink<T> &a);

//定义模板类
template <class T>
class PointLink     //路径记录类
{

//声明<<重载函数为友元函数
template <class U>  //'T'已经使用过了!!
friend std::ostream& operator<<(std::ostream&os,PointLink<U> &a);

public: 
    PointLink(T x,T y);
    ~PointLink();
    void AddStep(T x,T y);
protected:
    T startPos[2];
    T thatPos[2];
    T*stepRecord[2];
    unsigned int stepCount;
};

template <class T>
PointLink<T>::PointLink(T x,T y)
{
    startPos[0] = thatPos[0] = x;
    startPos[1] = thatPos[0] = y;
    stepCount = 0;
    stepRecord[0] = new T[stepCount];
    stepRecord[1] = new T[stepCount];
}

template <class T>
PointLink<T>::~PointLink()
{
    delete []stepRecord[0];
    delete []stepRecord[1];
}

template <class T>
void PointLink<T>::AddStep(T x,T y)
{
    T*tempRecord[2];
    stepCount++;
    thatPos[0] += x;
    thatPos[1] += y;
    tempRecord[0] = new T[stepCount];
    tempRecord[1] = new T[stepCount];
    *(tempRecord[0] + stepCount - 1) = x;
    *(tempRecord[1] + stepCount - 1) = y;
    for(int temp=0;temp<stepCount-1;temp++)
    {
        *(tempRecord[0] + stepCount) = *(stepRecord[0] + stepCount);
        *(tempRecord[1] + stepCount) = *(stepRecord[1] + stepCount);
    }
    delete []stepRecord[0];
    delete []stepRecord[1];
    stepRecord[0] = tempRecord[0];
    stepRecord[1] = tempRecord[1];
}

template <class T>
std::ostream& operator<<(std::ostream&os,PointLink<T> &a)
{
    using namespace std;
    T Position[2];
    Position[0] = a.startPos[0];
    Position[1] = a.startPos[1];
    os<<"Pos"<<"("<<Position[0]<<","<<Position[1]<<")"<<endl;
    for(int temp=0;temp<a.stepCount;temp++)
    {
    Position[0] += *(a.stepRecord[0] + temp);
    Position[1] += *(a.stepRecord[1] + temp);
    os<<"Pos"<<"("<<Position[0]<<","<<Position[1]<<")"<<endl;
    }
    os<<a.thatPos[0] <<endl << a.thatPos[1];
    return os;
}

int main(void)
{
    using namespace std;
    PointLink<double>*a;
    a = new PointLink<double>(1.7,6.2);
    a->AddStep(17.0,16.0);
    a->AddStep(-1.1,16.2);
    a->AddStep(0.4,78.8);
    cout<<*a<<endl;
    delete a;
    system("pause");
    return 0;
}
