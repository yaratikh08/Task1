#define _USE_MATH_DEFINES
#include "Point.h"
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>

using namespace std;

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

double Point::getX() const { return x; }
double Point::getY() const { return y; }
double Point::getZ() const { return z; }

string Point::toString() const
{
    ostringstream oss;
    oss << "(" << x << ", " << y << ", " << z << ")";
    return oss.str();
}

istream& Point::readFromStream(istream& is, Point& point)
{
    double x, y, z;
    is >> x >> y >> z;
    if (is)
    {
        point = Point(x, y, z);
    }
    return is;
}

ostream& operator<<(ostream& os, const Point& point)
{
    os << point.toString();
    return os;
}

istream& operator>>(istream& is, Point& point)
{
    return Point::readFromStream(is, point);
}

bool operator==(const Point& p1, const Point& p2)
{
    return abs(p1.getX() - p2.getX()) <= numeric_limits<double>::epsilon() &&
           abs(p1.getY() - p2.getY()) <= numeric_limits<double>::epsilon() &&
           abs(p1.getZ() - p2.getZ()) <= numeric_limits<double>::epsilon();
}

bool operator!=(const Point& p1, const Point& p2)
{
    return !(p1 == p2);
}
