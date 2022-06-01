#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct
{
    int x;
    int y;
}Pos;

Pos operator+(Pos&a,Pos&b)
{
    Pos c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

int main(void)
{
    Pos a = {1,2};
    Pos b = {3,4};
    a = a+b;
    cout<<a.x<<endl<<a.y<<endl;
    system("pause");
    return 0;
}

