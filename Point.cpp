#include<iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point()  // construct by default
    {
        cout << "Construct\n";
        x = y = 0;
    }
    Point(int x1, int y1)   // Construct by 2 param
    {
        cout << "Construct by 2 param\n";
        x = x1;
        y = y1;
    }
    void Init()
    {
        x = rand() % 10;
        y = rand() % 10;
    }
    void Init(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
    void Output()
    {
        cout << "X: " << x << "\tY: " << y << endl;
    }
    // перегрузка бинарных операции

    Point operator+(Point& b)
    {
        Point temp;
        temp.x = this->x + b.x;
        temp.y = this->y + b.y;
        return temp;
    }
    Point operator+(int a)
    {
        Point temp(x + a, y + a);
        return temp;
    }

    Point& operator--()
    {
        x -= 5;
        y -= 5;
        return *this;
    }

    Point operator--(int)
    {
        Point temp(*this);
        x -= 2;
        y -= 2;
        return temp;
    }
};

int main()
{
    srand(unsigned(time(0)));

    Point a(10, 10);
    Point c = --a;
    a.Output();
    c.Output();

    Point b(10, 10);
    Point v = b--;
    v.Output();
    b.Output();





    //Point c = a + b;
    //Point c = a.operator+(b);
    //c.Output();

    //c = a + 10;
    //c = a.operator+(10);
    //c.Output();

    //c = a * 3;

}