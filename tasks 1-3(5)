#include <stdio.h>
#include <stdlib.h>

/**
*@brief считает работу электрического тока
*@param I сила тока в ампера
*@param U напряжение в вольтах
*@param t время в минутах
*@return работа в джоулях
*/

double calculateWork(const double I, const double U, const double t);

/**
*@brief считывает значение, введенное с клавиатуры с проверкой ввода
*@return считанное значение
*/

double getValue();

/**
*@brief проверяет, что переменная положительная
*@param value значение проверяемой переменной
*/

void checkPositive(const double value);

/**
*@brief точка входа в программу
*@return возвращает 0, если программа выполнена корректно
*/

int main()
{
	printf("Введите значение силы тока в цепи (I, А): ");
	double I = getValue();
	checkPositive(I);
	printf("Введите значение напряжения (U, В): ");
	double U = getValue();
	checkPositive(U);
	double time_minutes = 20.0;
	double work = calculateWork(I, U, time_minutes);

	printf("\nРезультаты расчета:\n");
	printf("Сила тока: %.2f А\n", I);
	printf("Напряжение: %.2f В\n", U);
	printf("Время: %.0f минут\n", time_minutes);
	printf("Работа электрического тока: %.2f Дж\n", work);
	printf("Работа электрического тока: %.4f кДж\n", work / 1000);

	return 0;
}

double calculateWork(const double I, const double U, const double t)
{
	double time_seconds = t * 60;
	return U * I * time_seconds;
}

double getValue()
{
	double value = 0;
	if (!scanf("%lf", &value))
	{
		printf("Ошибка ввода! Пожалуйста, введите числовое значение.\n");
		abort();
	}
	return value;
}

void checkPositive(const double value)
{
	if (value <= 0)
	{
		printf("Ошибка! Значение должно быть положительным.\n");
		abort();
	}
}
