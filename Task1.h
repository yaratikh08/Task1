#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Задание 1 варианта 7.
     * Заменяет минимальный элемент каждой строки нулем.
     */
    class Task1 final : public Exercise
    {
    public:
        /**
         * @brief Создаёт задание 1 и заполняет матрицу
         * @param rows - количество строк
         * @param columns - количество столбцов
         * @param generator - генератор значений
         */
        Task1(
            const std::size_t rows,
            const std::size_t columns,
            const Generator& generator
        );

        /**
         * @brief Выполняет задание 1.
         */
        void solve() override;
    };
}
