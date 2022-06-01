#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/*******************************************************
 * public(公共的):任何对象和成员都可以访问
 * protected(保护的):可以被类本身和子类成员函数访问
 * private(私有的):只能由类本身的成员函数或者友元类访问
 *              2021/7/20   CodingBugStd
*******************************************************/

class BaseClass
{
    public:
    BaseClass(void);
    BaseClass(string name);
    void Show_Name(void);
    private:
    string name;
};

void BaseClass::Show_Name(void)
{
    cout<<"name:"<<name<<endl;
}

BaseClass::BaseClass(void)
{
    cout<<"BaseClass Maker"<<endl;
    cout<<"BaseClass Name:";
    getline(cin,this->name);
}

BaseClass::BaseClass(string name)
{
    cout<<"BaseClass Maker"<<endl;
    this->name = name;
}

class SubClass:public BaseClass
{
    public:
    SubClass(void);
    SubClass(string name);
};

SubClass::SubClass(void):BaseClass()
{
    cout<<"SubClass Maker"<<endl;
}

SubClass::SubClass(string name):BaseClass(name)
{
    cout<<"SubClass Maker"<<endl;
}

int main(void)
{
    SubClass a;
    a.Show_Name();
    system("pause");
    return 0;
}
