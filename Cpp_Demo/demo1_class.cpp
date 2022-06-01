#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Car
{
    public:
        string name;
        string color;
        string engine;
        float gas;
        float max_gas;
        unsigned short wheel;
        Car(void);
        ~Car(void);
        void fill_tank(float liter);
        void Running(void);
};

Car::Car(void)
{
    color = "Red";
    engine = "V8";
    gas = 0.0;
    max_gas = 1000;
    wheel = 4;
}

Car::~Car(void)
{
    cout<<"Car Was Break";
}

void Car::fill_tank(float liter)
{
    gas+=liter;
    if(gas>max_gas)
    {
        gas = max_gas;
        cout<<"Tank Full"<<endl;
    }
    cout<<"Gas Tank: "<<gas<<" liter"<<endl;
}

void Car::Running(void)
{
    gas -= 50;
    if(gas<0)
        gas = 0;
}

void OutPut(Car*car)
{
    cout<<"Car Name:"<<car->name<<endl;
    cout<<"Color:"<<car->color<<endl;
    cout<<"Engine:"<<car->engine<<endl;
    cout<<"Wheel:"<<car->wheel<<endl;
    cout<<"gas: "<<car->gas<<" filter"<<endl;
}

int main(void)
{
    Car myCar;
    char Input;
    char b[16];
    cout<<"Input Your Car Name:";
    getline(cin,myCar.name);
    while(1)
    {
        char flag = 0;
        OutPut(&myCar);
        cout<<"1:Get Gas 2:Run Car"<<endl;
        Input = getchar();
        switch(Input)
        {
            case '1':
                float temp;
                cout<<"Gas:";
                cin>>temp;
                myCar.fill_tank(temp);
                break;
            case '2':
                myCar.Running();
                break;
            default:
                flag = 1;
                break;
        }
        if(flag==1)
            break;
        cin.get();
        system("cls");
    }
    system("pause");
    return 0;
}

