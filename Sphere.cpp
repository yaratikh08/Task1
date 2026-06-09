#include "Sphere.h"
#include <sstream>

using namespace std;

Sphere::Sphere(const Point& centre, const double rad)
    : centre(centre), rad(rad)
{
    if (rad <= 0)
    {
        throw invalid_argument("радиус должен быть положительным");
    }
}

Sphere::Sphere(const Sphere& other)
    : centre(other.centre), rad(other.rad)
{
}

Sphere::Sphere(Sphere&& other)
    : centre(move(other.centre)), rad(other.rad)
{
    other.rad = 0;
}

Sphere& Sphere::operator=(const Sphere& other)
{
    if (this == &other)
    {
        return *this;
    }

    centre = other.centre;
    rad = other.rad;

    return *this;
}

Sphere& Sphere::operator=(Sphere&& other)
{
    if (this == &other)
    {
        return *this;
    }

    centre = move(other.centre);
    rad = other.rad;
    other.rad = 0;

    return *this;
}

Point Sphere::GetCentre() const
{
    return centre;
}

double Sphere::GetRad() const
{
    return rad;
}

double Sphere::CalcArea() const
{
    return 4 * M_PI * rad * rad;
}

double Sphere::CalcVolume() const
{
    return (4.0 / 3.0) * M_PI * rad * rad * rad;
}

ostream& operator<<(ostream& os, const Sphere& sphere)
{
    os << "—фера с центром " << sphere.centre << " и радиусом " << sphere.rad;
    return os;
}