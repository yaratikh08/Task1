#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <numbers>
#include <locale>  
#include "Circle.h"

using namespace std;

double getRadius(const string report = "");

int main() {
    setlocale(LC_ALL, "Russian");  

    double radius = getRadius("Введите радиус: ");
    double x = getRadius("Введите x: ");
    double y = getRadius("Введите y: ");
    double z = getRadius("Введите z: ");

    Circle myCircle(radius);

    cout << "Длина окружности: " << myCircle.getLenght() << endl; 
    cout << "Площадь круга: " << myCircle.getArea() << endl;       
    cout << "Координаты: " << x << " " << y << " " << z << endl;   

    return 0;
}

double getRadius(const string report) {
    cout << report << endl;
    double radius = 0;
    cin >> radius;
    if (cin.fail()) {
        cout << "Ошибка ввода!\n"; 
        exit(1);
    }
    return radius;
}