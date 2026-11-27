#include "ConfectioneryFactory.h"
#include <algorithm>
#include <stdexcept>

void ConfectioneryFactory::addBoxedItem(const BoxedConfectionery &item)
{
    for (const BoxedConfectionery &existing : boxedItems)//коробочные
    {
        if (existing.getId() == item.getId())
        {
            return;
        }
    }
    for (const PackagedConfectionery &existing : packagedItems)//пакетированные
    {
        if (existing.getId() == item.getId())
        {
            return;
        }
    }
    boxedItems.push_back(item);
}

void ConfectioneryFactory::addPackagedItem(const PackagedConfectionery &item)
{
    for (const BoxedConfectionery &existing : boxedItems)//коробочные
    {
        if (existing.getId() == item.getId())
        {
            return;
        }
    }
    for (const PackagedConfectionery &existing : packagedItems)//пакетированные
    {
        if (existing.getId() == item.getId())
        {
            return;
        }
    }
    packageddItems.push_back(item);
}

void ConfectioneryFactory::addIngredient(const Ingredient &ingredient)
{
    ingredients.push_back(ingredient);
}

void ConfectioneryFactory::addStoreOrder(const StoreOrder &order)
{
    bool itemExists = false;

for (const BoxedConfectionery &item : boxedItems)
{
    if (item.getId() == order.getItemId())
    {
        itemExists = true;
        break;
       
}
    if (!itemExists)
    {
        for (const PackagedConfectionery &item : packagedItems)
        {
            if (item.getId() == order.getItemId())
            {
                itemExists = true;
                break;
            }
        }
    }

    if (!itemExists)
    {
        throw std::invalid_argument("Товар с указанным ID не найден на фабрике!");
    }

    storeOrders.push_back(order);
}

void ConfectioneryFactory::addProductionRecord(const ProductionRecord &record)
{
       bool itemExists = false;

    for (const BoxedConfectionery &item : boxedItems)
    {
        if (item.getId() == record.getItemId())
        {
            itemExists = true;
            break;
        }
    }

    if (!itemExists)
    {
        for (const PackagedConfectionery &item : packagedItems)
        {
            if (item.getId() == record.getItemId())
            {
                itemExists = true;
                break;
            }
        }
    }

    if (!itemExists)
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
    std::string bestItemName;
    int bestItemPrice = 0;
    int maxOrdered = -1;

    for (const BoxedConfectionery &item : boxedItems)
    {
        if (item.getCategory() == category)
        {
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
                bestItemName = item.getName();
                bestItemPrice = item.getPrice();
            }
        }
    }
    for (const PackagedConfectionery &item : packagedItems)
    {
        if (item.getCategory() == category)
        {
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
                bestItemName = item.getName();
                bestItemPrice = item.getPrice();
            }
        }
    }   
    if (maxOrdered == -1)
    {
        return "Товары данной категории не найдены";
    }

    return bestItemName + " (заказано: " + std::to_string(maxOrdered) + " ед., цена: " +
           std::to_string(bestItemPrice) + " руб.)";
}
    
int ConfectioneryFactory::getProducedValueInPeriod(const std::string &startDate, const std::string &endDate) const
{
    int totalValue = 0;
    for (const ProductionRecord &rec : productionRecords)
        {
        if (rec.getDate() >= startDate && rec.getDate() <= endDate)
        {
            bool itemFound = false;

            for (const BoxedConfectionery &item : boxedItems)
            {
                if (item.getId() == rec.getItemId())
                {
                    totalValue += rec.getQuantity() * item.getPrice();
                    itemFound = true;
                    break;
                }
            }

  
            if (!itemFound)
            {
                for (const PackagedConfectionery &item : packagedItems)
                {
                    if (item.getId() == rec.getItemId())
                    {
                        totalValue += rec.getQuantity() * item.getPrice();
                        break;
                    }
                }
            }
        }
    }
    return totalValue;
}
