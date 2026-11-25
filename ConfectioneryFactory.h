#pragma once
#include "BoxedConfectionery.h"
#include "PackagedConfectionery.h"
#include "Ingredient.h"
#include "StoreOrder.h"
#include "ProductionRecord.h"
#include <vector>
#include <string>

/**
 * @brief Класс Кондитерская фабрика
 */
class ConfectioneryFactory
{
private:
    std::vector<BoxedConfectionery> boxedItems;
    std::vector<PackagedConfectionery> packagedItems;
    std::vector<Ingredient> ingredients;
    std::vector<StoreOrder> storeOrders;
    std::vector<ProductionRecord> productionRecords;

    /**
     * @brief Поиск изделия по ID
     * @param itemId Идентификатор изделия
     * @return Указатель на базовый класс или nullptr
     */
    const ConfectioneryItem *findItemById(const int itemId) const;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    ConfectioneryFactory() = default;

    /**
     * @brief Деструктор
     */
    ~ConfectioneryFactory() = default;

    /**
     * @brief Добавить изделие в коробке в каталог
     * @param item Объект BoxedConfectionery
     */
    void addBoxedItem(const BoxedConfectionery &item);

    /**
     * @brief Добавить изделие в пачке в каталог
     * @param item Объект PackagedConfectionery
     */
    void addPackagedItem(const PackagedConfectionery &item);

    /**
     * @brief Добавить продукт (сырье), заказываемый у поставщика
     * @param ingredient Объект Ingredient
     */
    void addIngredient(const Ingredient &ingredient);

    /**
     * @brief Зарегистрировать заказ от магазина
     * @param order Объект StoreOrder
     */
    void addStoreOrder(const StoreOrder &order);

    /**
     * @brief Зарегистрировать выпуск партии товара
     * @param record Объект ProductionRecord
     */
    void addProductionRecord(const ProductionRecord &record);

    /**
     * @brief Задание 1: Показать список магазинов, заказывающих данный товар
     * @param itemId Идентификатор товара
     * @return Вектор уникальных названий магазинов
     */
    std::vector<std::string> getStoresOrderingItem(const int itemId) const;

    /**
     * @brief Задание 2: Показать список продуктов, заказываемых у данного поставщика
     * @param supplierName Название поставщика
     * @return Вектор строк с описанием продуктов
     */
    std::vector<std::string> getIngredientsBySupplier(const std::string &supplierName) const;

    /**
     * @brief Задание 3: Показать ассортимент данного товара (категории) и цену
     * @param category Категория товара (например, "Конфеты")
     * @return Вектор строк с ассортиментом и ценами
     */
    std::vector<std::string> getAssortmentByCategory(const std::string &category) const;

    /**
     * @brief Задание 4: Выбрать наиболее популярный вид данного товара (по объему заказов)
     * @param category Категория товара
     * @return Строка с информацией о самом популярном изделии
     */
    std::string getMostPopularItemInCategory(const std::string &category) const;

    /**
     * @brief Задание 5: Показать стоимость произведенного товара за отчетный период времени
     * @param startDate Начальная дата периода (YYYY-MM-DD)
     * @param endDate Конечная дата периода (YYYY-MM-DD)
     * @return Общая стоимость произведенного товара в рублях
     */
    int getProducedValueInPeriod(const std::string &startDate, const std::string &endDate) const;
};
