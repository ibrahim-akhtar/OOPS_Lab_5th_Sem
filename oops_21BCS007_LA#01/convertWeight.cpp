#include <iostream>
using namespace std;

int main()
{
    double pounds, kilos;

    cout << "Enter the weight in pounds: ";
    cin >> pounds;
    kilos = pounds / 2.205;
    cout << pounds << " pounds is equivalent to " << kilos << " kilos." <<endl;

    cout << "Enter the weight in kilos: ";
    cin >> kilos;
    pounds = kilos * 2.205;
    cout << kilos << " kilos is equivalent to " << pounds << " pounds." <<endl;

    return 0;
}