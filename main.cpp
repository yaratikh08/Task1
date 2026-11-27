#include <iostream>
#include "ConfectioneryFactory.h"

/**
 * @brief Точка входа в программу
 * @return 0 при успешном завершении
 */
int main()
{
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    ConfectioneryFactory factory;

    BoxedConfectionery candies1("Птичье молоко", "Конфеты", 350, 300, 20);
    BoxedConfectionery candies2("Ассорти Классик", "Конфеты", 420, 400, 24);
    PackagedConfectionery cookies1("Овсяное с изюмом", "Печенье", 120, 350, "Пленка");
    PackagedConfectionery cookies2("Шоколадное", "Печенье", 150, 300, "Крафт-пакет");

    factory.addBoxedItem(candies1);
    factory.addBoxedItem(candies2);
    factory.addPackagedItem(cookies1);
    factory.addPackagedItem(cookies2);

    factory.addIngredient(Ingredient("Какао-бобы", "ООО АгроПоставка", 600));
    factory.addIngredient(Ingredient("Сахар-песок", "ООО АгроПоставка", 75));
    factory.addIngredient(Ingredient("Мука пшеничная", "Мелькомбинат №1", 55));

    factory.addStoreOrder(StoreOrder("Магазин Сладкоежка", candies1.getId(), 50, "2026-11-02"));
    factory.addStoreOrder(StoreOrder("Супермаркет Центральный", candies1.getId(), 80, "2026-11-04"));
    factory.addStoreOrder(StoreOrder("Магазин Сладкоежка", candies2.getId(), 40, "2026-11-05"));
    factory.addStoreOrder(StoreOrder("Супермаркет Центральный", cookies1.getId(), 100, "2026-11-03"));

    factory.addProductionRecord(ProductionRecord(candies1.getId(), 100, "2026-11-01"));
    factory.addProductionRecord(ProductionRecord(cookies1.getId(), 200, "2026-11-03"));
    factory.addProductionRecord(ProductionRecord(candies2.getId(), 50, "2026-11-20"));

    std::cout << "=== 1. МАГАЗИНЫ, ЗАКАЗЫВАЮЩИЕ 'Птичье молоко' ===" << std::endl;
    for (const std::string &store : factory.getStoresOrderingItem(candies1.getId()))
    {
        std::cout << "- " << store << std::endl;
    }

    std::cout << "\n=== 2. ПРОДУКТЫ ОТ ПОСТАВЩИКА 'ООО АгроПоставка' ===" << std::endl;
    for (const std::string &ing : factory.getIngredientsBySupplier("ООО АгроПоставка"))
    {
        std::cout << "- " << ing << std::endl;
    }

    std::cout << "\n=== 3. АССОРТИМЕНТ КАТЕГОРИИ 'Конфеты' И ЦЕНА ===" << std::endl;
    for (const std::string &info : factory.getAssortmentByCategory("Конфеты"))
    {
        std::cout << info << std::endl;
    }

    std::cout << "\n=== 4. НАИБОЛЕЕ ПОПУЛЯРНЫЙ ВИД КАТЕГОРИИ 'Конфеты' ===" << std::endl;
    std::cout << factory.getMostPopularItemInCategory("Конфеты") << std::endl;

    std::cout << "\n=== 5. СТОИМОСТЬ ПРОИЗВЕДЕННОГО ТОВАРА (2026-11-01 .. 2026-11-10) ===" << std::endl;
    std::cout << factory.getProducedValueInPeriod("2026-11-01", "2026-11-10") << " руб." << std::endl;


    std::cout << "\n=== ИНФОРМАЦИЯ О КОРОБОЧНЫХ ИЗДЕЛИЯХ ===" << std::endl;
    std::cout << candies1.getInfo() << std::endl;
    std::cout << candies2.getInfo() << std::endl;

    std::cout << "\n=== ИНФОРМАЦИЯ О ПАКЕТИРОВАННЫХ ИЗДЕЛИЯХ ===" << std::endl;
    std::cout << cookies1.getInfo() << std::endl;
    std::cout << cookies2.getInfo() << std::endl;
    
    return 0;
}
