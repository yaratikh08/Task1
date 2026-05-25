#pragma once
#include "Point.h"
#include <iostream>

/**
 * @brief Класс, представляющий шар в трехмерном пространстве.
 */
class Sphere
{
private:
    Point center;  // Центр шара
    double radius; // Радиус шара

public:
    /**
     * @brief Конструктор для инициализации шара.
     * @param center Центр шара.
     * @param radius Радиус шара.
     * @throw std::invalid_argument Если радиус не положительный.
     */
    Sphere(const Point& center = Point(), double radius = 1.0);

    /**
     * @brief Возвращает центр шара.
     * @return Центр шара.
     */
    Point getCenter() const;

    /**
     * @brief Возвращает радиус шара.
     * @return Радиус шара.
     */
    double getRadius() const;

    /**
     * @brief Устанавливает новый радиус.
     * @param radius Новый радиус.
     * @throw std::invalid_argument Если радиус не положительный.
     */
    void setRadius(const double radius);

    /**
     * @brief Вычисляет площадь поверхности шара.
     * @return Площадь поверхности (4πR²).
     */
    double surfaceArea() const;

    /**
     * @brief Вычисляет объем шара.
     * @return Объем шара (4/3 πR³).
     */
    double volume() const;

    /**
     * @brief Сериализация шара в строку.
     * @return Строковое представление шара.
     */
    std::string toString() const;

    /**
     * @brief Чтение шара из стандартного потока ввода.
     * @param is Входной поток.
     * @param sphere Ссылка на шар для заполнения.
     * @return Входной поток для цепочки операций.
     */
    static std::istream& readFromStream(std::istream& is, Sphere& sphere);
};

/**
 * @brief Оператор вывода шара в поток.
 * @param os Выходной поток.
 * @param sphere Шар для вывода.
 * @return Выходной поток для цепочки операций.
 */
std::ostream& operator<<(std::ostream& os, const Sphere& sphere);

/**
 * @brief Оператор ввода шара из потока.
 * @param is Входной поток.
 * @param sphere Шар для заполнения.
 * @return Входной поток для цепочки операций.
 */
std::istream& operator>>(std::istream& is, Sphere& sphere);