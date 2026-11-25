#include "Ingredient.h"

int Ingredient::nextId = 1;

Ingredient::Ingredient() : id(nextId++), name(""), supplierName(""), unitPrice(0) {}

Ingredient::Ingredient(const std::string &name, const std::string &supplierName, const int unitPrice, const int id)
    : id(id > 0 ? id : nextId++), name(name), supplierName(supplierName), unitPrice(unitPrice)
{
    if (this->id >= nextId)
    {
        nextId = this->id + 1;
    }
}

int Ingredient::getId() const noexcept
{
    return id;
}

const std::string &Ingredient::getName() const noexcept
{
    return name;
}

const std::string &Ingredient::getSupplierName() const noexcept
{
    return supplierName;
}

int Ingredient::getUnitPrice() const noexcept
{
    return unitPrice;
}

std::string Ingredient::getInfo() const
{
    return "Продукт: " + name + " | Поставщик: " + supplierName + " | Цена: " + std::to_string(unitPrice) + " руб.";
}
