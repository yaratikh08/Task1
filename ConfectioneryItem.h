#pragma once
#include <string>

/**
 * @brief Базовый класс Кондитерское изделие
 */
class ConfectioneryItem
{
protected:
    static int nextId;
    int id;
    std::string name;
    std::string category;
    int price;
    int weightGrams;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    ConfectioneryItem();

    /**
     * @brief Конструктор с параметрами
     * @param name Название изделия
     * @param category Вид/категория товара (например, "Конфеты", "Печенье")
     * @param price Цена за единицу фасовки
     * @param weightGrams Вес фасовки в граммах
     * @param id Идентификатор (0 для автогенерации)
     */
    ConfectioneryItem(const std::string &name, const std::string &category,
                      const int price, const int weightGrams, const int id = 0);

    /**
     * @brief Виртуальный деструктор
     */
    virtual ~ConfectioneryItem() = default;

    /**
     * @brief Получить ID изделия
     * @return Уникальный идентификатор
     */
    int getId() const noexcept;

    /**
     * @brief Получить название изделия
     * @return Константная ссылка на название
     */
    const std::string &getName() const noexcept;

    /**
     * @brief Получить категорию товара
     * @return Константная ссылка на категорию
     */
    const std::string &getCategory() const noexcept;

    /**
     * @brief Получить цену изделия
     * @return Цена в рублях
     */
    int getPrice() const noexcept;

    /**
     * @brief Получить вес фасовки
     * @return Вес в граммах
     */
    int getWeightGrams() const noexcept;

    /**
     * @brief Получить тип фасовки для магазинов
     * @return Строка с типом фасовки
     */
    virtual std::string getPackagingType() const;

    /**
     * @brief Получить подробную информацию об изделии
     * @return Строка с описанием
     */
    virtual std::string getInfo() const;
};
