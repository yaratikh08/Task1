#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Point3.h"

/**
 * @brief Класс окружности на плоскости
 */
class Circle
{
private:
    Point center;
    double radius;

public:
    Circle(const double radius, const Point& center);
    Circle(const double radius,const double x,const double y);

    double getRadius() const;
    Point getCenter() const;

    void setRadius(const double radius);
    void setCenter(const Point& center);

    double getLength() const;
    double getArea() const;

    friend std::ostream& operator<<(std::ostream& os, const Circle& circle);
};
