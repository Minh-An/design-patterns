#include <cmath>
#include <iostream>

using namespace std;

class Point
{
  private:
    float x_;
    float y_;
    Point(float x, float y) : x_(x), y_(y){};

  public:
    Point operator+(const Point &other)
    {
        return {x_ + other.x_, y_ + other.y_};
    }

    class Factory
    {
      public:
        static Point NewCartesian(float x, float y)
        {
            return {x, y};
        };
        static Point NewPolar(float r, float theta)
        {
            return {r * cos(theta), r * sin(theta)};
        };
    };

    friend ostream &operator<<(ostream &out, const Point &point);
};

ostream &operator<<(ostream &out, const Point &point)
{
    out << point.x_ << ", " << point.y_;
    return out;
}