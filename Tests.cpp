#include <cassert>
#include <iostream>
#include <vector>

#include "SequenceGenerator.h"
#include "Task1.h"
#include "Task2.h"

using namespace miit::algebra;

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

    assert(matrix[0] == 3);
    assert(matrix[1] == 0);
    assert(matrix[2] == 2);

    assert(matrix[3] == 5);
    assert(matrix[4] == 0);
    assert(matrix[5] == 6);

    assert(matrix[6] == 0);
    assert(matrix[7] == 9);
    assert(matrix[8] == 8);

    std::cout << "testTask1 passed\n";
}

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

int main()
{
    testTask1();
    testTask2();
    testTask2Partial();

    std::cout << "All tests passed\n";
    return 0;
}