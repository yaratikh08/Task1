#include "Matrix.h"
#include <algorithm>
#include <ios>
#include <ostream>
#include <istream>
#include <sstream>
#include <stdexcept>
#include <utility>

namespace miit::algebra
{
    Matrix::Matrix()
        : rowCount(0),
        columnCount(0)
    {
    }

    Matrix::Matrix(const std::size_t rows, const std::size_t columns)
        : rowCount(rows),
        columnCount(columns),
        data(rows, std::vector<int>(columns))
    {
    }

    Matrix::Matrix(
        const std::size_t rows,
        const std::size_t columns,
        const int value
    )
        : rowCount(rows),
        columnCount(columns),
        data(rows, std::vector<int>(columns, value))
    {
    }

    std::size_t Matrix::rows() const noexcept
    {
        return rowCount;
    }

    std::size_t Matrix::columns() const noexcept
    {
        return columnCount;
    }

    bool Matrix::empty() const noexcept
    {
        return data.empty();
    }

    std::vector<int>& Matrix::operator[](const std::size_t row)
    {
        if (row >= data.size())
        {
            throw std::out_of_range("Row index is out of range");
        }
        return data[row];
    }

    const std::vector<int>& Matrix::operator[](const std::size_t row) const
    {
        if (row >= data.size())
        {
            throw std::out_of_range("Row index is out of range");
        }
        return data[row];
    }

    void Matrix::fill(const Generator& generator)
    {
        for (auto& row : data)
        {
            for (auto& value : row)
            {
                value = generator.generate();
            }
        }
    }

    void Matrix::removeColumn(const std::size_t column)
    {
        if (column >= columnCount)
        {
            throw std::out_of_range("Column index is out of range");
        }

        for (auto& row : data)
        {
            row.erase(row.begin() + column);
        }

        --columnCount;
    }

    std::string Matrix::toString() const
    {
        std::ostringstream output;

        for (std::size_t row = 0; row < rowCount; ++row)
        {
            for (std::size_t column = 0; column < columnCount; ++column)
            {
                if (column != 0)
                {
                    output << ' ';
                }

                output << data[row][column];
            }

            if (row + 1 < rowCount)
            {
                output << '\n';
            }
        }

        return output.str();
    }

    std::ostream& operator<<(std::ostream& output, const Matrix& matrix)
    {
        output << matrix.toString();
        return output;
    }

    std::istream& operator>>(std::istream& input, Matrix& matrix)
    {
        for (auto& row : matrix.data)
        {
            for (int& value : row)
            {
                input >> value;
            }
        }
        return input;
    }
}
