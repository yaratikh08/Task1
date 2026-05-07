#define _USE_MATH_DEFINES
#include "Sphere.h"
#include <cmath>
#include <stdexcept>
#include <sstream>

using namespace std;

Sphere::Sphere(const Point& center, double radius) : center(center), radius(radius)
{
    if (radius <= 0)
    {
        throw invalid_argument("Радиус должен быть положительным числом");
    }
}

Point Sphere::getCenter() const { return center; }
double Sphere::getRadius() const { return radius; }

void Sphere::setRadius(double radius)
{
    if (radius <= 0)
    {
        throw invalid_argument("Радиус должен быть положительным числом");
    }
    this->radius = radius;
}

double Sphere::surfaceArea() const
{
    return 4 * M_PI * radius * radius;
}

double Sphere::volume() const
{
    return (4.0 / 3.0) * M_PI * radius * radius * radius;
}

string Sphere::toString() const
{
    ostringstream oss;
    oss << "Шар: центр = " << center << ", радиус = " << radius;
    return oss.str();
}

istream& Sphere::readFromStream(istream& is, Sphere& sphere)
{
    Point center;
    double radius;
    
    is >> center >> radius;
    
    if (is)
    {
        sphere = Sphere(center, radius);
    }
    
    return is;
}

ostream& operator<<(ostream& os, const Sphere& sphere)
{
    os << sphere.toString();
    return os;
}

istream& operator>>(istream& is, Sphere& sphere)
{
    return Sphere::readFromStream(is, sphere);
}
