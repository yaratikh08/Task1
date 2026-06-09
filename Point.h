#pragma once
#include <iostream>

/**
 * @brief Класс точки в трехмерном пространстве
 */
class Point
{
private:
    double x; // координата X
    double y; // координата Y
    double z; // координата Z

public:
    /**
     * @brief Конструктор точки
     * @param x координата X
     * @param y координата Y
     * @param z координата Z
     */
    Point(const double x = 0, const double y = 0, const double z = 0);

    /**
     * @brief Конструктор копирования
     * @param other объект для копирования
     */
    Point(const Point& other);

    /**
     * @brief Конструктор перемещения
     * @param other объект для перемещения
     */
    Point(Point&& other);

    /**
     * @brief Деструктор
     */
    ~Point() = default;

    /**
     * @brief Оператор присваивания копированием
     * @param other объект для копирования
     * @return текущий объект
     */
    Point& operator=(const Point& other);

    /**
     * @brief Оператор присваивания перемещением
     * @param other объект для перемещения
     * @return текущий объект
     */
    Point& operator=(Point&& other);

    /**
     * @brief Получить координату X
     * @return координата X
     */
    double GetX() const;

    /**
     * @brief Получить координату Y
     * @return координата Y
     */
    double GetY() const;

    /**
     * @brief Получить координату Z
     * @return координата Z
     */
    double GetZ() const;

    /**
     * @brief Оператор сравнения на равенство
     * @param other другая точка
     * @return true если точки равны
     */
    bool operator==(const Point& other) const;

    /**
     * @brief Оператор сравнения на неравенство
     * @param other другая точка
     * @return true если точки не равны
     */
    bool operator!=(const Point& other) const;

    /**
     * @brief Оператор сравнения меньше
     * @param other другая точка
     * @return true если текущая точка меньше other
     */
    bool operator<(const Point& other) const;

    /**
     * @brief Оператор сравнения меньше или равно
     * @param other другая точка
     * @return true если текущая точка меньше или равна other
     */
    bool operator<=(const Point& other) const;

    /**
     * @brief Оператор сравнения больше
     * @param other другая точка
     * @return true если текущая точка больше other
     */
    bool operator>(const Point& other) const;

    /**
     * @brief Оператор сравнения больше или равно
     * @param other другая точка
     * @return true если текущая точка больше или равна other
     */
    bool operator>=(const Point& other) const;

    /**
     * @brief Оператор вывода точки в поток
     * @param os поток вывода
     * @param point точка
     * @return поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& point);

    /**
     * @brief Оператор ввода точки из потока
     * @param is поток ввода
     * @param point точка
     * @return поток ввода
     */
    friend std::istream& operator>>(std::istream& is, Point& point);
};