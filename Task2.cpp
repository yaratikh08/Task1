#include "Task2.h"

namespace miit::algebra
{
    Task2::Task2(
        const std::size_t rows,
        const std::size_t columns,
        Generator& generator
    )
        : Exercise(rows, columns, generator)
    {
    }

    void Task2::solve()
    {
        if (matrix.empty())
        {
            return;
        }

        const std::size_t rowCount = matrix.rows();

        // Идём справа налево, чтобы удаление столбца
        // не сдвигало индексы ещё не проверенных столбцов.
        for (std::size_t column = matrix.columns(); column-- > 0;)
        {
            bool needRemove = false;

            for (std::size_t row = 0; row < rowCount; ++row)
            {
                const int value = matrix[row * matrix.columns() + column];

                // Нечётный положительный элемент.
                if (value > 0 && value % 2 != 0)
                {
                    needRemove = true;
                    break;
                }
            }

            if (needRemove)
            {
                matrix.removeColumn(column);
            }
        }
    }
}