#include <gtest/gtest.h>
#include "Point.h"
#include "Sphere.h"

// ========== ТЕСТЫ ДЛЯ КЛАССА POINT ==========

// Тест: проверяет конструктор по умолчанию (должна быть точка (0,0,0))
TEST(PointTest, DefaultConstructor)
{
    Point p;  // создаём точку без параметров
    EXPECT_DOUBLE_EQ(p.GetX(), 0.0);  // проверяем X
    EXPECT_DOUBLE_EQ(p.GetY(), 0.0);  // проверяем Y
    EXPECT_DOUBLE_EQ(p.GetZ(), 0.0);  // проверяем Z
}

// Тест: проверяет конструктор с параметрами (должна быть точка (1,2,3))
TEST(PointTest, ParameterizedConstructor)
{
    Point p(1, 2, 3);  // создаём точку с координатами
    EXPECT_DOUBLE_EQ(p.GetX(), 1.0);
    EXPECT_DOUBLE_EQ(p.GetY(), 2.0);
    EXPECT_DOUBLE_EQ(p.GetZ(), 3.0);
}

// Тест: проверяет геттер GetX()
TEST(PointTest, GetX)
{
    Point p(5, 6, 7);
    EXPECT_DOUBLE_EQ(p.GetX(), 5.0);
}

// Тест: проверяет геттер GetY()
TEST(PointTest, GetY)
{
    Point p(5, 6, 7);
    EXPECT_DOUBLE_EQ(p.GetY(), 6.0);
}

// Тест: проверяет геттер GetZ()
TEST(PointTest, GetZ)
{
    Point p(5, 6, 7);
    EXPECT_DOUBLE_EQ(p.GetZ(), 7.0);
}

// Тест: проверяет оператор сравнения ==
TEST(PointTest, EqualityOperator)
{
    Point p1(1, 2, 3);
    Point p2(1, 2, 3);  // такая же точка
    Point p3(4, 5, 6);  // другая точка
    EXPECT_TRUE(p1 == p2);   // одинаковые точки -> true
    EXPECT_FALSE(p1 == p3);  // разные точки -> false
}

// Тест: проверяет оператор сравнения !=
TEST(PointTest, InequalityOperator)
{
    Point p1(1, 2, 3);
    Point p2(1, 2, 3);
    Point p3(4, 5, 6);
    EXPECT_FALSE(p1 != p2);  // одинаковые -> false
    EXPECT_TRUE(p1 != p3);   // разные -> true
}

// Тест: проверяет оператор < (лексикографическое сравнение)
TEST(PointTest, LessThanOperator)
{
    Point p1(0, 0, 1);  // расстояние 1 от начала
    Point p2(0, 0, 2);  // расстояние 2 от начала
    EXPECT_TRUE(p1 < p2);   // 1 < 2 -> true
    EXPECT_FALSE(p2 < p1);  // 2 < 1 -> false
}

// Тест: проверяет вывод точки в поток (operator<<)
TEST(PointTest, OutputOperator)
{
    Point p(2, 3, 4);
    std::stringstream ss;   // создаём строковый поток
    ss << p;                // выводим точку в поток
    std::string result = ss.str();  // получаем строку
    // проверяем, что в строке есть нужные числа
    EXPECT_NE(result.find("2"), std::string::npos);
    EXPECT_NE(result.find("3"), std::string::npos);
    EXPECT_NE(result.find("4"), std::string::npos);
}

// ========== ТЕСТЫ ДЛЯ КЛАССА SPHERE ==========

// Тест: проверяет конструктор сферы через точку
TEST(SphereTest, ConstructorWithPoint)
{
    Point centre(1, 2, 3);          // создаём центр
    Sphere s(centre, 5.0);          // создаём сферу
    EXPECT_DOUBLE_EQ(s.GetRad(), 5.0);  // проверяем радиус
    // проверяем координаты центра
    EXPECT_DOUBLE_EQ(s.GetCentre().GetX(), 1.0);
    EXPECT_DOUBLE_EQ(s.GetCentre().GetY(), 2.0);
    EXPECT_DOUBLE_EQ(s.GetCentre().GetZ(), 3.0);
}

// Тест: проверяет конструктор сферы через координаты
TEST(SphereTest, ConstructorWithCoordinates)
{
    Sphere s(5.0, 1, 2, 3);  // радиус, x, y, z
    EXPECT_DOUBLE_EQ(s.GetRad(), 5.0);
    EXPECT_DOUBLE_EQ(s.GetCentre().GetX(), 1.0);
    EXPECT_DOUBLE_EQ(s.GetCentre().GetY(), 2.0);
    EXPECT_DOUBLE_EQ(s.GetCentre().GetZ(), 3.0);
}

// Тест: проверяет, что конструктор выбрасывает исключение при отрицательном радиусе
TEST(SphereTest, ConstructorThrowsOnNegativeRadius)
{
    Point centre(0, 0, 0);
    // ожидаем, что при создании сферы с радиусом -5 выбросится исключение
    EXPECT_THROW(Sphere s(centre, -5.0), std::invalid_argument);
}

// Тест: проверяет, что конструктор выбрасывает исключение при нулевом радиусе
TEST(SphereTest, ConstructorThrowsOnZeroRadius)
{
    Point centre(0, 0, 0);
    EXPECT_THROW(Sphere s(centre, 0.0), std::invalid_argument);
}

// Тест: проверяет геттер радиуса
TEST(SphereTest, GetRad)
{
    Sphere s(7.5, 0, 0, 0);
    EXPECT_DOUBLE_EQ(s.GetRad(), 7.5);
}

// Тест: проверяет геттер центра
TEST(SphereTest, GetCentre)
{
    Point centre(1, 2, 3);
    Sphere s(centre, 5.0);
    Point result = s.GetCentre();
    EXPECT_DOUBLE_EQ(result.GetX(), 1.0);
    EXPECT_DOUBLE_EQ(result.GetY(), 2.0);
    EXPECT_DOUBLE_EQ(result.GetZ(), 3.0);
}

// Тест: проверяет площадь поверхности (формула 4πR² для R=1)
TEST(SphereTest, CalcArea)
{
    Sphere s(1.0, 0, 0, 0);
    double expected = 4.0 * M_PI;  // 4π
    EXPECT_NEAR(s.CalcArea(), expected, 0.0001);  // сравниваем с погрешностью
}

// Тест: проверяет площадь поверхности для радиуса 2
TEST(SphereTest, CalcAreaWithRadiusTwo)
{
    Sphere s(2.0, 0, 0, 0);
    double expected = 4.0 * M_PI * 4.0;  // 4π * 2² = 16π
    EXPECT_NEAR(s.CalcArea(), expected, 0.0001);
}

// Тест: проверяет объём (формула 4/3πR³ для R=1)
TEST(SphereTest, CalcVolume)
{
    Sphere s(1.0, 0, 0, 0);
    double expected = (4.0 / 3.0) * M_PI;
    EXPECT_NEAR(s.CalcVolume(), expected, 0.0001);
}

// Тест: проверяет объём для радиуса 2
TEST(SphereTest, CalcVolumeWithRadiusTwo)
{
    Sphere s(2.0, 0, 0, 0);
    double expected = (4.0 / 3.0) * M_PI * 8.0;  // 4/3π * 8 = 32/3π
    EXPECT_NEAR(s.CalcVolume(), expected, 0.0001);
}

// Тест: проверяет вывод сферы в поток
TEST(SphereTest, OutputOperator)
{
    Sphere s(3.0, 1, 2, 3);
    std::stringstream ss;      // создаём строковый поток
    ss << s;                   // выводим сферу в поток
    std::string result = ss.str();  // получаем строку
    // проверяем, что в строке есть слово "Сфера" и радиус 3
    EXPECT_NE(result.find("Сфера"), std::string::npos);
    EXPECT_NE(result.find("3"), std::string::npos);
}

// Тест: проверяет, что координаты центра могут быть отрицательными
TEST(SphereTest, NegativeCentreCoordinates)
{
    Sphere s(5.0, -10, -20, -30);
    EXPECT_DOUBLE_EQ(s.GetCentre().GetX(), -10.0);
    EXPECT_DOUBLE_EQ(s.GetCentre().GetY(), -20.0);
    EXPECT_DOUBLE_EQ(s.GetCentre().GetZ(), -30.0);
    EXPECT_NEAR(s.CalcArea(), 4.0 * M_PI * 25.0, 0.0001);
}

// Тест: проверяет конструктор копирования
TEST(SphereTest, CopyConstructor)
{
    Sphere original(Point(1, 2, 3), 5.0);  // оригинал
    Sphere copy = original;                // копия
    // проверяем, что копия совпадает с оригиналом
    EXPECT_DOUBLE_EQ(copy.GetRad(), original.GetRad());
    EXPECT_DOUBLE_EQ(copy.GetCentre().GetX(), original.GetCentre().GetX());
    EXPECT_DOUBLE_EQ(copy.GetCentre().GetY(), original.GetCentre().GetY());
    EXPECT_DOUBLE_EQ(copy.GetCentre().GetZ(), original.GetCentre().GetZ());
}

// Тест: проверяет оператор присваивания
TEST(SphereTest, AssignmentOperator)
{
    Sphere a(Point(1, 2, 3), 5.0);   // первая сфера
    Sphere b(Point(0, 0, 0), 1.0);   // вторая сфера
    b = a;                            // присваиваем a в b
    // проверяем, что b стало равно a
    EXPECT_DOUBLE_EQ(b.GetRad(), a.GetRad());
    EXPECT_DOUBLE_EQ(b.GetCentre().GetX(), a.GetCentre().GetX());
    EXPECT_DOUBLE_EQ(b.GetCentre().GetY(), a.GetCentre().GetY());
    EXPECT_DOUBLE_EQ(b.GetCentre().GetZ(), a.GetCentre().GetZ());
}