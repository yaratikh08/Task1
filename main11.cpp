#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <locale>  
#include "Circle1.h"

using namespace std;

double getRadius(const string report = "");

int main() {
    setlocale(LC_ALL, "Russian");  

    double radius = getRadius("Введите радиус: ");
    double x = getRadius("Введите x: ");
    double y = getRadius("Введите y: ");


    Circle myCircle(radius);

    cout << "Длина окружности: " << myCircle.getLength() << endl; 
    cout << "Площадь круга: " << myCircle.getArea() << endl;       
    cout << "Координаты: " << x << " " << y <<  endl;   

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