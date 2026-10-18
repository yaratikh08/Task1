#include <cassert>
#include <iostream>
#include <vector>

#include "ConstantGenerator.h"
#include "FunctionGenerator.h"
#include "RandomGenerator.h"
#include "SequenceGenerator.h"
#include "Matrix.h"
#include "Task1.h"
#include "Task2.h"

using namespace miit::algebra;

/**
 * @brief Тестирует ConstantGenerator
 */
void testConstantGenerator()
{
    ConstantGenerator gen(7);
    assert(gen.generate() == 7);
    assert(gen.generate() == 7);
    std::cout << "testConstantGenerator passed\n";
}

/**
 * @brief Тестирует FunctionGenerator
 */
void testFunctionGenerator()
{
    int counter = 0;
    FunctionGenerator gen([&counter]() { return ++counter; });
    assert(gen.generate() == 1);
    assert(gen.generate() == 2);
    std::cout << "testFunctionGenerator passed\n";
}

/**
 * @brief Тестирует RandomGenerator
 */
void testRandomGenerator()
{
    RandomGenerator gen(-5, 5);
    for (int i = 0; i < 100; ++i)
    {
        int val = gen.generate();
        assert(val >= -5 && val <= 5);
    }
    std::cout << "testRandomGenerator passed\n";
}

/**
 * @brief Тестирует SequenceGenerator
 */
void testSequenceGenerator()
{
    SequenceGenerator gen({ 10, 20, 30 });
    assert(gen.generate() == 10);
    assert(gen.generate() == 20);
    assert(gen.generate() == 30);
    std::cout << "testSequenceGenerator passed\n";
}

/**
 * @brief Тестирует конструкторы матрицы
 */
void testMatrixConstructors()
{
    Matrix m1;
    assert(m1.empty() == true);
    assert(m1.rows() == 0 && m1.columns() == 0);

    Matrix m2(2, 3);
    assert(m2.empty() == false);
    assert(m2.rows() == 2 && m2.columns() == 3);
    assert(m2[0][0] == 0);

    Matrix m3(2, 2, 9);
    assert(m3[0][0] == 9 && m3[1][1] == 9);

    std::cout << "testMatrixConstructors passed\n";
}

/**
 * @brief Тестирует удаление столбца матрицы
 */
void testMatrixRemoveColumn()
{
    Matrix m(2, 3, 5);
    m.removeColumn(1);
    assert(m.columns() == 2);
    assert(m[0][0] == 5 && m[0][1] == 5);
    std::cout << "testMatrixRemoveColumn passed\n";
}

/**
 * @brief Тестирует задание 1
 */
void testTask1()
{
    std::vector<int> values{
        3, 1, 2,
        5, 4, 6,
        0, 9, 8
    };

    SequenceGenerator generator(values);
    Task1 task(3, 3, generator);
    task.solve();

    const Matrix& matrix = task.getMatrix();

    assert(matrix[0][0] == 3 && matrix[0][1] == 0 && matrix[0][2] == 2);
    assert(matrix[1][0] == 5 && matrix[1][1] == 0 && matrix[1][2] == 6);
    assert(matrix[2][0] == 0 && matrix[2][1] == 9 && matrix[2][2] == 8);

    std::cout << "testTask1 passed\n";
}

/**
 * @brief Тестирует задание 2
 */
void testTask2()
{
    std::vector<int> values{
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12
    };

    SequenceGenerator generator(values);
    Task2 task(3, 4, generator);
    task.solve();

    assert(task.getMatrix().columns() == 0);
    assert(task.getMatrix().rows() == 3);

    std::cout << "testTask2 passed\n";
}

/**
 * @brief Тестирует задание 2 (частичное удаление)
 */
void testTask2Partial()
{
    std::vector<int> values{ 2, -3, 4, 6, 8, -1 };
    SequenceGenerator generator(values);
    Task2 task(2, 3, generator);
    task.solve();

    assert(task.getMatrix().columns() == 3);

    std::vector<int> values2{ 2, -3, 3, 6, 8, -1 };
    SequenceGenerator generator2(values2);
    Task2 task2(2, 3, generator2);
    task2.solve();

    assert(task2.getMatrix().columns() == 2);

    std::cout << "testTask2Partial passed\n";
}

/**
 * @brief Точка входа в тесты
 * @return 0 при успехе
 */
int main()
{
    testConstantGenerator();
    testFunctionGenerator();
    testRandomGenerator();
    testSequenceGenerator();
    testMatrixConstructors();
    testMatrixRemoveColumn();
    testTask1();
    testTask2();
    testTask2Partial();

    std::cout << "All tests passed\n";
    return 0;
}
