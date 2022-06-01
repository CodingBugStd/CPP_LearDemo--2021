#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Animal
{
    public:
    Animal(void);
    Animal(string name);
    ~Animal(void);
    void Show_Name(void);
    void Breath(void);
    protected:
    string name;
};

class Pig:public Animal
{
    public:
    Pig(void);
    void Show_Name(void);
};

void Pig::Show_Name(void)
{
    cout<<"Pig Name:"<<name<<endl;
}

Pig::Pig(void)
{
    cout<<"Pig Maker"<<endl;
}

void Animal::Breath(void)
{
    cout<<"Animal "<<name<<" Breathing"<<endl;
}

void Animal::Show_Name(void)
{
    cout<<"Name:"<<name<<endl;
}

Animal::Animal(void)
{
    cout<<"Animal Maker"<<endl;
    cout<<"Animal Name:";
    getline(cin,name);
}

Animal::Animal(string name)
{
    this->name = name;
}

Animal::~Animal(void)
{
    cout<<"Animal Deleter"<<endl;
}

int main(void)
{
    Pig animal;
    animal.Show_Name();
    animal.Breath();
    system("pause");
    return 0;
}
