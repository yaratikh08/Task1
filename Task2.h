#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Задание 2 варианта 7.
     * Удаляет все столбцы, в которых встретится нечетный положительный элемент.
     */
    class Task2 final : public Exercise
    {
    public:
        /**
         * @brief Создаёт задание 2 и заполняет матрицу
         * @param rows - количество строк
         * @param columns - количество столбцов
         * @param generator - генератор значений
         */
        Task2(
            const std::size_t rows,
            const std::size_t columns,
            Generator& generator
        );

        /**
         * @brief Выполняет задание 2.
         */
        void solve() override;
    };
}
