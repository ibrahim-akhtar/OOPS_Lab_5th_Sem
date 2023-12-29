#include <iostream>
using namespace std;

class Line
{
    public:
        void setLength (double len);
        double getLength ();
        Line(); //Non Parametrized Constructor
        Line(double inLength); //Parameterized Constructor

    private:
        double length;
};

//defining non parameterized constructor
Line :: Line()
{
    cout << "Object is being created..." << endl;
    //Problem 2 part 1
    length = 0.0;
    cout << "Initially set the length to 0.0" << endl;
}

//defining parametrized constructor
Line :: Line (double inLength)
{
    cout << "Parameterized Constructor constructed ..." << endl;
    length = inLength;
    cout << "Length of line set to " << length << endl;
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