#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Задание 1 варианта 7.
     *
     * Заменяет минимальный элемент каждой строки нулем.
     */
    class Task1 final : public Exercise
    {
    public:
        /**
         * @brief Создаёт объект задания 1 и заполняет матрицу.
         */
        Task1(
            const std::size_t rows,
            const std::size_t columns,
            Generator& generator
        );

        /**
         * @brief Выполняет задание 1.
         */
        void solve() override;
    };
}