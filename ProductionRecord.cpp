#include "ProductionRecord.h"
#include <stdexcept>

ProductionRecord::ProductionRecord(const int itemId, const int quantity, const std::string &date)
    : itemId(itemId), quantity(quantity), date(date)
{
    if (quantity <= 0)
    {
        throw std::invalid_argument("Количество произведенного товара должно быть больше нуля!");
    }
}

int ProductionRecord::getItemId() const noexcept
{
    return itemId;
}

int ProductionRecord::getQuantity() const noexcept
{
    return quantity;
}

const std::string &ProductionRecord::getDate() const noexcept
{
    return date;
}
