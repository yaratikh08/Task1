#pragma once
#include <string>

/**
 * @brief Класс Продукт (сырье), заказываемый фабрикой у поставщика
 */
class Ingredient
{
private:
    static int nextId;
    int id;
    std::string name;
    std::string supplierName;
    int unitPrice;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Ingredient();

    /**
     * @brief Конструктор с параметрами
     * @param name Название продукта
     * @param supplierName Название поставщика
     * @param unitPrice Цена за единицу (кг/л)
     * @param id Идентификатор
     */
    Ingredient(const std::string &name, const std::string &supplierName, const int unitPrice, const int id = 0);

    /**
     * @brief Получить ID продукта
     * @return Уникальный идентификатор
     */
    int getId() const noexcept;

    /**
     * @brief Получить название продукта
     * @return Константная ссылка на название
     */
    const std::string &getName() const noexcept;

    /**
     * @brief Получить название поставщика
     * @return Константная ссылка на поставщика
     */
    const std::string &getSupplierName() const noexcept;

    /**
     * @brief Получить цену за единицу сырья
     * @return Цена в рублях
     */
    int getUnitPrice() const noexcept;

    /**
     * @brief Получить информацию о продукте
     * @return Строка с описанием
     */
    std::string getInfo() const;
};
