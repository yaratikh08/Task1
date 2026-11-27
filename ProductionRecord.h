#pragma once
#include <string>

/**
 * @brief Класс Запись о произведенной партии товара
 */
class ProductionRecord
{
private:
    int itemId;
    int quantity;
    std::string date;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    ProductionRecord() = default;

    /**
     * @brief Конструктор с параметрами
     * @param itemId ID произведенного изделия
     * @param quantity Количество произведенных единиц
     * @param date Дата производства (YYYY-MM-DD)
     */
    ProductionRecord(const int itemId, const int quantity, const std::string &date);

    /**
     * @brief Получить ID изделия
     * @return Идентификатор изделия
     */
    int getItemId() const noexcept;

    /**
     * @brief Получить количество произведенного товара
     * @return Количество единиц
     */
    int getQuantity() const noexcept;

    /**
     * @brief Получить дату производства
     * @return Константная ссылка на дату
     */
    const std::string &getDate() const noexcept;
};
