// LA #05
// Problem 01

#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    static int count;
    double _x;
    double _y;

public:
    void setCoords(double x, double y);
    void printCoords() const;
    double distFrom(Point &p);
    Point midPoint(Point &p);

    Point();                   // This is the DEFAULT constructor
    Point(double x, double y); // This is the PARAMETERIZED constructor
    Point(Point &p);           // This is the COPY constructor
    ~Point();                  // This is the destructor

    Point operator+(const Point &p) const;                    // Addition Operator Overloading
    double l2Norm() const;                                    // Euclidean Distance Function
    double operator[](int index) const;                       // Subscript Operator Overloading
    friend ostream &operator<<(ostream &out, const Point &p); // Stream Out Operator Overloading

    static int getCount();
};

int Point::count = 0;

void Point::setCoords(double x, double y)
{
    _x = x;
    _y = y;
}

void Point::printCoords() const
{
    cout << "(" << _x << ", " << _y << ")";
}

double Point::distFrom(Point &p)
{
    return sqrt(pow(_x - p._x, 2) + pow(_y - p._y, 2));
}

Point Point::midPoint(Point &p)
{
    return Point((_x + p._x) / 2, (_y + p._y) / 2);
}

Point::Point()
{
    count++;
}

Point::Point(double x, double y)
{
    count++;
    _x = x;
    _y = y;
}

Point::Point(Point &p)
{
    count++;
    _x = p._x;
    _y = p._y;
}

Point::~Point()
{
    count--;
}

Point Point::operator+(const Point &p) const
{
    return Point(_x + p._x, _y + p._y);
}

double Point::l2Norm() const
{
    return sqrt(_x * _x + _y * _y);
}

double Point::operator[](int index) const
{
    if (index == 0)
        return _x;
    else if (index == 1)
        return _y;
    else
        return 0.0; // You may choose to handle out-of-bounds differently
}

ostream &operator<<(ostream &out, const Point &p)
{
    out << "Point ";
    p.printCoords();
    out << ", Norm = " << p.l2Norm();
    return out;
}

int Point::getCount()
{
    return count;
}

int main()
{
    Point p1(1.0, 2.0);
    cout << "Original Point: " << p1 << endl;

    // Example of subscript operator overloading
    cout << "X coordinate using subscript operator: " << p1[0] << endl;
    cout << "Y coordinate using subscript operator: " << p1[1] << endl;

    Point p2(5.0, 10.0);
    // Example of stream out << operator overloading
    cout << p2 << endl;

    return 0;
}
