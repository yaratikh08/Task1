#include "BoxedConfectionery.h"

BoxedConfectionery::BoxedConfectionery() : ConfectioneryItem(), itemsPerBox(0) {}

BoxedConfectionery::BoxedConfectionery(const std::string &name, const std::string &category,
                                       const int price, const int weightGrams, const int itemsPerBox, const int id)
    : ConfectioneryItem(name, category, price, weightGrams, id), itemsPerBox(itemsPerBox) {}

int BoxedConfectionery::getItemsPerBox() const noexcept
{
    return itemsPerBox;
}

std::string BoxedConfectionery::getPackagingType() const
{
    return "Коробка";
}

std::string BoxedConfectionery::getInfo() const
{
    return ConfectioneryItem::getInfo() + " | Штук в коробке: " + std::to_string(itemsPerBox);
}
