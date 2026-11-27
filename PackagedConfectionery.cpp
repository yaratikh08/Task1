#include "PackagedConfectionery.h"

PackagedConfectionery::PackagedConfectionery() : ConfectioneryItem(), packageMaterial("") {}

PackagedConfectionery::PackagedConfectionery(const std::string &name, const std::string &category,
                                             const int price, const int weightGrams,
                                             const std::string &packageMaterial, const int id)
    : ConfectioneryItem(name, category, price, weightGrams, id), packageMaterial(packageMaterial) {}

const std::string &PackagedConfectionery::getPackageMaterial() const noexcept
{
    return packageMaterial;
}

std::string PackagedConfectionery::getPackagingType() const
{
    return "Пакет/Пачка";
}

std::string PackagedConfectionery::getInfo() const
{
    return ConfectioneryItem::getInfo() + " | Материал: " + packageMaterial;
}
