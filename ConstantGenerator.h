#pragma once

#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief Генератор, возвращающий одно постоянное значение.
     */
    class ConstantGenerator final : public Generator
    {
    private:
        /**
         * @brief Хранимое постоянное значение
         */
        const int value;

    public:
        /**
         * @brief Создаёт генератор постоянного значения.
         * @param value - значение, которое будет возвращаться
         */
        explicit ConstantGenerator(const int value);

        /**
         * @brief Возвращает постоянное значение.
         * @return сохраненное значение генератора
         */
        int generate() override;
    };
}
