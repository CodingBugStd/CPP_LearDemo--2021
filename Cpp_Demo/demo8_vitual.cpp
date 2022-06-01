#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/******************************************************
 * 析构器--虚方法
 * 如果指针类型是父类,new的是子类实例,那么
 * 实例在删除过程中不会调用子类的析构器,要
 * 将父类的析构器定义为virtual,在删除过程
 * 中两者的析构器才会全部调用
 * 一般析构器都定义为virtual,这样防止子类
 * 在析构时没有调用子类的析构器
 * * 子类构造器可以使用 Sub::Sub(xxx):Bace(xxx){}
 * * 的方式,这样构造时可以调用父类构造器的重载
 *              2021/7/21   CodingBugStd
*******************************************************/

class BaceClass
{
public:
    BaceClass(void);
    ~BaceClass();
    void ShowCount(void);
protected:
    static int Count;
};

int BaceClass::Count = 0;

void BaceClass::ShowCount(void)
{
    cout<<Count<<endl;
}

BaceClass::BaceClass(void)
{
    cout<<"BaceClass Maker Run"<<endl;
    Count++;
}

BaceClass::~BaceClass(void)
{
    cout<<"BaceClass Clearer Run"<<endl;
    Count--;
}

class SubClass:public BaceClass
{
public:
    SubClass(void);
    ~SubClass();
    void Aka(void);
};

void SubClass::Aka(void)
{

}

SubClass::SubClass(void):BaceClass()
{
    cout<<"SubClass Maker Run"<<endl;
}

SubClass::~SubClass(void)
{
    cout<<"SubClass Clearer Run"<<endl;
}

int main(void)
{
    BaceClass*ptr;
    cout<<"BaseClass ptr"<<endl;
    ptr = new SubClass;
    ptr->ShowCount();
    delete ptr;

    SubClass*ptr2;
    cout<<"SubClass ptr"<<endl;
    ptr2 = new SubClass;
    ptr2->ShowCount();
    delete ptr;

    system("pause");
    return 0;
}
