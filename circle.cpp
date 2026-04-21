#include "Circle.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

const double PI = 3.14159265358979323846;

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
    return PI * radius * radius;
}

double Circle::circumference() const
{
    return 2 * PI * radius;
}

void Circle::print() const
{
    cout << "Окружность с центром в точке (" << centerX << ", " << centerY 
         << ") и радиусом " << radius << endl;
}