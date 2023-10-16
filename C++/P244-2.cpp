#include <iostream>
using namespace std;
class Time {
public:
    int hour;
    int minute;

    Time(int h = 0, int m = 0);

    void print()
    {
        cout << hour << ":" << minute << endl;
    }
};
Time::Time(int h, int m)
{
    hour = h;
    minute = m;
}
int main()
{
    Time a;
    Time b{ 10,25 };
    a.print();
    b.print();
    return 0;
}