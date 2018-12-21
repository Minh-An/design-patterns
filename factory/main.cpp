#include "factory.h"
//x = r * cos theta, y = r* sin theta

int main()
{
    Point x = Point::Factory::NewCartesian(1, 1.5);
    Point y = Point::Factory::NewPolar(sqrt(2), M_PI_4);
    Point z = x + y;
    cout << z << endl;
}