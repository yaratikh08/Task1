#pragma once

#include "Generator.h"

#include <cstddef>
#include <iosfwd>
#include <string>
#include <vector>

namespace miit::algebra
{
    /**
     * @brief Класс двумерной целочисленной матрицы.
     */
    class Matrix
    {
    private:
        std::size_t rowCount;
        std::size_t columnCount;
        std::vector<int> data;

        /**
         * @brief Вычисляет плоский индекс элемента матрицы.
         * @throw std::out_of_range Если строка или столбец выходят за границы.
         */
        std::size_t offset(
            const std::size_t row,
            const std::size_t column
        ) const;

    public:
        /** @brief Создаёт пустую матрицу. */
        Matrix();

        /** @brief Создаёт матрицу заданного размера. */
        Matrix(
            const std::size_t rows,
            const std::size_t columns
        );

        /** @brief Создаёт матрицу и заполняет её значением. */
        Matrix(
            const std::size_t rows,
            const std::size_t columns,
            const int value
        );

        Matrix(const Matrix& other) = default;
        Matrix(Matrix&& other) noexcept = default;
        Matrix& operator=(const Matrix& other) = default;
        Matrix& operator=(Matrix&& other) noexcept = default;
        ~Matrix() = default;

        /** @brief Возвращает количество строк. */
        std::size_t rows() const noexcept;

        /** @brief Возвращает количество столбцов. */
        std::size_t columns() const noexcept;

        /** @brief Проверяет, является ли матрица пустой. */
        bool empty() const noexcept;

        /** @brief Возвращает элемент матрицы по плоскому индексу. */
        int& operator[](const std::size_t index);

        /** @brief Возвращает элемент константной матрицы. */
        const int& operator[](const std::size_t index) const;

        /** @brief Заполняет матрицу значениями генератора. */
        void fill(Generator& generator);

        /** @brief Удаляет один столбец матрицы. */
        void removeColumn(const std::size_t column);

        /** @brief Преобразует матрицу в строку. */
        std::string toString() const;

        friend std::ostream& operator<<(
            std::ostream& output,
            const Matrix& matrix
            );

        friend std::istream& operator>>(
            std::istream& input,
            Matrix& matrix
            );
    };
}