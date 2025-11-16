#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief вычисляет значение функции y в зависимости от x
 * @param x аргумент функции
 * @return возвращает вычисленное значение y
 */
double calculateY(const double x);

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    const double a = 2.3;

    printf("Введите значение x: ");
    double x = getValue();

    double y = calculateY(x);
    printf("При x = %.2lf, y = %.6lf\n", x, y);

    return 0;
}

double calculateY(const double x)
{
    if (x < 2.0)
    {
        return 1.5 * pow(cos(x), 2);
    }
    else
    {
        return pow(x - 2.0, 2) + 6.0;
    }
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
