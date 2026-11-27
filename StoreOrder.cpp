#include "StoreOrder.h"
#include <stdexcept>

StoreOrder::StoreOrder(const std::string &storeName, const int itemId, const int quantity, const std::string &date)
    : storeName(storeName), itemId(itemId), quantity(quantity), date(date)
{
    if (quantity <= 0)
    {
        throw std::invalid_argument("Количество товара в заказе должно быть больше нуля!");
    }
}

const std::string &StoreOrder::getStoreName() const noexcept
{
    return storeName;
}

int StoreOrder::getItemId() const noexcept
{
    return itemId;
}

int StoreOrder::getQuantity() const noexcept
{
    return quantity;
}

const std::string &StoreOrder::getDate() const noexcept
{
    return date;
}
