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
        std::vector<int> values;
        std::size_t position = 0;

    public:
        explicit SequenceGenerator(const std::vector<int> values);

        int generate() override;
    };
}