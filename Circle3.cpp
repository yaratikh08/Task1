#include "Circle3.h"
#include <stdexcept>

using namespace std;

Circle::Circle(double radius, const Point& center)
    : radius(radius), center(center)
{
    if (radius <= 0)
    {
        throw invalid_argument("Radius must be positive");
    }
}

Circle::Circle(double radius, double x, double y)
    : radius(radius), center(Point(x, y, 0))
{
    if (radius <= 0)
    {
        throw invalid_argument("Radius must be positive");
    }
}

double Circle::getRadius() const { return radius; }
Point Circle::getCenter() const { return center; }

void Circle::setRadius(double radius)
{
    if (radius <= 0)
    {
        throw invalid_argument("Radius must be positive");
    }
    this->radius = radius;
}

void Circle::setCenter(const Point& center) { this->center = center; }

double Circle::getLength() const
{
    return 2 * M_PI * radius;
}

double Circle::getArea() const
{
    return M_PI * radius * radius;
}

ostream& operator<<(ostream& os, const Circle& circle)
{
    os << "Окружность с центром " << circle.center << " и радиусом " << circle.radius;
    return os;
}