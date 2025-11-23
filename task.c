#define _USE_MATH_DEFINES // for C
#include <math.h>
#include <stdio.h>

/**
 * @brief Рассчитывает функцию В по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
double getB(const double x, const double y, const double z);

/**
 * @brief Рассчитывает функцию A по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
double getA(const double x, const double y, const double z);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main()
{
    const double x = -2.9;
    const double y = 15.5;
    const double z = 1.5;
    printf("A = %6lf\n", getA(x, y, z));
    printf("B = %6lf\n", getB(x, y, z));
    return 0;
}

double getB(const double x, const double y, const double z)
{
    return cos(pow(x,3)) * cos(pow(x,3)) - x / (sqrt(pow(z,2) + pow(y,2)));
}

double getA(const double x, const double y, const double z)
{
    return sqrt(pow(x,2) + y) - y * y * sin((x + z) / x) * sin((x + z) / x) * sin((x + z) / x);
}
