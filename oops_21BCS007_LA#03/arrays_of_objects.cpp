// LA #03
// Problem 03

#include <iostream>
using namespace std;
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>

#define MAX 1000
#define K 10

class Point
{
    double _x, _y, _mass;
    double _forceX, _forceY;

public:
    Point(double x, double y, double mass) : _x(x), _y(y), _mass(mass)
    {
        _forceX = _forceY = 0;
    }

    // Member function to calculate the Euclidean distance between points
    double distFrom(const Point &p)
    {
        double dx = _x - p._x;
        double dy = _y - p._y;
        return sqrt(dx * dx + dy * dy);
    }

    void pushNeighbours(vector<Point> &points, int i, int j)
    {
        for (int m = i - 1; m <= i + 1; m++)
        {
            for (int n = j - 1; n <= j + 1; n++)
            {
                if (m >= 0 && m < MAX && n >= 0 && n < MAX)
                {
                    int index = m * MAX + n;
                    double distance = distFrom(points[index]);
                    double force = 1000 * _mass * points[index]._mass / (distance * distance + 1);
                    points[index]._forceX += (points[index]._x - _x) / distance * force;
                    points[index]._forceY += (points[index]._y - _y) / distance * force;
                }
            }
        }
    }

    void updatePosition(double dt)
    {
        _x += _forceX * dt;
        _y += _forceY * dt;
        _forceX = _forceY = 0;
    }

    void printCoords()
    {
        cout << "(" << _x << ", " << _y << ")" << endl;
    }
};

vector<Point> createPoints()
{
    vector<Point> points;
    srand(time(0));
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            double x = i + 0.5;
            double y = j + 0.5;
            double mass = rand() % 10 + 1;
            points.push_back(Point(x, y, mass));
        }
    }
    return points;
}

void getKNN(vector<Point> &points, int index, int k)
{
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    for (int i = 0; i < points.size(); i++)
    {
        if (i != index)
        {
            double distance = points[index].distFrom(points[i]);
            pq.push(make_pair(distance, i));
        }
    }

    cout << "Nearest " << k << " neighbors of point at index " << index << ":" << endl;
    for (int i = 0; i < k; i++)
    {
        int neighborIndex = pq.top().second;
        points[neighborIndex].printCoords();
        pq.pop();
    }
}

int main()
{
    vector<Point> points = createPoints();
    int index = 12345;
    getKNN(points, index, K);

    double dt = 1.0;
    for (int i = 0; i < 10000; i++)
    {
        points[index].pushNeighbours(points, index / MAX, index % MAX);
        points[index].updatePosition(dt);
    }

    return 0;
}