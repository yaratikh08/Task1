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

        /**
         * @brief Количество строк матрицы
         */
        std::size_t rowCount;

        /**
         * @brief Количество столбцов матрицы
         */
        std::size_t columnCount;

        /**
         * @brief Данные матрицы, хранятся как вектор строк
         */
        std::vector<std::vector<int>> data;

    public:
        /** @brief Создаёт пустую матрицу. 
        */
        Matrix();

        /**
         * @brief Создаёт матрицу заданного размера
         * @param rows - количество строк
         * @param columns - количество столбцов
         */
        Matrix(
            const std::size_t rows,
            const std::size_t columns
        );

        /**
         * @brief Создаёт матрицу и заполняет её значением
         * @param rows - количество строк
         * @param columns - количество столбцов
         * @param value - значение для заполнения
         */
        Matrix(
            const std::size_t rows,
            const std::size_t columns,
            const int value
        );

        /**
         * @brief Конструктор копирования
         */
        Matrix(const Matrix& other) = default;

        /**
         * @brief Конструктор перемещения
         */
        Matrix(Matrix&& other) noexcept = default;

        /**
         * @brief Оператор копирующего присваивания
         */
        Matrix& operator=(const Matrix& other) = default;

        /**
         * @brief Оператор перемещающего присваивания
         */
        Matrix& operator=(Matrix&& other) noexcept = default;

        /**
         * @brief Деструктор матрицы
         */
        ~Matrix() = default;

        /**
         * @brief Возвращает количество строк
         * @return количество строк
         */
        std::size_t rows() const noexcept;

        /**
         * @brief Возвращает количество столбцов
         * @return количество столбцов
         */
        std::size_t columns() const noexcept;

        /**
         * @brief Проверяет, пуста ли матрица
         * @return true, если матрица пустая
         */
        bool empty() const noexcept;

        /**
         * @brief Возвращает строку матрицы по номеру
         * @param row - номер строки
         * @return ссылка на строку
         */
        std::vector<int>& operator[](const std::size_t row);

        /**
         * @brief Возвращает константную строку по номеру
         * @param row - номер строки
         * @return константная ссылка на строку
         */
        const std::vector<int>& operator[](const std::size_t row) const;

        /**
         * @brief Заполняет матрицу значениями генератора
         * @param generator - генератор значений
         */
        void fill(Generator& generator);

        /**
         * @brief Удаляет столбец по номеру
         * @param column - номер столбца
         */
        void removeColumn(const std::size_t column);

        /**
         * @brief Преобразует матрицу в строку
         * @return строковое представление
         */
        std::string toString() const;

        /**
         * @brief Выводит матрицу в поток
         * @param output - поток вывода
         * @param matrix - матрица
         * @return ссылка на поток
         */
        friend std::ostream& operator<<(
            std::ostream& output,
            const Matrix& matrix
            );

        /**
         * @brief Считывает матрицу из потока
         * @param input - поток ввода
         * @param matrix - матрица
         * @return ссылка на поток
         */
        friend std::istream& operator>>(
            std::istream& input,
            Matrix& matrix
            );
    };
}
