#include "Point.h"
#include "Sphere.h"
#include <iostream>
#include <locale>
#include <stdexcept>

using namespace std;

/**
 * @brief Функция демонстрации работы с классом Point.
 */
void demonstratePoint()
{
    cout << "\n=== Демонстрация работы с классом Point ===" << endl;
    
    Point p1(1, 2, 3);
    Point p2(4, 5, 6);
    
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    
    cout << "p1 == p2? " << (p1 == p2 ? "Да" : "Нет") << endl;
    cout << "p1 != p2? " << (p1 != p2 ? "Да" : "Нет") << endl;
    
    Point p3;
    cout << "\nВведите координаты точки (x y z): ";
    cin >> p3;
    cout << "Вы ввели: " << p3 << endl;
}

/**
 * @brief Функция демонстрации работы с классом Sphere.
 */
void demonstrateSphere()
{
    cout << "\n=== Демонстрация работы с классом Sphere ===" << endl;
    
    // Создание шара
    Point center(0, 0, 0);
    Sphere sphere1(center, 5.0);
    
    cout << sphere1 << endl;
    cout << "Площадь поверхности: " << sphere1.surfaceArea() << endl;
    cout << "Объем: " << sphere1.volume() << endl;
    
    // Создание шара через конструктор по умолчанию
    Sphere sphere2;
    cout << "\nШар по умолчанию: " << sphere2 << endl;
    
    // Ввод шара с клавиатуры
    cout << "\nВведите шар (центр x y z и радиус): ";
    Sphere sphere3;
    cin >> sphere3;
    cout << "Вы ввели: " << sphere3 << endl;
    cout << "Площадь поверхности: " << sphere3.surfaceArea() << endl;
    cout << "Объем: " << sphere3.volume() << endl;
}

/**
 * @brief Функция демонстрации обработки исключений.
 */
void demonstrateException()
{
    cout << "\n=== Демонстрация обработки исключений ===" << endl;
    
    try
    {
        Point center(1, 1, 1);
        Sphere invalidSphere(center, -5.0); // Это вызовет исключение
    }
    catch (const invalid_argument& e)
    {
        cout << "Ошибка: " << e.what() << endl;
    }
    
    try
    {
        Sphere sphere;
        sphere.setRadius(-10.0); // Это тоже вызовет исключение
    }
    catch (const invalid_argument& e)
    {
        cout << "Ошибка: " << e.what() << endl;
    }
}

/**
 * @brief Точка входа в программу.
 * @return 0 в случае успешного завершения программы.
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    
    try
    {
        demonstratePoint();
        demonstrateSphere();
        demonstrateException();
    }
    catch (const exception& e)
    {
        cout << "Необработанная ошибка: " << e.what() << endl;
        return 1;
    }
    
    cout << "\nПрограмма успешно завершена!" << endl;
    return 0;
}
