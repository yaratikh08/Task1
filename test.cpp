#define _USE_MATH_DEFINES
#include "CppUnitTest.h"
#include "Circle.h"
#include "Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CircleTests
{
    // ========== Тесты для класса Point ==========
    
    TEST_CLASS(PointTests)
    {
    public:

        TEST_METHOD(Point_DefaultConstructor_Test)
        {
            Point p;
            Assert::AreEqual(0.0, p.getX(), 0.0001);
            Assert::AreEqual(0.0, p.getY(), 0.0001);
            Assert::AreEqual(0.0, p.getZ(), 0.0001);
        }

        TEST_METHOD(Point_ParameterizedConstructor_Test)
        {
            Point p(1.5, 2.5, 3.5);
            Assert::AreEqual(1.5, p.getX(), 0.0001);
            Assert::AreEqual(2.5, p.getY(), 0.0001);
            Assert::AreEqual(3.5, p.getZ(), 0.0001);
        }

        TEST_METHOD(Point_DistanceTo_Test)
        {
            Point p1(0, 0, 0);
            Point p2(3, 4, 0);
            double distance = p1.distanceTo(p2);
            Assert::AreEqual(5.0, distance, 0.0001);
        }

        TEST_METHOD(Point_SubtractionOperator_Test)
        {
            Point p1(10, 10, 10);
            Point p2(1, 2, 3);
            Point p3 = p1 - p2;
            Assert::AreEqual(9.0, p3.getX(), 0.0001);
            Assert::AreEqual(8.0, p3.getY(), 0.0001);
            Assert::AreEqual(7.0, p3.getZ(), 0.0001);
        }

        TEST_METHOD(Point_Equality_Test)
        {
            Point p1(1, 2, 3);
            Point p2(1, 2, 3);
            Assert::IsTrue(p1 == p2);
        }

        TEST_METHOD(Point_Inequality_Test)
        {
            Point p1(1, 2, 3);
            Point p2(3, 2, 1);
            Assert::IsTrue(p1 != p2);
        }
    };

    // ========== Тесты для класса Circle ==========

    TEST_CLASS(CircleTests)
    {
    public:

        TEST_METHOD(Circle_DefaultConstructor_Test)
        {
            Circle c;
            Assert::AreEqual(0.0, c.getCenterX(), 0.0001);
            Assert::AreEqual(0.0, c.getCenterY(), 0.0001);
            Assert::AreEqual(1.0, c.getRadius(), 0.0001);
        }

        TEST_METHOD(Circle_ParameterizedConstructor_Test)
        {
            Circle c(2.0, 3.0, 5.0);
            Assert::AreEqual(2.0, c.getCenterX(), 0.0001);
            Assert::AreEqual(3.0, c.getCenterY(), 0.0001);
            Assert::AreEqual(5.0, c.getRadius(), 0.0001);
        }

        TEST_METHOD(Circle_ConstructorThrowsOnNegativeRadius_Test)
        {
            auto func = []() { Circle c(0, 0, -5.0); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(Circle_ConstructorThrowsOnZeroRadius_Test)
        {
            auto func = []() { Circle c(0, 0, 0.0); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(Circle_GetCenterX_Test)
        {
            Circle c(1.0, 2.0, 3.0);
            Assert::AreEqual(1.0, c.getCenterX(), 0.0001);
        }

        TEST_METHOD(Circle_GetCenterY_Test)
        {
            Circle c(1.0, 2.0, 3.0);
            Assert::AreEqual(2.0, c.getCenterY(), 0.0001);
        }

        TEST_METHOD(Circle_GetRadius_Test)
        {
            Circle c(0, 0, 7.5);
            Assert::AreEqual(7.5, c.getRadius(), 0.0001);
        }

        TEST_METHOD(Circle_SetRadius_Test)
        {
            Circle c;
            c.setRadius(10.0);
            Assert::AreEqual(10.0, c.getRadius(), 0.0001);
        }

        TEST_METHOD(Circle_SetRadiusThrowsOnNegative_Test)
        {
            Circle c;
            auto func = [&c]() { c.setRadius(-5.0); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(Circle_SetRadiusThrowsOnZero_Test)
        {
            Circle c;
            auto func = [&c]() { c.setRadius(0.0); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(Circle_Area_Test)
        {
            Circle c(0, 0, 2.0);
            double expected = M_PI * 4.0;
            double actual = c.area();
            Assert::AreEqual(expected, actual, 0.0001);
        }

        TEST_METHOD(Circle_AreaWithRadiusOne_Test)
        {
            Circle c(0, 0, 1.0);
            double expected = M_PI;
            double actual = c.area();
            Assert::AreEqual(expected, actual, 0.0001);
        }

        TEST_METHOD(Circle_AreaWithRadiusThree_Test)
        {
            Circle c(0, 0, 3.0);
            double expected = M_PI * 9.0;
            double actual = c.area();
            Assert::AreEqual(expected, actual, 0.0001);
        }

        TEST_METHOD(Circle_Circumference_Test)
        {
            Circle c(0, 0, 3.0);
            double expected = 2.0 * M_PI * 3.0;
            double actual = c.circumference();
            Assert::AreEqual(expected, actual, 0.0001);
        }

        TEST_METHOD(Circle_CircumferenceWithRadiusOne_Test)
        {
            Circle c(0, 0, 1.0);
            double expected = 2.0 * M_PI;
            double actual = c.circumference();
            Assert::AreEqual(expected, actual, 0.0001);
        }

        TEST_METHOD(Circle_Print_Test)
        {
            Circle c(1, 2, 3.0);
            
            // Перенаправляем вывод в строковый поток
            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
            c.print();
            std::cout.rdbuf(old);
            
            std::string result = buffer.str();
            Assert::IsTrue(result.find("Окружность") != std::string::npos);
            Assert::IsTrue(result.find("1") != std::string::npos);
            Assert::IsTrue(result.find("2") != std::string::npos);
            Assert::IsTrue(result.find("3") != std::string::npos);
        }

        TEST_METHOD(Circle_MultipleCircles_Test)
        {
            Circle c1(0, 0, 2.0);
            Circle c2(5, 5, 2.0);
            
            Assert::AreEqual(c1.area(), c2.area(), 0.0001);
            Assert::AreEqual(c1.circumference(), c2.circumference(), 0.0001);
            Assert::AreEqual(0.0, c1.getCenterX(), 0.0001);
            Assert::AreEqual(5.0, c2.getCenterX(), 0.0001);
        }

        TEST_METHOD(Circle_LargeRadius_Test)
        {
            Circle c(0, 0, 1000.0);
            double expectedArea = M_PI * 1000000.0;
            double expectedCircumference = 2.0 * M_PI * 1000.0;
            
            Assert::AreEqual(expectedArea, c.area(), 0.1);
            Assert::AreEqual(expectedCircumference, c.circumference(), 0.1);
        }

        TEST_METHOD(Circle_SmallRadius_Test)
        {
            Circle c(0, 0, 0.001);
            double expectedArea = M_PI * 0.000001;
            double expectedCircumference = 2.0 * M_PI * 0.001;
            
            Assert::AreEqual(expectedArea, c.area(), 1e-10);
            Assert::AreEqual(expectedCircumference, c.circumference(), 1e-9);
        }

        TEST_METHOD(Circle_NegativeCenterCoordinates_Test)
        {
            Circle c(-10, -20, 5.0);
            Assert::AreEqual(-10.0, c.getCenterX(), 0.0001);
            Assert::AreEqual(-20.0, c.getCenterY(), 0.0001);
            Assert::AreEqual(M_PI * 25.0, c.area(), 0.0001);
        }
    };
}
