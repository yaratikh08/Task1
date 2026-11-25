#pragma once
#include <string>

/**
 * @brief Класс Заказ магазина на кондитерское изделие
 */
class StoreOrder
{
private:
    std::string storeName;
    int itemId;
    int quantity;
    std::string date;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    StoreOrder() = default;

    /**
     * @brief Конструктор с параметрами
     * @param storeName Название магазина
     * @param itemId ID заказываемого изделия
     * @param quantity Количество единиц фасовки
     * @param date Дата заказа (YYYY-MM-DD)
     */
    StoreOrder(const std::string &storeName, const int itemId, const int quantity, const std::string &date);

    /**
     * @brief Получить название магазина
     * @return Константная ссылка на название магазина
     */
    const std::string &getStoreName() const noexcept;

    /**
     * @brief Получить ID изделия
     * @return Идентификатор изделия
     */
    int getItemId() const noexcept;

    /**
     * @brief Получить заказанное количество
     * @return Количество единиц
     */
    int getQuantity() const noexcept;

    /**
     * @brief Получить дату заказа
     * @return Константная ссылка на дату
     */
    const std::string &getDate() const noexcept;
};
