# C++笔记

## 	1.重载

​	C++能对函数进行重载。重载(overloading)指的是能根据传入的数据类型的不同执行不同的代码段。

```c++
//调用swap()函数时,编译器会自动根据传入的参数匹配对应的函数。
void swap(int&a,int&b);
void swap(double&a,double&b);
```

​	C++也能对运算符进行重载!使用关键字operator。对运算符的重载的意义在于能对自己定义的数据类型和对象使用运算符,比如使结构体能够相加等

```c++
typedef struct
{
    int x;
    int y;
}Pos;

Pos operator+(Pos a,Pos b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}
```

​	上面的代码使名为Pos的数据类型能够实现'+'的运算,并且结果为一个Pos类型。

## 2.new 和 delete

​	new:申请内存

​	delete:释放内存

```c++
int main(void)
{
    int*a = NULL;
    a = new int;	//申请一个int大小的内存空间
    delete a;		//释放内存
    a = NULL;
    return 0;
}
```

## 3.类

​	类可以简单理解为C结构体的升级,它能包含多个数据成员和函数成员。类是对某样“事物”的描述(不能简单的理解为一种数据类型),比如说"车"类,它是对"车"这一事物的描述,类中包含"车"的相关属性和方法!如:颜色 名字 车主(都是属性) 以及 启动 转向 加油 维修(都是方法)等...

### 	类的声明,定义和实例化

```c++
#include <iostream>
#include <string>

class Car;	//声明一个叫做Car的类
class Car	//Car类的定义
{
public:			//成员访问等级 公共的
    string name;				//数据成员
    Car::Car();					//类构造器
    Car::~Car();				//类析构器
    void Car::Car_Run(void);	//方法成员
};
void Car::Car_Run(void)
{
    //Car类中的Car_Run方法的实现
}
Car::Car(){}	//类构造器的实现
Car::~Car(){}	//类析构器的实现

int main(void)
{
    Car	myCar;			//创建一个Car类对象
    myCar.Car_Run();	//使用myCar对象的Car_Run()方法
    std::cout<<myCar.name<<std::endl;	//访问myCar对象的name成员
    return 0;
}

```

​	**注意:方法成员需要在方法名前加入类名域,表示该方法所属的类**

### 	类构造器和析构器

​	类构造器会在创建对象时被调用,可以不定义构造器。但是通常情况下会定义类的构造器，用于给对象的各个属性赋予初始值。类构造器可以被重载,使创建对象时能接收不同参数。

```c++
Car::Car(void)
{
	name = "noName";
}
Car::Car(string carName)
{
	name = carName;
}

Car myCar;			//使用无参数的构造器,myCar的name成员被赋值为"noName"
Car mySubCar("WTF");//使用Car::Car(string)构造器,mySubCar的name成员被赋值为"WTF"
```

​	类析构器会在对象被删除时调用,不能被重载,不能接收参数。析构器主要用来回收内存!

### 	继承