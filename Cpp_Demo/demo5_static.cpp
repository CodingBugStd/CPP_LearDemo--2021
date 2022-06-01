#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/****************************************************
 * 类中变量声明为static后,需要分配内存才能使用
 * ex: 
 * type className::Static = 0;
 * 静态成员函数不能访问非静态成员函数和非静态数据成员
 *          2021/7/20 CodingBugStd
***************************************************/

class BaseClass
{
    public:
    BaseClass(void);
    BaseClass(string name);
    static void ShowObCount(void);
    protected:
    string objectName;
    private:
    static int baseObCount;
};

class SubClass:public BaseClass
{
    public:
    SubClass(void);
    SubClass(string name);
};

SubClass::SubClass(void):BaseClass(){}
SubClass::SubClass(string name):BaseClass(name){}

int BaseClass::baseObCount = 0;

void BaseClass::ShowObCount(void)
{
    cout<<baseObCount<<endl;
}

BaseClass::BaseClass(string name)
{
    cout<<"Object Name:"<<objectName<<endl;
    baseObCount++;
}

BaseClass::BaseClass(void)
{
    cout<<"Object Name:";
    getline(cin,objectName);
    baseObCount++;
}

int main(void)
{
    SubClass a;
    a.ShowObCount();
    system("pause");
    return 0;
}
