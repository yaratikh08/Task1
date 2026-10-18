#pragma once

#include "Generator.h"
#include <functional>

namespace miit::algebra
{
    /**
     * @brief Генератор значений с использованием пользовательской функции.
     */
    class FunctionGenerator final : public Generator
    {
    private:
        /**
         * @brief Функция, вызываемая при каждом generate
         */
        std::function<int()> function;

    public:
        /**
         * @brief Создаёт генератор на основе переданной функции.
         * @param function Функция, возвращающая очередное целое число.
         */
        explicit FunctionGenerator(const std::function<int()> function);

        /**
         * @brief Получает очередное значение вызовом сохранённой функции.
         * @return Целое число, возвращённое пользовательской функцией.
         */
        int generate() override;
    };
}
