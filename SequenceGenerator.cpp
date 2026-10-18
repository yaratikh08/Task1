#include "SequenceGenerator.h"
#include <stdexcept>

namespace miit::algebra
{
    SequenceGenerator::SequenceGenerator(const std::vector<int> values)
        : values(std::move(values))
    {
    }

    int SequenceGenerator::generate()
    {
        if (position >= values.size())
        {
            throw std::out_of_range("SequenceGenerator: no more values");
        }

        return values[position++];
    }
}