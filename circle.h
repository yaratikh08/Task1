#pragma once

/**
 * @brief Класс, представляющий окружность на плоскости.
 */
class Circle
{
private:
    double centerX, centerY;  // Координаты центра окружности
    double radius;            // Радиус окружности

public:
    /**
     * @brief Конструктор для инициализации окружности.
     * @param x Координата x центра (по умолчанию 0).
     * @param y Координата y центра (по умолчанию 0).
     * @param r Радиус окружности (по умолчанию 1).
     */
    Circle(double x = 0.0, double y = 0.0, double r = 1.0);

    /**
     * @brief Возвращает координату x центра.
     * @return Значение координаты x.
     */
    double getCenterX() const;

    /**
     * @brief Возвращает координату y центра.
     * @return Значение координаты y.
     */
    double getCenterY() const;

    /**
     * @brief Возвращает радиус окружности.
     * @return Значение радиуса.
     */
    double getRadius() const;

    /**
     * @brief Устанавливает новый радиус.
     * @param r Новый радиус.
     */
    void setRadius(double r);

    /**
     * @brief Вычисляет площадь круга.
     * @return Площадь круга.
     */
    double area() const;

    /**
     * @brief Вычисляет длину окружности.
     * @return Длина окружности.
     */
    double circumference() const;

    /**
     * @brief Выводит параметры окружности на экран.
     */
    void print() const;
};