#include "Circle.h"
#include <iostream>
#include <locale>
#include <stdexcept>

using namespace std;

/**
 * @brief Функция создания окружности с вводом данных с клавиатуры.
 */
Circle getCircle();

/**
 * @brief Точка входа в программу.
 * @return 0 в случае успешного завершения программы.
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    
    try
    {
        Circle circle = getCircle();
        circle.print();
        cout << "Площадь круга: " << circle.area() << endl;
        cout << "Длина окружности: " << circle.circumference() << endl;
    }
    catch (const exception& e)
    {
        cout << "Ошибка: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}

Circle getCircle()
{
    double x = 0.0;
    double y = 0.0;
    double r = 0.0;
    
    cout << "Введите координаты центра окружности:" << endl;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    
    cout << "Введите радиус окружности: ";
    cin >> r;
    
    if (cin.fail())
    {
        throw invalid_argument("Введено некорректное значение");
    }
    
    return Circle(x, y, r);
}