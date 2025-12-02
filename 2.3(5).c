#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Вычисляет общий пройденный путь
 * @param v1 скорость на первом участке
 * @param t1 время на первом участке
 * @param v2 скорость на втором участке
 * @param t2 время на втором участке
 * @param v3 скорость на третьем участке
 * @param t3 время на третьем участке
 * @return общий путь
 */
double totalPath(const double v1, const double t1,
    const double v2, const double t2,
    const double v3, const double t3);

/**
 * @brief Вычисляет время, за которое пройдена половина пути
 * @param v1 скорость на первом участке
 * @param t1 время на первом участке
 * @param v2 скорость на втором участке
 * @param t2 время на втором участке
 * @param v3 скорость на третьем участке
 * @param t3 время на третьем участке
 * @param halfPath половина общего пути
 * @return время для преодоления половины пути
 */
double timeToHalfPath(const double v1, const double t1,
    const double v2, const double t2,
    const double v3, const double t3,
    const double halfPath);

/**
 * @brief Считывает значение, введённое с клавиатуры, и проверяет корректность ввода.
 * @return возвращает введённое значение
 */
double getValue(void);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main(void) 
{
    printf("Введите скорость на первом участке (v1):\n");
    double v1 = getValue();
    printf("Введите время на первом участке (t1):\n");
    double t1 = getValue();

    printf("Введите скорость на втором участке (v2):\n");
    double v2 = getValue();
    printf("Введите время на втором участке (t2):\n");
    double t2 = getValue();

    printf("Введите скорость на третьем участке (v3):\n");
    double v3 = getValue();
    printf("Введите время на третьем участке (t3):\n");
    double t3 = getValue();

    double path = totalPath(v1, t1, v2, t2, v3, t3);
    double halfPath = path / 2;

    printf("Общий пройденный путь: %.2lf\n", path);
    printf("Половина пути: %.2lf\n", halfPath);

    double timeHalf = timeToHalfPath(v1, t1, v2, t2, v3, t3, halfPath);

    printf("Время для преодоления половины пути: %.2lf часов\n", timeHalf);

    return 0;
}

double getValue(void) 
{
    double value = 0;
    double result = scanf("%lf", &value);
    if (result != 1 || value < 0) 
    {
        fprintf(stderr, "Ошибка ввода: введите положительное число\n");
        exit(1);
    }
    return value;
}

double totalPath(const double v1, const double t1,
    const double v2, const double t2,
    const double v3, const double t3)
{
    return v1 * t1 + v2 * t2 + v3 * t3;
}

double timeToHalfPath(const double v1, const double t1,
    const double v2, const double t2,
    const double v3, const double t3,
    const double halfPath) 
{
    double accumulatedPath = 0;
    double timeSpent = 0;

    // Проверяем первый участок
    double path1 = v1 * t1;
    if (accumulatedPath + path1 >= halfPath)
    {
        // Половина пути достигается на первом участке
        double remainingPath = halfPath - accumulatedPath;
        return timeSpent + remainingPath / v1;
    }
    accumulatedPath += path1;
    timeSpent += t1;

    // Проверяем второй участок
    double path2 = v2 * t2;
    if (accumulatedPath + path2 >= halfPath) 
    {
        // Половина пути достигается на втором участке
        double remainingPath = halfPath - accumulatedPath;
        return timeSpent + remainingPath / v2;
    }
    accumulatedPath += path2;
    timeSpent += t2;

    // Половина пути достигается на третьем участке
    double remainingPath = halfPath - accumulatedPath;
    return timeSpent + remainingPath / v3;
}
