#include "ConfectioneryFactory.h"
#include <algorithm>
#include <stdexcept>

const ConfectioneryItem *ConfectioneryFactory::findItemById(const int itemId) const
{
    for (const BoxedConfectionery &item : boxedItems)
    {
        if (item.getId() == itemId)
        {
            return &item;
        }
    }
    for (const PackagedConfectionery &item : packagedItems)
    {
        if (item.getId() == itemId)
        {
            return &item;
        }
    }
    return nullptr;
}

void ConfectioneryFactory::addBoxedItem(const BoxedConfectionery &item)
{
    if (findItemById(item.getId()) == nullptr)
    {
        boxedItems.push_back(item);
    }
}

void ConfectioneryFactory::addPackagedItem(const PackagedConfectionery &item)
{
    if (findItemById(item.getId()) == nullptr)
    {
        packagedItems.push_back(item);
    }
}

void ConfectioneryFactory::addIngredient(const Ingredient &ingredient)
{
    ingredients.push_back(ingredient);
}

void ConfectioneryFactory::addStoreOrder(const StoreOrder &order)
{
    if (findItemById(order.getItemId()) == nullptr)
    {
        throw std::invalid_argument("Товар с указанным ID не найден на фабрике!");
    }
    storeOrders.push_back(order);
}

void ConfectioneryFactory::addProductionRecord(const ProductionRecord &record)
{
    if (findItemById(record.getItemId()) == nullptr)
    {
        throw std::invalid_argument("Товар с указанным ID не найден на фабрике!");
    }
    productionRecords.push_back(record);
}

std::vector<std::string> ConfectioneryFactory::getStoresOrderingItem(const int itemId) const
{
    std::vector<std::string> stores;
    for (const StoreOrder &order : storeOrders)
    {
        if (order.getItemId() == itemId)
        {
            if (std::find(stores.begin(), stores.end(), order.getStoreName()) == stores.end())
            {
                stores.push_back(order.getStoreName());
            }
        }
    }
    return stores;
}

std::vector<std::string> ConfectioneryFactory::getIngredientsBySupplier(const std::string &supplierName) const
{
    std::vector<std::string> result;
    for (const Ingredient &ing : ingredients)
    {
        if (ing.getSupplierName() == supplierName)
        {
            result.push_back(ing.getInfo());
        }
    }
    return result;
}

std::vector<std::string> ConfectioneryFactory::getAssortmentByCategory(const std::string &category) const
{
    std::vector<std::string> result;
    for (const BoxedConfectionery &item : boxedItems)
    {
        if (item.getCategory() == category)
        {
            result.push_back(item.getInfo());
        }
    }
    for (const PackagedConfectionery &item : packagedItems)
    {
        if (item.getCategory() == category)
        {
            result.push_back(item.getInfo());
        }
    }
    return result;
}

std::string ConfectioneryFactory::getMostPopularItemInCategory(const std::string &category) const
{
    const ConfectioneryItem *bestItem = nullptr;
    int maxOrdered = -1;

    auto evaluate = [&](const ConfectioneryItem &item)
    {
        if (item.getCategory() != category)
        {
            return;
        }
        int totalOrdered = 0;
        for (const StoreOrder &order : storeOrders)
        {
            if (order.getItemId() == item.getId())
            {
                totalOrdered += order.getQuantity();
            }
        }
        if (totalOrdered > maxOrdered)
        {
            maxOrdered = totalOrdered;
            bestItem = &item;
        }
    };

    for (const BoxedConfectionery &item : boxedItems)
    {
        evaluate(item);
    }
    for (const PackagedConfectionery &item : packagedItems)
    {
        evaluate(item);
    }

    if (bestItem == nullptr)
    {
        return "Товары данной категории не найдены";
    }
    return bestItem->getName() + " (заказано: " + std::to_string(maxOrdered) + " ед., цена: " +
           std::to_string(bestItem->getPrice()) + " руб.)";
}

int ConfectioneryFactory::getProducedValueInPeriod(const std::string &startDate, const std::string &endDate) const
{
    int totalValue = 0;
    for (const ProductionRecord &rec : productionRecords)
    {
        if (rec.getDate() >= startDate && rec.getDate() <= endDate)
        {
            const ConfectioneryItem *item = findItemById(rec.getItemId());
            if (item != nullptr)
            {
                totalValue += rec.getQuantity() * item->getPrice();
            }
        }
    }
    return totalValue;
}
