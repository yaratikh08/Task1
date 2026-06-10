#define _USE_MATH_DEFINES
#include <iostream>
#include <locale>
#include "Circle3.h"

using namespace std;

double inputDouble(const string& message);

int main()
{
    setlocale(LC_ALL, "Russian");

    try
    {
        double x = inputDouble("Введите x центра: ");
        double y = inputDouble("Введите y центра: ");
        double r = inputDouble("Введите радиус: ");

        Circle myCircle(r, x, y);

        cout << myCircle << endl;
        cout << "Длина окружности: " << myCircle.getLength() << endl;
        cout << "Площадь круга: " << myCircle.getArea() << endl;
    }
    catch (const exception& e)
    {
        cout << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}

double inputDouble(const string& message)
{
    cout << message;
    double value=0;
    cin >> value;

    if (cin.fail())
    {
        throw invalid_argument("Некорректный ввод");
    }

    return value;
}
