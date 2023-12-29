//LA #07
//Problems 01

#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
    double x, y;

    Point() : x(0.0), y(0.0) {}

    Point(double x, double y) : x(x), y(y) {}

    double distFrom(const Point &other) const
    {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }
};

class Location : public Point
{
public:
    string Address;

    // Default constructor
    Location() : Point(), Address("") {}

    Location(double x, double y, const string &address)
        : Point(x, y), Address(address) {}

};

int main()
{
    // Instantiating an object of type Location using the default constructor.
    Location locDefault;

    // This will output the default coordinates (0.0, 0.0) and an empty address.
    cout << "Default Constructor Output: (" << locDefault.x << ", " << locDefault.y
         << "), Address: " << locDefault.Address << endl;

    // Instantiating an object of type Location using the parameterized constructor with only coordinates.
    Location locCoordinates(1.0, 2.0, "123 Main St");
    // This will output the specified coordinates (1.0, 2.0) and the provided address.
    cout << "Coordinates Constructor Output: (" << locCoordinates.x << ", " << locCoordinates.y
         << "), Address: " << locCoordinates.Address << endl;

    // Instantiating an object of type Location using the parameterized constructor with coordinates and address.
    Location locFull(3.0, 4.0, "456 Side St");
    // This will output the specified coordinates (3.0, 4.0) and the provided address.
    cout << "Full Constructor Output: (" << locFull.x << ", " << locFull.y
         << "), Address: " << locFull.Address << endl;

    // Instantiate two Location objects and call the distFrom function.
    Location loc1(0.0, 0.0, "First Location");
    Location loc2(3.0, 4.0, "Second Location");

    // Calculating the distance between loc1 and loc2 using the distFrom function.
    double distance = loc1.distFrom(loc2);
    cout << "Distance between loc1 and loc2: " << distance << endl;

    return 0;
}