
#include <gtest/gtest.h>
#include <iostream>
#include "menu.hpp"
#include "heavyweight_pizza.hpp"

namespace {
	void CheckPizzaType(const Pizza& pizza, const PizzaType& pizza_type){
		EXPECT_EQ(pizza_type.GetSize(), pizza.GetPizzaType()->GetSize());
		EXPECT_EQ(pizza_type.GetCheese(), pizza.GetPizzaType()->GetCheese());
		EXPECT_EQ(pizza_type.GetToppings().at(0), pizza.GetPizzaType()->GetToppings().at(0));
		EXPECT_EQ(pizza_type.GetToppings().at(1), pizza.GetPizzaType()->GetToppings().at(1));
	}
	constexpr std::size_t PIZZA_ID = 0;
	constexpr std::size_t TOTAL_PIZZAS = 10;
	constexpr std::size_t APPROXMATE_SIZE_OF_SHARED_PTR_CONTROL_BLOCK = 32;
}

TEST(TestFlyweight, ExpectCorrectValuesFromPizzaFlyweight){
	Menu menu;
	
	Pizza pizza1 = menu.OrderPizza(PIZZA_ID, 1);
	Pizza pizza2 = menu.OrderPizza(PIZZA_ID, 2);
	Pizza pizza3 = menu.OrderPizza(PIZZA_ID, 3);
	
	EXPECT_EQ(1, pizza1.GetTableNumber());
	CheckPizzaType(pizza1, menu.GetPizzaType(PIZZA_ID));
	
	EXPECT_EQ(2, pizza2.GetTableNumber());
	CheckPizzaType(pizza2, menu.GetPizzaType(PIZZA_ID));
	
	EXPECT_EQ(3, pizza3.GetTableNumber());
	CheckPizzaType(pizza3, menu.GetPizzaType(PIZZA_ID));
}

TEST(TestFlyweight, ExpectFlyweightMemoryUsageToBelowerThanHeavyweight){
	Menu menu;
	
	std::vector<Pizza> light_pizzas;
	light_pizzas.reserve(TOTAL_PIZZAS);
	for(std::size_t i = 0; i < TOTAL_PIZZAS; ++i){
		light_pizzas.push_back(menu.OrderPizza(PIZZA_ID, i));
	}
	
	std::vector<HeavyweightPizza> heavy_pizzas;
	heavy_pizzas.reserve(TOTAL_PIZZAS);
	for(std::size_t i = 0; i < TOTAL_PIZZAS; ++i){
		heavy_pizzas.push_back(HeavyweightPizza(enums::Size::Large, enums::Cheese::Mozzarella, i));
		heavy_pizzas.at(i).AddTopping(enums::Topping::SpicySalami);
		heavy_pizzas.at(i).AddTopping(enums::Topping::Jalapenos);
	}
	
	std::size_t flyweight_size = 0;
	flyweight_size += APPROXMATE_SIZE_OF_SHARED_PTR_CONTROL_BLOCK; // 32
	flyweight_size += 16; // sizeof(shared_ptr<PizzaType>) == 16, 2 pointers to object and control block on 64bit processor
	flyweight_size += sizeof(menu.GetPizzaType(PIZZA_ID)); // sizeof(PizzaType) == 32, 24 (vector) + 4 (Size) + 4 (Cheese)
	flyweight_size += menu.GetPizzaType(PIZZA_ID).GetToppings().size() * sizeof(enums::Topping); // 8 = 2 * 4, might be more if vector reserves more storage
	
	// Pizza class hase sizeof = 24 with alignment to 8 bytes => 16: shared_ptr + 4: int + 4: padding
	flyweight_size += light_pizzas.size() * sizeof(Pizza); // 240 = 10 * (16 + 4 + 4)
	std::cout << flyweight_size << std::endl; // flyweight_size == 328
	
	std::size_t heavyweight_size = 0;
	// Heavyweight class has sizeof = 40 with alignment to 8 bytes => 24: vector, 4: Size, 4: Cheese, 4: int, 4: padding
	heavyweight_size += heavy_pizzas.size() * sizeof(HeavyweightPizza); // 400 =  10 * 40
	// 80 = 10 * 2 * 4 = 10 pizzas, each with 2 toppings of byte size 4, might be more if vector reserves more storage
	heavyweight_size += heavy_pizzas.size() * heavy_pizzas.at(0).GetToppings().size() * sizeof(enums::Topping);
	std::cout << heavyweight_size << std::endl; // heavyweight_size == 480
	
	EXPECT_TRUE(flyweight_size < heavyweight_size);
}
