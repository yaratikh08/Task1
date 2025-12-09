#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief считывает вещественное значение с клавиатуры с проверкой ввода
 * @return возвращает считанное значение
 */
double getDouble(void);

/**
 * @brief Проверяет, что минимальное значение меньше максимального
 * @param min минимальное значение промежутка
 * @param max максимальное значение промежутка
 */
void checkMinMax(const double min, const double max);

/**
 * @brief Проверяет, что шаг функции больше нуля.
 * @param step значение шага функции
 */
void checkStep(const double step);

/**
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const double value);

/**
 * @brief Вычисляет значение функции f(x) = 1/4 * ln((1+x)/(1-x)) + 1/2 * arctg(x)
 * @param x значение параметра x
 * @return рассчитанное значение
 */
double calculateFunction(const double x);

/**
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param i текущий индекс
 * @param x значение параметра x
 * @return рассчитанное значение коэффициента
 */
double getRecurent(const int i, const double x);

/**
 * @brief рассчитывает сумму членов последовательности с точностью e
 * @param e заданная точность
 * @param x значение параметра x
 * @return рассчитанное значение
 */
double getSumE(const double e, const double x);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    printf("Введите min:\n");
    const double min = getDouble();
    printf("Введите max:\n");
    const double max = getDouble();
    checkMinMax(min, max);
    printf("Введите step:\n");
    const double step = getDouble();
    checkStep(step);
    printf("Введите e:\n");
    const double e = getDouble();
    checkPositive(e);
    for (double x = min; x < max + step; x += step)
      {
        printf("x = %.6lf, f(x) = %.6lf, S = %.6lf\n",
            x, calculateFunction(x), getSumE(e, x));
    }
    return 0;
}

double getDouble()
{
    double value = 0;
    int result = scanf("%lf", &value);
    if (result != 1) {
        fprintf(stderr, "Ошибка");
        exit(1);
    }
    return value;
}

void checkMinMax(const double min, const double max) 
{
    if (min > max || fabs(min - max) <= DBL_EPSILON) 
    {
        fprintf(stderr, "Max должен быть больше, чем min.");
        exit(1);
    }
}

void checkStep(const double step) 
{
    if (step < DBL_EPSILON)
    {
        fprintf(stderr, "Step должен быть больше 0");
        exit(1);
    }
}

void checkPositive(const double value)
{
    if (value < 0)
    {
        fprintf(stderr, "ошибка.");
        exit(1);
    }
}

double calculateFunction(const double x) 
{
    double log_part = log((1.0 + x) / (1.0 - x));
    double arctg_part = atan(x);
    return 0.25 * log_part + 0.5 * arctg_part;
}

double getRecurent(const int i, const double x)
{
    return pow(x, 4) * (4.0 * (i - 1.0) + 1.0) / (4.0 * (i - 1.0) + 5.0);
}

double getSumE(const double e, const double x)
{
    double current = 1;
    double result = current;
    for (int i = 1; fabs(current) > e; i++)
    {
        current *= getRecurent(i, x);
        result += current;
    }
    return result;
}
