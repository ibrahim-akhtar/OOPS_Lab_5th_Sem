//LA #06
//Problem 01

#include <iostream>
using namespace std;

class Point
{
    double x;
    double y;

public:
    // Parameterized constructor
    Point(double arr[2]) : x(arr[0]), y(arr[1]) {}

    // Conversion operator
    operator double *() const
    {
        double *parr = new double[2];
        parr[0] = x;
        parr[1] = y;
        return parr;
    }

    // Subscript operator overloading
    double operator[](int index) const
    {
        if (index == 0)
            return x;
        else if (index == 1)
            return y;
        else
            return 0.0; //to handle out of bounds
    }
};

int main()
{
    double arr[2] = {1, 2};
    Point p1(arr);

    // Use the subscript operator
    cout << "Using subscript operator: " << p1[0] << "," << p1[1] << endl;

    // Use the conversion operator
    double *parr = p1;
    cout << "Using conversion operator: " << parr[0] << "," << parr[1] << endl;

    delete[] parr; // deleting to free up the memory

    return 0;
}
