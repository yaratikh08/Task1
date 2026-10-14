#include "Task1.h"

namespace miit::algebra
{
    Task1::Task1(
        const std::size_t rows,
        const std::size_t columns,
        Generator& generator
    )
        : Exercise(rows, columns, generator)
    {
    }

    void Task1::solve()
    {
        if (matrix.empty())
        {
            return;
        }

        const std::size_t rowCount = matrix.rows();
        const std::size_t columnCount = matrix.columns();

        for (std::size_t row = 0; row < rowCount; ++row)
        {
            // Предполагаем, что первый элемент строки — минимальный.
            int minimum = matrix[row * columnCount];
            std::size_t minimumIndex = row * columnCount;

            // Ищем минимальный элемент в строке.
            for (std::size_t column = 1; column < columnCount; ++column)
            {
                const std::size_t index = row * columnCount + column;

                if (matrix[index] < minimum)
                {
                    minimum = matrix[index];
                    minimumIndex = index;
                }
            }

            // Заменяем минимальный элемент строки нулём.
            matrix[minimumIndex] = 0;
        }
    }
}