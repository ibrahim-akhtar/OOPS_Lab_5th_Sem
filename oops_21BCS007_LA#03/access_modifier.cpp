// LA #03
// Problem 01

#include <iostream>
#include <cmath> //for functions like pow and sqrt
using namespace std;

class Point
{
private:
    double _x;
    double _y;

public:
    // Default constructor
    Point() : _x(0.0), _y(0.0) {}

    // Parameterized constructor
    Point(double x, double y) : _x(x), _y(y) {}

    // Copy constructor
    Point(const Point &p) : _x(p._x), _y(p._y) {}

    // Destructor
    ~Point()
    {
        cout << "Destructor called!" << endl;
    }

    // Member function to set coordinates
    void setCoords(double x, double y)
    {
        _x = x;
        _y = y;
    }

    // Member function to print coordinates
    void printCoords()
    {
        cout << "(" << _x << ", " << _y << ")" << endl;
    }

    // Member function to calculate distance between points
    double distFrom(const Point &p)
    {
        return sqrt(pow(_x - p._x, 2) + pow(_y - p._y, 2));
    }

    // Member function to calculate midpoint between points
    Point midPoint(const Point &p)
    {
        double midX = (_x + p._x) / 2.0;
        double midY = (_y + p._y) / 2.0;
        return Point(midX, midY);
    }
};

int main()
{
    // Example usage
    Point p1;
    Point p2(3.0, 4.0);

    p1.setCoords(1.0, 2.0);
    p1.printCoords();

    double distance = p1.distFrom(p2);
    cout << "Distance between p1 and p2: " << distance << endl;

    Point midpoint = p1.midPoint(p2);
    cout << "Midpoint between p1 and p2: ";
    midpoint.printCoords();

    return 0;
}
