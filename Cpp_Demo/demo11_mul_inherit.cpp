#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/*******************************
 * 多继承
 * 一个类可以从多个类中继承
 * 若在多个类中继承了同名成员,在
 * 访问成员时需要写出父类
 * 多继承可以理解为创建了多个对象
 * 并将这些对象合并当成一个对象处
 * 理
 *  2021/7/24   CodingBugStd
 ******************************/

class Person
{
public:
    Person(void);
    Person(string name);
    virtual void Introduce(void);
protected:
    string name;
};

void Person::Introduce(void)
{
    cout<<"My name is "<<name<<endl;
}

Person::Person(string name)
{
    this->name = name;
}

Person::Person(void)
{
    name = "NoName";
}

class Student:public Person
{
public:
    Student(string name,string classes);
    void Introduce(void);
    void Learn(void);
protected:
    string classes;
};

Student::Student(string name,string classes):Person(name)
{
    this->classes = classes;
}

void Student::Learn(void)
{
    cout<<name<<" is learn in "<<classes<<" class"<<endl;
}

void Student::Introduce(void)
{
    cout<<"I am a student,my name is "<<name<<". I learn in "<<classes<<" class"<<endl;
}

class Teacher:public Person
{
public:
    Teacher(string name,string classes);
    void Introduce(void);
    void Teache(void);
protected:
    string classse;
};

class TeachingStudent:public Teacher,public Student
{
public:
    TeachingStudent(string name,string LearnClass,string TeachClass);
    void Introduce(void);
};

TeachingStudent::TeachingStudent(string name,string LearnClass,string TeachClass):Student(name,LearnClass),Teacher(name,TeachClass){}


void TeachingStudent::Introduce(void)
{
    cout<<"I am a TeachingStudent,my name is "<<Teacher::name<<".I teach in "<<Teacher::classse<<"class and learn in "<<Student::classes<<" class."<<endl;
}

void Teacher::Introduce(void)
{
    cout<<"I am a teacher,my name is "<<name<<". I teach in "<<classse<<" class"<<endl;
}

void Teacher::Teache(void)
{
    cout<<name<<" is teach in "<<classse<<" class"<<endl;
}

Teacher::Teacher(string name,string classes)
{
    this->name = name;
    this->classse = classes;
}

int main(void)
{
    Student a("Ava","123");
    Teacher b("Aka","123");
    TeachingStudent c("mmm","123","321");
    a.Introduce();
    a.Learn();
    b.Introduce();
    b.Teache();
    c.Introduce();
    c.Learn();
    c.Teache();
    system("pause");
    return 0;
}
