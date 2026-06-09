#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include "Point.h"

/**
 * @brief Класс шара в трехмерном пространстве
 */
class Sphere
{
private:
    Point centre; // центр шара
    double rad;   // радиус шара

public:
    /**
     * @brief Конструктор шара
     * @param centre центр шара
     * @param rad радиус шара
     */
    Sphere(const Point& centre = Point(), const double rad = 1);

    /**
     * @brief Конструктор копирования
     * @param other объект для копирования
     */
    Sphere(const Sphere& other);

    /**
     * @brief Конструктор перемещения
     * @param other объект для перемещения
     */
    Sphere(Sphere&& other);

    /**
     * @brief Деструктор
     */
    ~Sphere() = default;

    /**
     * @brief Оператор присваивания копированием
     * @param other объект для копирования
     * @return текущий объект
     */
    Sphere& operator=(const Sphere& other);

    /**
     * @brief Оператор присваивания перемещением
     * @param other объект для перемещения
     * @return текущий объект
     */
    Sphere& operator=(Sphere&& other);

    /**
     * @brief Получить центр шара
     * @return центр шара
     */
    Point GetCentre() const;

    /**
     * @brief Получить радиус шара
     * @return радиус шара
     */
    double GetRad() const;

    /**
     * @brief Вычислить площадь поверхности шара
     * @return площадь поверхности (4πR²)
     */
    double CalcArea() const;

    /**
     * @brief Вычислить объем шара
     * @return объем шара (4/3 πR³)
     */
    double CalcVolume() const;

    /**
     * @brief Оператор вывода шара в поток
     * @param os поток вывода
     * @param sphere шар
     * @return поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Sphere& sphere);
};