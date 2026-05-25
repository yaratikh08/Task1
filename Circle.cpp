#define _USE_MATH_DEFINES
#include "Circle.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

Circle::Circle(double x, double y, double r) : centerX(x), centerY(y), radius(r)
{
    if (r <= 0)
    {
        throw invalid_argument("Радиус должен быть положительным числом");
    }
}

double Circle::getCenterX() const { return centerX; }
double Circle::getCenterY() const { return centerY; }
double Circle::getRadius() const { return radius; }

void Circle::setRadius(double r)
{
    if (r <= 0)
    {
        throw invalid_argument("Радиус должен быть положительным числом");
    }
    radius = r;
}

double Circle::area() const
{
    return M_PI * radius * radius;
}

double Circle::circumference() const
{
    return 2 * M_PI * radius;
}

void Circle::print() const
{
    cout << "Окружность с центром в точке (" << centerX << ", " << centerY
        << ") и радиусом " << radius << endl;
}