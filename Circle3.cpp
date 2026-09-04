#include "Circle3.h"
#include <stdexcept>

using namespace std;

Circle::Circle(const double radius, const Point& center)
    : center(center), radius(radius)
{
    if (radius <= 0)
    {
        throw invalid_argument("Radius must be positive");
    }
}

Circle::Circle(const double radius, const double x, const double y)
    : center(Point(x, y, 0)),  radius(radius)
{
    if (radius <= 0)
    {
        throw invalid_argument("Radius must be positive");
    }
}

double Circle::getRadius() const { return radius; }
Point Circle::getCenter() const { return center; }

void Circle::setRadius(const double radius)
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
