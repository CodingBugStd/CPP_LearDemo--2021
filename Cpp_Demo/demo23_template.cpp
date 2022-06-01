#include <iostream>
#include <string>
#include <cstdlib>

/****************************************************
 * 泛型编程 模板函数
 * template <class T>
 * 告诉编译器T是一种数据类型
 * 注意:T不一定使class!
 * 在函数中使用T来表示一种不确定
 * 的数据类型,使函数可以接收不同
 * 的数据类型来完成相同的操作,避
 * 免使用重载函数.
 * 在调用模板函数的时候,可以使用
 * Function<type>(a,b)来进一步明
 * 确T的数据类型
 * 
 * 对不同数据类型进行同样的处理 -> 模板函数
 * 对不同的数据类型进行不同的处理 -> 重载函数
 * 
 * 2021/7/31    CodingBugStd
**************************************************/

template <class T>

void Function(T&a,T&b)
{
    T c;
    c = a;
    a = b;
    b = c;
}

int main(void)
{
    using namespace std;
    int a,b;
    double c,d;
    string e,f;
    a= 16;
    b= 22;
    c= 72.5;
    d= 11.6;
    e= "HelloWorld!";
    f= "WDNMD";
    Function(a,b);
    cout<<a<<endl<<b<<endl;
    Function(c,d);
    cout<<c<<endl<<d<<endl;
    Function(e,f);
    cout<<e<<endl<<f<<endl;
    system("pause");
    return 0;
}
