// LA #03
// Problem 02

#include <iostream>
#include <cmath> //for functions like pow and sqrt
using namespace std;

class Point
{
private:
    double _x;
    double _y;

    // Static variables to keep track of object count
    static int count;
    static int countTL;
    static int countTR;
    static int countBR;
    static int countBL;

public:
    // Default constructor
    Point() : _x(0.0), _y(0.0)
    {
        count++;
    }

    // Parameterized constructor
    Point(double x, double y) : _x(x), _y(y)
    {
        count++;
        updateQuadrantCounts();
    }

    // Copy constructor
    Point(const Point &p) : _x(p._x), _y(p._y)
    {
        count++;
        updateQuadrantCounts();
    }

    // Destructor
    ~Point()
    {
        cout << "Destructor called!" << endl;
        count--;
    }

    // Member function to set coordinates
    void setCoords(double x, double y)
    {
        _x = x;
        _y = y;
        updateQuadrantCounts();
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

    // Static function to get the object count
    static int getCount()
    {
        return count;
    }

    // Static function to get the quadrant count
    static int getQuadrantCount(int quadrant)
    {
        switch (quadrant)
        {
        case 1:
            return countTL;
        case 2:
            return countTR;
        case 3:
            return countBR;
        case 4:
            return countBL;
        default:
            return -1;
        }
    }

private:
    void updateQuadrantCounts()
    {
        if (_x > 0 && _y > 0)
        {
            countTR++;
        }
        else if (_x > 0 && _y <= 0)
        {
            countBR++;
        }
        else if (_x <= 0 && _y > 0)
        {
            countTL++;
        }
        else if (_x <= 0 && _y <= 0)
        {
            countBL++;
        }
    }
};

// Define the static variables count and countTL, countTR, countBR, countBL
int Point::count = 0;
int Point::countTL = 0;
int Point::countTR = 0;
int Point::countBR = 0;
int Point::countBL = 0;

int main()
{
    // Example usage
    Point p1;
    Point p2(3.0, 4.0);

    p1.setCoords(1.0, 2.0);
    p1.printCoords();
    p2.printCoords();

    double distance = p1.distFrom(p2);
    cout << "Distance between p1 and p2: " << distance << endl;

    Point midpoint = p1.midPoint(p2);
    cout << "Midpoint between p1 and p2: ";
    midpoint.printCoords();

    cout << "Number of Point objects created: " << Point::getCount() << endl;

    // Example usage for quadrant count
    Point p3(1.0, 1.0);
    Point p4(-1.0, -1.0);

    cout << "Number of points in quadrant 1: " << Point::getQuadrantCount(1) << endl;
    cout << "Number of points in quadrant 2: " << Point::getQuadrantCount(2) << endl;
    cout << "Number of points in quadrant 3: " << Point::getQuadrantCount(3) << endl;
    cout << "Number of points in quadrant 4: " << Point::getQuadrantCount(4) << endl;

    return 0;
}