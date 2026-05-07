#pragma once
#include <iostream>

/**
 * @brief Класс, представляющий точку в трехмерном пространстве.
 */
class Point
{
private:
    double x, y, z;

public:
    /**
     * @brief Конструктор для инициализации точки.
     * @param x Координата x (по умолчанию 0).
     * @param y Координата y (по умолчанию 0).
     * @param z Координата z (по умолчанию 0).
     */
    Point(double x = 0.0, double y = 0.0, double z = 0.0);

    /**
     * @brief Возвращает координату x.
     * @return Значение координаты x.
     */
    double getX() const;

    /**
     * @brief Возвращает координату y.
     * @return Значение координаты y.
     */
    double getY() const;

    /**
     * @brief Возвращает координату z.
     * @return Значение координаты z.
     */
    double getZ() const;

    /**
     * @brief Сериализация точки в строку.
     * @return Строковое представление точки.
     */
    std::string toString() const;

    /**
     * @brief Чтение точки из стандартного потока ввода.
     * @param is Входной поток.
     * @param point Ссылка на точку для заполнения.
     * @return Входной поток для цепочки операций.
     */
    static std::istream& readFromStream(std::istream& is, Point& point);
};

/**
 * @brief Оператор вывода точки в поток.
 * @param os Выходной поток.
 * @param point Точка для вывода.
 * @return Выходной поток для цепочки операций.
 */
std::ostream& operator<<(std::ostream& os, const Point& point);

/**
 * @brief Оператор ввода точки из потока.
 * @param is Входной поток.
 * @param point Точка для заполнения.
 * @return Входной поток для цепочки операций.
 */
std::istream& operator>>(std::istream& is, Point& point);

/**
 * @brief Оператор сравнения точек (равенство).
 * @param p1 Первая точка.
 * @param p2 Вторая точка.
 * @return true, если точки совпадают, иначе false.
 */
bool operator==(const Point& p1, const Point& p2);

/**
 * @brief Оператор сравнения точек (неравенство).
 * @param p1 Первая точка.
 * @param p2 Вторая точка.
 * @return true, если точки не совпадают, иначе false.
 */
bool operator!=(const Point& p1, const Point& p2);
