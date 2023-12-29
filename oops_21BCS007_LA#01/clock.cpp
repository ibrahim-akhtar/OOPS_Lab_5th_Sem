#include <iostream>
using namespace std;

class Clock
{
    private:
        int hour;
        int minute;
        int second;
        string meridian;

    public:
        void setClock (int h, int m, int s, string mer)
        {
            hour = h;
            minute = m;
            second = s;
            meridian = mer;
        }

        void displayStandard()
        {
            cout << "Time (in Standard Form)-> " << hour << ":" << minute << ":" << second << " " << meridian << endl;
        }

        void displayMilitary()
        {
            if (meridian == "PM")
            {
                hour = 12 + hour;
            }

            cout << "Time (in Military Form)-> " << hour << ":" << minute << ":" << second << endl;
        }
};

int main()
{
    Clock c;
    c.setClock (3, 15, 30, "PM");
    c.displayStandard();
    c.displayMilitary();
    
    return 0;
}