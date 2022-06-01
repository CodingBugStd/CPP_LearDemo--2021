#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/****************************************************************************
friend class的运用
friend class可以访问所有属性和方法
声明:在class任何地方 friend class xxx
xxx就可以访问该类的所有属性和方法
注意:子类无法访问父类的私有部分(保护部分可以访问),除非子类为为父类的friend class
        2021/7/20   CodingBugStd
****************************************************************************/

class Lovers;
class Boyfriend;
class Girlfriend;
class Other;

class Lovers
{
    friend class Other;
    public:
    Lovers(void);
    Lovers(string name);
    void Kiss(Lovers*ptr);
    protected:
    string name;
};

class Boyfriend:public Lovers
{
    public:
    Boyfriend(void);
    Boyfriend(string name);
};

class Girlfriend:public Lovers
{
    public:
    Girlfriend();
    Girlfriend(string name);
};

class Other:public Lovers
{
    public:
    Other(void);
    Other(string name);
    void Kiss(Lovers*ptr);
};

Boyfriend::Boyfriend(void):Lovers(){}
Boyfriend::Boyfriend(string name):Lovers(name){}
Girlfriend::Girlfriend(void):Lovers(){}
Girlfriend::Girlfriend(string name):Lovers(name){}
Other::Other(void):Lovers(){}
Other::Other(string name):Lovers(name){}

void Other::Kiss(Lovers*ptr)
{
    cout<<"Other "<<name<<" Kiss "<<ptr->name;
}

Lovers::Lovers(void)
{
    cout<<"Name:";
    getline(cin,name);
}

Lovers::Lovers(string name)
{
    this->name = name;
}

void Lovers::Kiss(Lovers*ptr)
{
    cout<<name<<" Kiss "<<ptr->name<<endl;
}

int main(void)
{
    Boyfriend a;
    Other b;
    a.Kiss(&b);
    b.Kiss(&a);
    system("pause");
    return 0;
}
