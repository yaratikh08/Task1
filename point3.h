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
    Point(const double x = 0, const double y = 0, const double z = 0);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(const double x);
    void setY(const double y);
    void setZ(const double z);

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};
