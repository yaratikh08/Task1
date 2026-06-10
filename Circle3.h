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
    Circle(double radius, const Point& center);
    Circle(double radius, double x, double y);

    double getRadius() const;
    Point getCenter() const;

    void setRadius(double radius);
    void setCenter(const Point& center);

    double getLength() const;
    double getArea() const;

    friend std::ostream& operator<<(std::ostream& os, const Circle& circle);
};