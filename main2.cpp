#include <iostream>
#include <string>
#include <cstdlib>
#include "Sphere.h"

using namespace std;

/*
* @brief Считывает значение с клавиатуры
* @param report - строка информации
* @return считанное значение
*/
double getValue(const string& report = "");

/*
* @brief Считывает координаты точки
* @return точка
*/
Point getPoint();

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    setlocale(LC_ALL, "Russian");

    Point centre = getPoint();
    double rad = getValue("Введите радиус шара: ");

    if (rad <= 0)
    {
        cout << "Ошибка, радиус должен быть положительным." << endl;
        exit(1);
    }

    Sphere mySphere(centre, rad);

    cout << mySphere << endl;
    cout << "Площадь поверхности: " << mySphere.CalcArea() << endl;
    cout << "Объем: " << mySphere.CalcVolume() << endl;

    return 0;
}

double getValue(const string& report)
{
    cout << report;
    double value = 0;
    cin >> value;

    if (cin.fail())
    {
        cout << "Ошибка, введено неверное значение." << endl;
        exit(1);
    }

    return value;
}

Point getPoint()
{
    double x = getValue("Введите x центра: ");
    double y = getValue("Введите y центра: ");
    double z = getValue("Введите z центра: ");

    return Point(x, y, z);
}