//LA #04
//Problem 01

#include <iostream>
#include<cmath>
using namespace std;

class Point{
    static int count;
    double _x;
    double _y;

public:
    void setCoords( double x, double y );
    void printCoords( );
    double distFrom(Point &p);
    Point midPoint(Point &p);

    Point(); // This is the DEFAULT constructor
    Point(double x, double y); // This is the PARAMETERIZED constructor
    Point(Point &p); // This is the COPY constructor
    ~Point(); // This is the destructor

    Point operator + (const Point & p) const; //Arithmetic Operator Overloading

    static int getCount();
};

int Point::count = 0;

void Point::setCoords( double x, double y ){
    _x = x;
    _y = y;
}

void Point::printCoords( ){
    cout << "(" << _x << ", " << _y << ")" << endl;
}

double Point::distFrom(Point &p){
    return sqrt( pow( _x - p._x, 2 ) + pow( _y - p._y, 2 ) );
}

Point Point::midPoint(Point &p){
    return Point( ( _x + p._x ) / 2, ( _y + p._y ) / 2 );
}

Point::Point(){
    count++;
}

Point::Point(double x, double y){
    count++;
    _x = x;
    _y = y;
}

Point::Point(Point &p){
    count++;
    _x = p._x;
    _y = p._y;
}

Point::~Point(){
    count--;
}

Point Point::operator + (const Point & p) const{
    return Point(_x + p._x, _y + p._y);
}

int Point::getCount(){
    return count;
}

int main() {
    Point p1, p2;
    cout << "Count after initializing 2 default Point objects: " << Point::getCount() << endl;

    p1.setCoords(1.0, 2.0);
    p2.setCoords(4.0, 6.0);

    cout << "Coordinates of Point p1: ";
    p1.printCoords();
    cout << "Coordinates of Point p2: ";
    p2.printCoords();

    cout << "Distance between Point p1 and Point p2: " << p1.distFrom(p2) << endl;

    Point mid = p1.midPoint(p2);
    cout << "Midpoint between Point p1 and Point p2: ";
    mid.printCoords();

    // Create a new Point object using the copy constructor
    Point p3(p1);

    cout << "Count after initializing Point p3 using the copy constructor: " << Point::getCount() << endl;

    // Overload the + operator for adding the coordinates of the 2 Point objects
    Point p4 = p1 + p2;

    cout << "Coordinates of Point p4 after overloading the + operator: ";
    p4.printCoords();

    cout << "Count after initializing Point p4 after overloading the + operator: " << Point::getCount() << endl;

    
    Point result = p1 + p2 + p3 + p4 + mid;
    cout << "Result after adding all the 5 points through + operator overloading: ";
    result.printCoords();
    
    return 0;
}