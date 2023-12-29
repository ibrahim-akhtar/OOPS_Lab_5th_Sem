// LA #07
// Problems 03

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Abstract class Element
class Element
{
public:
    // Pure virtual function print
    virtual void print() const = 0;

    // Virtual destructor (to make Element polymorphic)
    virtual ~Element() = default;
};

class Point : public Element
{
public:
    double x, y;

    // Default constructor
    Point() : x(0.0), y(0.0) {}

    // Parameterized constructor
    Point(double x, double y) : x(x), y(y) {}

    // Implementation of the print function for Point
    void print() const override
    {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }

    double distFrom(const Point &other) const
    {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }
};

class Vector : public Element
{
public:
    double i, j;

    // Default constructor
    Vector() : i(0.0), j(0.0) {}

    // Parameterized constructor
    Vector(double i, double j) : i(i), j(j) {}

    // Implementation of the print function for Vector
    void print() const override
    {
        cout << "Vector: (" << i << ", " << j << ")" << endl;
    }
};

class Location : public Point
{
public:
    std::string Address;

    // Default constructor
    Location() : Point(), Address("") {}

    // Parameterized constructor
    Location(double x, double y, const std::string &address)
        : Point(x, y), Address(address) {}

    // Implementation of the print function for Location
    void print() const override
    {
        cout << "Location: (" << x << ", " << y << "), Address: " << Address << endl;
    }

    // Override distFrom to calculate geodesic distance
    double distFrom(const Location &other) const
    {
        constexpr double earthRadius = 6371.0; // Earth radius in kilometers
        double angle = acos(sin(x) * sin(other.x) + cos(x) * cos(other.x) * cos(y - other.y));
        return angle * earthRadius;
    }
};

int main()
{
    Point point(1.0, 2.0);
    Vector vector(3.0, 4.0);
    Location location(5.0, 6.0, "Main Street");

    // Call print on objects of type Point and Vector
    point.print();
    vector.print();

    // Call print on an object of type Location
    location.print();

    return 0;
}