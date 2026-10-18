#pragma once

#include "Generator.h"
#include <vector>
#include <cstddef>

namespace miit::algebra
{
    /**
     * @brief Генератор последовательности заранее заданных чисел.
     */
    class SequenceGenerator final : public Generator
    {
    private:
        /**
         * @brief Вектор чисел, которые выдаются по порядку
         */
        std::vector<int> values;
        /**
         * @brief Текущая позиция в векторе
         */
        std::size_t position = 0;

    public:
        /**
         * @brief Создаёт генератор из последовательности
         * @param values - набор чисел для последовательной выдачи
         */
        explicit SequenceGenerator(const std::vector<int> values);

        /**
         * @brief Возвращает следующее число последовательности
         * @return следующее целое число
         */
        int generate() override;
    };
}
