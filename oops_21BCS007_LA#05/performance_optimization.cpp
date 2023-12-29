#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <chrono> // for measuring time

using namespace std;
using namespace std::chrono;

class Point
{
public:
    double x;
    double y;

    Point() : x(0.0), y(0.0) {}
    Point(double x, double y) : x(x), y(y) {}

    bool operator<(const Point &p) const
    {
        double norm1 = sqrt(x * x + y * y);
        double norm2 = sqrt(p.x * p.x + p.y * p.y);
        return norm1 < norm2;
    }

    friend ostream &operator<<(ostream &out, const Point &p);
};

ostream &operator<<(ostream &out, const Point &p)
{
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

void insertionSort(vector<Point> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        Point key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Insertion sort for int types
void insertionSortInt(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    vector<int> sizes = {10, 100, 1000, 10000};
    // vector<int> sizes = {10}; // Testing with a smaller size for demonstration

    srand(time(0));

    for (int n : sizes)
    {
        vector<Point> points;
        for (int i = 0; i < n; ++i)
        {
            double x = rand() % 10;
            double y = rand() % 10;
            points.push_back(Point(x, y));
        }

        // Measure time for Point objects
        auto start = high_resolution_clock::now();
        insertionSort(points);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Execution time for Point objects (n = " << n << "): " << duration.count() << " microseconds" << endl;

        // Create an array of integers
        vector<int> intArray;
        for (int i = 0; i < n; ++i)
        {
            intArray.push_back(rand() % 10);
        }

        // Measure time for int types
        start = high_resolution_clock::now();
        insertionSortInt(intArray);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Execution time for int types (n = " << n << "): " << duration.count() << " microseconds" << endl;
    }

    return 0;
}
