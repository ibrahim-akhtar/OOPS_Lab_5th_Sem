// LA #09
// Problem 01

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Element
{
public:
    // Pure virtual function norm
    virtual double norm() const = 0;

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

    // Implementation of the norm function for Point
    double norm() const override
    {
        return sqrt(x * x + y * y);
    }

    // Implementation of the print function for Point
    void print() const override
    {
        cout << "Point: (" << x << ", " << y << "), Norm: " << norm() << endl;
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

    // Implementation of the norm function for Vector
    double norm() const override
    {
        return sqrt(i * i + j * j);
    }

    // Implementation of the print function for Vector
    void print() const override
    {
        cout << "Vector: (" << i << ", " << j << "), Norm: " << norm() << endl;
    }
};

class PointN : public Element
{
private:
    vector<double> coordinates;

public:
    // Default constructor
    PointN() {}

    // Parameterized constructor
    PointN(const vector<double> &coords) : coordinates(coords) {}

    // Destructor
    ~PointN()
    {
        cout << "PointN Destructor" << endl;
    }

    // Implementation of the norm function for PointN
    double norm() const override
    {
        double sum = 0.0;
        for (const double &coord : coordinates)
        {
            sum += coord * coord;
        }
        return sqrt(sum);
    }

    // Implementation of the print function for PointN
    void print() const override
    {
        cout << "PointN: (";
        for (size_t i = 0; i < coordinates.size(); ++i)
        {
            cout << coordinates[i];
            if (i < coordinates.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "), Norm: " << norm() << endl;
    }
};

int main()
{
    Point point(1.0, 2.0);
    Vector vector(3.0, 4.0);

    // Call norm and print on objects of type Point and Vector
    cout << "Point Norm: " << point.norm() << endl;
    point.print();

    cout << "Vector Norm: " << vector.norm() << endl;
    vector.print();

    // Create a PointN with 3 coordinates
    PointN pointN({1.0, 2.0, 3.0});
    cout << "PointN Norm: " << pointN.norm() << endl;
    pointN.print();

    return 0;
}