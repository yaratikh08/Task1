#include "Point.h"

using namespace std;

Point::Point(const double x, const double y, const double z) : x(x), y(y), z(z)
{
}

Point::Point(const Point& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
}

Point::Point(Point&& other)
{
    x = other.x;
    y = other.y;
    z = other.z;

    other.x = 0;
    other.y = 0;
    other.z = 0;
}

Point& Point::operator=(const Point& other)
{
    if (this == &other)
    {
        return *this;
    }

    x = other.x;
    y = other.y;
    z = other.z;

    return *this;
}

Point& Point::operator=(Point&& other)
{
    if (this == &other)
    {
        return *this;
    }

    x = other.x;
    y = other.y;
    z = other.z;

    other.x = 0;
    other.y = 0;
    other.z = 0;

    return *this;
}

double Point::GetX() const
{
    return x;
}

double Point::GetY() const
{
    return y;
}

double Point::GetZ() const
{
    return z;
}

bool Point::operator==(const Point& other) const
{
    return x == other.x && y == other.y && z == other.z;
}

bool Point::operator!=(const Point& other) const
{
    return !(*this == other);
}

bool Point::operator<(const Point& other) const
{
    if (x != other.x)
        return x < other.x;
    if (y != other.y)
        return y < other.y;
    return z < other.z;
}

bool Point::operator<=(const Point& other) const
{
    return (*this < other) || (*this == other);
}

bool Point::operator>(const Point& other) const
{
    return !(*this <= other);
}

bool Point::operator>=(const Point& other) const
{
    return !(*this < other);
}

ostream& operator<<(ostream& os, const Point& point)
{
    os << "(" << point.x << ", " << point.y << ", " << point.z << ")";
    return os;
}

istream& operator>>(istream& is, Point& point)
{
    is >> point.x >> point.y >> point.z;
    return is;
}