#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/*********************************************
 * 虚继承
 * 为了解决多继承中,父类之间相同的成员
 * (源于同一实例)而造成的成员重复。
 * class aaa : virtual public bbb{};
 * virtual(虚拟的) 可理解为可被覆盖的
 * 即aaa的衍生类,bbb的成员只有一个(多的被覆盖)
 *  2021/7/24   CodingBugStd
*********************************************/

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

class Student:virtual public Person
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

class Teacher:virtual public Person
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

//后面的Teacher(name,TeacherClass)对Person::name重新覆盖
TeachingStudent::TeachingStudent(string name,string LearnClass,string TeachClass):Student(name,LearnClass),Teacher(name,TeachClass){}
//因为 Student 和 Teacher 是 Person 的虚继承,所以TeachingStduent的Person::name只且有一个,name的值会被构造器层层覆盖
//TeachingStudent::TeachingStudent(string name,string LearnClass,string TeachClass):Student("a",LearnClass),Teacher("b",TeachClass){}
//TeachingStudent::TeachingStudent(string name,string LearnClass,string TeachClass):Student("a",LearnClass),Teacher("b",TeachClass),Person(name){}


void TeachingStudent::Introduce(void)
{
    cout<<"I am a TeachingStudent,my name is "<<name<<".I teach in "<<Teacher::classse<<" class and learn in "<<Student::classes<<" class."<<endl;
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
    TeachingStudent*a;
    a = new TeachingStudent("ava","123","321");
    a->Introduce();
    system("pause");
    return 0;
}
