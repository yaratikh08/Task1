#include "Point3.h"

using namespace std;

Point::Point(const double x,const double y,const double z) : x(x), y(y), z(z) {}

double Point::getX() const { return x; }
double Point::getY() const { return y; }
double Point::getZ() const { return z; }

void Point::setX(double x) { this->x = x; }
void Point::setY(double y) { this->y = y; }
void Point::setZ(double z) { this->z = z; }

ostream& operator<<(ostream& os, const Point& point)
{
    os << "(" << point.x << ", " << point.y << ", " << point.z << ")";
    return os;
}
