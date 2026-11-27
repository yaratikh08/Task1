#include <gtest/gtest.h>
#include "ConfectioneryFactory.h"
#include <typeinfo>

TEST(ConfectioneryItemTest, PolymorphismAndInfo)
{
    BoxedConfectionery box("Трюфель", "Конфеты", 400, 250, 15, 10);
    PackagedConfectionery pack("Юбилейное", "Печенье", 100, 200, "Фольга", 11);

    const ConfectioneryItem &bRef = box;
    const ConfectioneryItem &pRef = pack;

    EXPECT_EQ(bRef.getPackagingType(), "Коробка");
    EXPECT_EQ(pRef.getPackagingType(), "Пакет/Пачка");
    EXPECT_NO_THROW((void)dynamic_cast<const BoxedConfectionery &>(bRef));
    EXPECT_THROW((void)dynamic_cast<const BoxedConfectionery &>(pRef), std::bad_cast);
}

TEST(ConfectioneryFactoryTest, AllFiveAssignmentsWorkCorrectly)
{
    ConfectioneryFactory factory;
    BoxedConfectionery c1("Птичье молоко", "Конфеты", 300, 300, 20, 100);
    BoxedConfectionery c2("Мишка на севере", "Конфеты", 450, 400, 25, 101);
    factory.addBoxedItem(c1);
    factory.addBoxedItem(c2);

    factory.addIngredient(Ingredient("Сахар", "Поставщик А", 70));
    factory.addIngredient(Ingredient("Масло", "Поставщик А", 500));
    factory.addIngredient(Ingredient("Мука", "Поставщик Б", 50));

    factory.addStoreOrder(StoreOrder("Магазин 1", 100, 20, "2026-11-02"));
    factory.addStoreOrder(StoreOrder("Магазин 2", 100, 50, "2026-11-03"));
    factory.addStoreOrder(StoreOrder("Магазин 1", 101, 30, "2026-11-04"));

    factory.addProductionRecord(ProductionRecord(100, 10, "2026-11-01"));
    factory.addProductionRecord(ProductionRecord(101, 20, "2026-11-05"));
    factory.addProductionRecord(ProductionRecord(100, 50, "2026-11-25"));

    auto stores = factory.getStoresOrderingItem(100);
    ASSERT_EQ(stores.size(), 2u);
    EXPECT_EQ(stores[0], "Магазин 1");
    EXPECT_EQ(stores[1], "Магазин 2");

    auto ings = factory.getIngredientsBySupplier("Поставщик А");
    ASSERT_EQ(ings.size(), 2u);

    auto assortment = factory.getAssortmentByCategory("Конфеты");
    ASSERT_EQ(assortment.size(), 2u);

    std::string popular = factory.getMostPopularItemInCategory("Конфеты");
    EXPECT_NE(popular.find("Птичье молоко"), std::string::npos);
    EXPECT_NE(popular.find("70 ед."), std::string::npos);

    EXPECT_EQ(factory.getProducedValueInPeriod("2026-11-01", "2026-11-10"), 10 * 300 + 20 * 450);
}
