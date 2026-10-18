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
         * @brief Создаёт задание и заполняет матрицу
         * @param rows - количество строк
         * @param columns - количество столбцов
         * @param generator - генератор значений
         */
        Exercise(
            const std::size_t rows,
            const std::size_t columns,
            Generator& generator
        );

        /**
         * @brief Виртуальный деструктор задания
         */
        virtual ~Exercise() = default;

        /**
         * @brief Выполняет конкретное задание над матрицей
         */
        virtual void solve() = 0;

        /**
        * @brief Возвращает константную ссылку на матрицу
        * @return константная ссылка на матрицу
        */
        const Matrix& getMatrix() const noexcept;

        /**
         * @brief Возвращает ссылку на матрицу
         * @return ссылка на матрицу
         */
        Matrix& getMatrix() noexcept;
    };
}
