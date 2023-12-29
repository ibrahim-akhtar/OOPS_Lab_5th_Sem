// LA #07
// Problems 02

#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

class Point
{
public:
    double x, y;

    // Default constructor
    Point() : x(0.0), y(0.0)
    {
        cout << "Point Default Constructor" << endl;
    }

    // Parameterized constructor
    Point(double x, double y) : x(x), y(y)
    {
        cout << "Point Parameterized Constructor" << endl;
    }

    // Copy constructor
    Point(const Point &other) : x(other.x), y(other.y)
    {
        cout << "Point Copy Constructor" << endl;
    }

    // Move constructor
    Point(Point &&other) noexcept : x(exchange(other.x, 0.0)), y(exchange(other.y, 0.0))
    {
        cout << "Point Move Constructor" << endl;
    }

    // Default destructor
    ~Point()
    {
        cout << "Point Destructor" << endl;
    }

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
    Location() : Point(), Address("")
    {
        cout << "Location Default Constructor" << endl;
    }

    // Parameterized constructor
    Location(double x, double y, const string &address)
        : Point(x, y), Address(address)
    {
        cout << "Location Parameterized Constructor" << endl;
    }

    // Copy constructor
    Location(const Location &other)
        : Point(other), Address(other.Address)
    {
        cout << "Location Copy Constructor" << endl;
    }

    // Move constructor
    Location(Location &&other) noexcept
        : Point(move(other)), Address(exchange(other.Address, ""))
    {
        cout << "Location Move Constructor" << endl;
    }

    // Default destructor
    ~Location()
    {
        cout << "Location Destructor" << endl;
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
    // Instantiate two Location objects and call the distFrom function.
    Location loc1(0.0, 0.0, "First Location");
    Location loc2(3.0, 4.0, "Second Location");

    // Calculate and output the geodesic distance between loc1 and loc2 using the overridden distFrom function.
    double distance = loc1.distFrom(loc2);
    cout << "Geodesic Distance between loc1 and loc2: " << distance << " km" << endl;

    // Create a vector of locations representing the delivery truck's route
    vector<Location> route = {
        {0.0, 0.0, "Location 1"},
        {1.0, 1.0, "Location 2"},
        // ... Add other locations in the route ...
        {9.0, 9.0, "Location 9"},
        {10.0, 10.0, "Location 10"}};

    // Calculate the total distance the delivery truck must travel
    double totalDistance = 0.0;
    for (size_t i = 0; i < route.size() - 1; ++i)
    {
        totalDistance += route[i].distFrom(route[i + 1]);
    }

    cout << "Total Distance for the Delivery Truck's Route: " << totalDistance << " km" << endl;

    return 0;
}