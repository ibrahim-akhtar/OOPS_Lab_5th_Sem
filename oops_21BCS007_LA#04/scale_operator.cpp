//LA #04
//Problem 04

#include <iostream>
#include <cmath>
using namespace std;

class Point {
    static int count;
    double _x;
    double _y;

public:
    void setCoords(double x, double y);
    void printCoords();
    double distFrom(Point &p);
    Point midPoint(Point &p);

    Point();                        // This is the DEFAULT constructor
    Point(double x, double y);      // This is the PARAMETERIZED constructor
    Point(Point &p);                // This is the COPY constructor
    ~Point();                       // This is the destructor

    Point operator+(const Point &p) const; // Addition Operator Overloading
    Point operator*(double s) const;       // Scaling Operator Overloading
    static int getCount();
};

int Point::count = 0;

void Point::setCoords(double x, double y) {
    _x = x;
    _y = y;
}

void Point::printCoords() {
    cout << "(" << _x << ", " << _y << ")" << endl;
}

double Point::distFrom(Point &p) {
    return sqrt(pow(_x - p._x, 2) + pow(_y - p._y, 2));
}

Point Point::midPoint(Point &p) {
    return Point((_x + p._x) / 2, (_y + p._y) / 2);
}

Point::Point() {
    count++;
}

Point::Point(double x, double y) {
    count++;
    _x = x;
    _y = y;
}

Point::Point(Point &p) {
    count++;
    _x = p._x;
    _y = p._y;
}

Point::~Point() {
    count--;
}

Point Point::operator+(const Point &p) const {
    return Point(_x + p._x, _y + p._y);
}

Point Point::operator*(double s) const {
    return Point(_x * s, _y * s);
}

int Point::getCount() {
    return count;
}

// Function for linear combination
Point linear_combine(const Point &p, double s) {
    // q = (this) * s + p * (1 - s)
    Point q = (p * (1 - s)) + (Point() * s);
    return q;
}

int main() {
    // Example usage

    Point p1(1.0, 2.0);
    Point p2 = p1 * 2.0; // Scaling p1 by a factor of 2

    cout << "Initial Point p1: ";
    p1.printCoords();
    cout << "Point p1 gets Scaled by 2.0 ..." <<endl;
    cout << "Scaled Point p2: ";
    p2.printCoords();

    // Linear combination of two points
    Point p3 = linear_combine(p1, 0.3);

    cout << "Linear Combination of Point p1 and Default Point: ";
    p3.printCoords();

    return 0;
}