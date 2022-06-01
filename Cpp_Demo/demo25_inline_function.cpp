#include <iostream>
#include <cstdlib>
#include <string>

/***************************
 * 内联函数
 * 源代码层面具有函数的结构
 * 编译后却不具备函数的性质
 * 类似与宏定义
 * 内联模板
 * 声明类的时候直接将定义也写
 * 在声明中
 * 内联模板可以减少代码量,对
 * 模板类的书写十分方便
 * 2021/8/1    CodingBugStd
***************************/

class Person
{
public:
    Person(std::string name)
    {
        this->name = name;
    }
    void ShowName(void)
    {
        std::cout<<name<<std::endl;
    }
protected:
    std::string name;
};

inline void swap(int&a,int&b)
{
    int c = a;
    a = b;
    b = c;
}

int main(void)
{
    using namespace std;
    int a , b;
    Person l("Fuck");
    a = 16;
    b = 11;
    swap(a,b);
    cout<<a<<endl<<b<<endl;
    l.ShowName();
    system("pause");
    return 0;
}
