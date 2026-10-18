#include "Exercise.h"

namespace miit::algebra
{
    Exercise::Exercise(
        const std::size_t rows,
        const std::size_t columns,
        Generator& generator
    )
        : matrix(rows, columns)
    {
        matrix.fill(generator);
    }

    const Matrix& Exercise::getMatrix() const noexcept
    {
        return matrix;
    }

    Matrix& Exercise::getMatrix() noexcept
    {
        return matrix;
    }
}