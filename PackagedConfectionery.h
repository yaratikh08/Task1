#pragma once
#include "ConfectioneryItem.h"

/**
 * @brief Кондитерское изделие, расфасованное в пачки/пакеты
 */
class PackagedConfectionery : public ConfectioneryItem
{
private:
    std::string packageMaterial;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    PackagedConfectionery();

    /**
     * @brief Конструктор с параметрами
     * @param name Название изделия
     * @param category Категория товара
     * @param price Цена пачки
     * @param weightGrams Вес пачки в граммах
     * @param packageMaterial Материал упаковки
     * @param id Идентификатор
     */
    PackagedConfectionery(const std::string &name, const std::string &category,
                          const int price, const int weightGrams,
                          const std::string &packageMaterial, const int id = 0);

    /**
     * @brief Получить материал упаковки
     * @return Константная ссылка на материал
     */
    const std::string &getPackageMaterial() const noexcept;

    /**
     * @brief Получить тип фасовки
     * @return Строка "Пакет/Пачка"
     */
    std::string getPackagingType() const override;

    /**
     * @brief Получить подробную информацию
     * @return Строка с описанием
     */
    std::string getInfo() const override;
};
