#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>

/**********************************************************
 * assert()
 * 用来检查标志
 * 若不成立会终止程序
 * 避免出现未知情况
 * try
 * {
 *  ......
 * }
 * try 语句,将不确定的代码放入try中
 * 若try中代码抛出异常会挂起程序进入catch(){}
 * catch(type)
 * {
 *  ......
 * }
 * 用来输出异常情况给程序员和处理异常
 * throw type 抛出一个type类型的异常
 * 
 * Tips:
 * 1.不要滥用异常捕获,尽量在可能出现不确定的情况的代码段使用
 * 2.通常debug使用assert和cout等来反馈bug
 * 3.构造器和析构器中别使用try,特别容易出问题!
 * 4.若使用对象作为异常,抛出异常使用 值传递,捕获异常使用 引用传递
 *   避免捕获时重新构造一个对象
 *  2021/7/25 CodingBugStd
*************************************************************/

using namespace std;

class ErrClass
{
public:
    string Err_Name;
    int Err_Num;
    ErrClass(string name,int num);
    void CoutErr(void);
};
ErrClass::ErrClass(string name,int num)
{
    Err_Name = name;
    Err_Num = num;
}
void ErrClass::CoutErr(void)
{
    cout<<"Err_Name:"<<Err_Name<<endl;
    cout<<"Err_Num:"<<Err_Num<<endl;
}

int main(void)
{
    //int a = 16;
    ErrClass a("Try Test",16);
    try
    {
        throw a;
    }
    //assert(a==60);
    catch(ErrClass&e)
    {
        e.CoutErr();
    }
    system("pause");
    return 0;
}

