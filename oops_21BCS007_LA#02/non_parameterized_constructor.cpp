#include <iostream>
using namespace std;

class Line
{
    public:
        void setLength (double len);
        double getLength ();
        Line(); //Non Parametrized Constructor

    private:
        double length;
};

//defining constructor
Line :: Line()
{
    cout << "Object is being created..." << endl;
}

//member functions definations
void Line :: setLength(double len)
{
    length = len;
}

double Line :: getLength()
{
    return length;
}

//main function
int main()
{
    Line line;
    line.setLength(6.0);
    cout << "Length of line: " << line.getLength() << endl;
    return 0;
}