#pragma once
#include <iostream>

/**
 * @brief Класс точки в трехмерном пространстве
 */
class Point
{
private:
    double x, y, z;

public:
    Point(double x = 0, double y = 0, double z = 0);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};