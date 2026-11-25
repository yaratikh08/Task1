#pragma once
#include "ConfectioneryItem.h"

/**
 * @brief Кондитерское изделие, расфасованное в коробки
 */
class BoxedConfectionery : public ConfectioneryItem
{
private:
    int itemsPerBox;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    BoxedConfectionery();

    /**
     * @brief Конструктор с параметрами
     * @param name Название изделия
     * @param category Категория товара
     * @param price Цена коробки
     * @param weightGrams Вес коробки в граммах
     * @param itemsPerBox Количество штук в коробке
     * @param id Идентификатор
     */
    BoxedConfectionery(const std::string &name, const std::string &category,
                       const int price, const int weightGrams, const int itemsPerBox, const int id = 0);

    /**
     * @brief Получить количество штук в коробке
     * @return Количество штук
     */
    int getItemsPerBox() const noexcept;

    /**
     * @brief Получить тип фасовки
     * @return Строка "Коробка"
     */
    std::string getPackagingType() const override;

    /**
     * @brief Получить подробную информацию
     * @return Строка с описанием
     */
    std::string getInfo() const override;
};
