#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief рассчитывает периметр прямоугольника
 * @param side1 первая сторона прямоугольника
 * @param side2 вторая сторона прямоугольника
 * @return возвращает рассчитанный периметр
 */
double getPerimeter(const double side1, const double side2);

/**
 * @brief рассчитывает площадь прямоугольника
 * @param side1 первая сторона прямоугольника
 * @param side2 вторая сторона прямоугольника
 * @return возвращает рассчитанную площадь
 */
double getPL(const double side1, const double side2);

/**
 * @brief рассчитывает длину диагонали прямоугольника
 * @param side1 первая сторона прямоугольника
 * @param side2 вторая сторона прямоугольника
 * @return возвращает рассчитанную длину диагонали
 */
double getDiagonal(const double side1, const double side2);

/**
 * @brief считывает значение с клавиатуры
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет, что переменная положительная
 * @param value значение проверяемой переменной
 */
void checkPositive(const double value);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    printf("Введите стороны прямоугольника: ");
    double side1 = getValue();
    checkPositive(side1);
    double side2 = getValue();
    checkPositive(side2);

    printf("Периметр равен: %.2lf\n", getPerimeter(side1, side2));
    printf("Площадь равна: %.2lf\n", getPL(side1, side2));
    printf("Длина диагонали равна: %.2lf\n", getDiagonal(side1, side2));

    return 0;
}

double getPerimeter(const double side1, const double side2)
{
    return 2 * (side1 + side2);
}

double getPL(const double side1, const double side2)
{
    return side1 * side2;
}

double getDiagonal(const double side1, const double side2)
{
    return sqrt(side1 * side1 + side2 * side2);
}

double getValue()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Ошибка ввода!\n");
        abort();
    }
    return value;
}

void checkPositive(const double value)
{
    if (value <= 0)
    {
        printf("Значение должно быть положительным!\n");
        abort();
    }
}
