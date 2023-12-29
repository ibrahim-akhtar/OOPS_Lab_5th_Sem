// LA #06
// Problem 02

#include <iostream>
using namespace std;

class Vector;

class Point
{
    double x;
    double y;

public:
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    // Conversion operator from Point to Vector
    operator Vector() const;

    // Friend function to output Point
    friend ostream &operator<<(ostream &out, const Point &p);
};

class Vector
{
    double x;
    double y;

public:
    Vector(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    // Conversion operator from Vector to Point
    operator Point() const;

    // Friend function to output Vector
    friend ostream &operator<<(ostream &out, const Vector &v);
};

// Conversion operator from Point to Vector
Point::operator Vector() const
{
    return Vector(x, y);
}

// Friend function to output Point
ostream &operator<<(ostream &out, const Point &p)
{
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

// Conversion operator from Vector to Point
Vector::operator Point() const
{
    return Point(x, y);
}

// Friend function to output Vector
ostream &operator<<(ostream &out, const Vector &v)
{
    out << "<" << v.x << ", " << v.y << ">";
    return out;
}

int main()
{
    // Create a Point
    Point p1(1, 2);
    cout << "Point: " << p1 << endl;

    // Convert Point to Vector
    Vector v1 = static_cast<Vector>(p1);
    cout << "Converted Point to Vector: " << v1 << endl;

    // Create a Vector
    Vector v2(3, 4);
    cout << "Vector: " << v2 << endl;

    // Convert Vector to Point
    Point p2 = static_cast<Point>(v2);
    cout << "Converted Vector to Point: " << p2 << endl;

    return 0;
}
