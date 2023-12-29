// LA #04
// Problem 02

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

    Point();                              // This is the DEFAULT constructor
    Point(double x, double y);            // This is the PARAMETERIZED constructor
    Point(Point &p);                      // This is the COPY constructor
    ~Point();                             // This is the destructor

    Point operator+(const Point &p) const; // Arithmetic Operator Overloading
    bool operator<(const Point &p) const;  // "less than" Operator Overloading
    bool operator>(const Point &p) const;  // "greater than" Operator Overloading
    bool operator==(const Point &p) const; // "equality" Operator Overloading

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

bool Point::operator<(const Point &p) const {
    double norm1 = _x + _y;
    double norm2 = p._x + p._y;
    return norm1 < norm2;
}

bool Point::operator>(const Point &p) const {
    double norm1 = _x + _y;
    double norm2 = p._x + p._y;
    return norm1 > norm2;
}

bool Point::operator==(const Point &p) const {
    double norm1 = _x + _y;
    double norm2 = p._x + p._y;
    double tolerance = 0.00001; // You can adjust the tolerance as needed
    return abs(norm1 - norm2) < tolerance;
}

int Point::getCount() {
    return count;
}

int main() {
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);

    cout << "Is p1 less than p2? " << (p1 < p2 ? "Yes" : "No") << endl;
    cout << "Is p1 greater than p2? " << (p1 > p2 ? "Yes" : "No") << endl;
    cout << "Are p1 and p2 approximately equal? " << (p1 == p2 ? "Yes" : "No") << endl;

    return 0;
}