// LA #03
// Problem 03

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

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

// Function to generate a random double in the specified range
double getRandomDouble(double min, double max)
{
    return min + (max - min) * (static_cast<double>(rand()) / RAND_MAX);
}

// Function to generate random coordinates for Point and Vector
void generateRandomCoordinates(double &x, double &y)
{
    x = getRandomDouble(-10.0, 10.0);
    y = getRandomDouble(-10.0, 10.0);
}

// Function to generate random coordinates for PointN
vector<double> generateRandomCoordinates(size_t length)
{
    vector<double> coordinates;
    for (size_t i = 0; i < length; ++i)
    {
        coordinates.push_back(getRandomDouble(-10.0, 10.0));
    }
    return coordinates;
}

// Function to instantiate k objects based on the specified rules
vector<Element *> instantiateObjects(int k)
{
    vector<Element *> objects;

    for (int j = 0; j < k; ++j)
    {
        if (j % 3 == 0)
        {
            double x, y;
            generateRandomCoordinates(x, y);
            objects.push_back(new Point(x, y));
        }
        else if (j % 3 == 1)
        {
            double i, j;
            generateRandomCoordinates(i, j);
            objects.push_back(new Vector(i, j));
        }
        else
        {
            size_t length = rand() % 9 + 2; // Random length between 2 and 10
            vector<double> coordinates = generateRandomCoordinates(length);
            objects.push_back(new PointN(coordinates));
        }
    }

    return objects;
}

// Function to print the norms of the elements (for verification)
void printNorms(const vector<Element *> &objects)
{
    for (const auto &obj : objects)
    {
        cout << "Norm: " << obj->norm() << endl;
    }
}

// Function to perform insertion sort based on the magnitude of norms (initial version)
void slowSort(vector<Element *> &objects)
{
    int n = objects.size();

    for (int i = 1; i < n; ++i)
    {
        Element *key = objects[i];
        int j = i - 1;

        while (j >= 0 && objects[j]->norm() > key->norm())
        {
            objects[j + 1] = objects[j];
            --j;
        }

        objects[j + 1] = key;
    }
}

// Function to perform a faster sorting algorithm based on the magnitude of norms
void fastSort(vector<Element *> &objects)
{
    // Use std::sort for faster sorting
    std::sort(objects.begin(), objects.end(), [](Element *a, Element *b)
              { return a->norm() < b->norm(); });
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    // Perform the sorting for different values of k
    //int arr[]  = {100, 1000, 10000, 100000};
    int arr[] = {10};       //demonstrating for lower values
    for (int k : arr)
    {
        // Instantiate k objects
        vector<Element *> objects = instantiateObjects(k);

        // Measure the execution time of slowSort
        auto slowStart = high_resolution_clock::now();
        slowSort(objects);
        auto slowStop = high_resolution_clock::now();
        auto slowDuration = duration_cast<microseconds>(slowStop - slowStart);

        // Measure the execution time of fastSort
        auto fastStart = high_resolution_clock::now();
        fastSort(objects);
        auto fastStop = high_resolution_clock::now();
        auto fastDuration = duration_cast<microseconds>(fastStop - fastStart);

        // Output the result
        cout << "Sorting time for k = " << k << ":" << endl;
        cout << "SlowSort: " << slowDuration.count() << " microseconds" << endl;
        cout << "FastSort: " << fastDuration.count() << " microseconds" << endl;

        // Calculate and print the speedup
        double speedup = static_cast<double>(slowDuration.count()) / fastDuration.count();
        cout << "Speedup: " << speedup << endl;

        // Clean up memory
        for (auto &obj : objects)
        {
            delete obj;
        }
    }

    return 0;
}
