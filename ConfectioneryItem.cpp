#include "ConfectioneryItem.h"

int ConfectioneryItem::nextId = 1;

ConfectioneryItem::ConfectioneryItem()
    : id(nextId++), name(""), category(""), price(0), weightGrams(0) {}

ConfectioneryItem::ConfectioneryItem(const std::string &name, const std::string &category,
                                     const int price, const int weightGrams, const int id)
    : id(id > 0 ? id : nextId++),
      name(name),
      category(category),
      price(price),
      weightGrams(weightGrams)
{
    if (this->id >= nextId)
    {
        nextId = this->id + 1;
    }
}

int ConfectioneryItem::getId() const noexcept
{
    return id;
}

const std::string &ConfectioneryItem::getName() const noexcept
{
    return name;
}

const std::string &ConfectioneryItem::getCategory() const noexcept
{
    return category;
}

int ConfectioneryItem::getPrice() const noexcept
{
    return price;
}

int ConfectioneryItem::getWeightGrams() const noexcept
{
    return weightGrams;
}

std::string ConfectioneryItem::getPackagingType() const
{
    return "Стандартная";
}

std::string ConfectioneryItem::getInfo() const
{
    return "ID: " + std::to_string(id) +
           " | Изделие: " + name +
           " | Категория: " + category +
           " | Фасовка: " + getPackagingType() + " (" + std::to_string(weightGrams) + " г)" +
           " | Цена: " + std::to_string(price) + " руб.";
}
