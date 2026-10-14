#pragma once

#include "Generator.h"
#include "Matrix.h"

namespace miit::algebra
{
    /**
     * @brief Базовый класс учебного задания над матрицей.
     */
    class Exercise
    {
    protected:
        Matrix matrix;

    public:
        /**
         * @brief Создаёт задание и заполняет его матрицу.
         */
        Exercise(
            const std::size_t rows,
            const std::size_t columns,
            Generator& generator
        )
            : matrix(rows, columns)
        {
            matrix.fill(generator);
        }

        virtual ~Exercise() = default;

        Exercise(const Exercise&) = delete;
        Exercise& operator=(const Exercise&) = delete;

        /** @brief Выполняет конкретное задание над матрицей. */
        virtual void solve() = 0;

        /** @brief Возвращает константную ссылку на матрицу. */
        const Matrix& getMatrix() const noexcept
        {
            return matrix;
        }

        /** @brief Возвращает ссылку на матрицу для изменения. */
        Matrix& getMatrix() noexcept
        {
            return matrix;
        }
    };
}