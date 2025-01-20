
#include <gtest/gtest.h>
#include "pizza_base.hpp"
#include "cheese_pizza.hpp"
#include "tomato_sauce_pizza.hpp"
#include "salami_pizza.hpp"

TEST(DecoratorTest, ExpectPizzasToHaveCorrectPricesAfterUsingTheDecoratorPattern){
	std::unique_ptr<Pizza> pizza = std::make_unique<PizzaBase>(); // 20
	pizza = std::make_unique<TomatoSaucePizza>(std::move(pizza)); // +10
	pizza = std::make_unique<CheesePizza>(std::move(pizza)); // +4
	pizza = std::make_unique<SalamiPizza>(std::move(pizza)); // +6
	EXPECT_EQ(40, pizza->GetPrice());
	
	std::unique_ptr<Pizza> double_cheese = std::make_unique<PizzaBase>(); // 20
	double_cheese = std::make_unique<TomatoSaucePizza>(std::move(double_cheese)); // +10
	double_cheese = std::make_unique<CheesePizza>(std::move(double_cheese)); // +4
	double_cheese = std::make_unique<CheesePizza>(std::move(double_cheese)); // +4
	double_cheese = std::make_unique<SalamiPizza>(std::move(double_cheese)); // +6
	EXPECT_EQ(44, double_cheese->GetPrice());
	
	std::unique_ptr<Pizza> double_cheese_double_salami = std::make_unique<PizzaBase>(); // 20
	double_cheese_double_salami = std::make_unique<TomatoSaucePizza>(std::move(double_cheese_double_salami)); // +10
	double_cheese_double_salami = std::make_unique<CheesePizza>(std::move(double_cheese_double_salami)); // +4
	double_cheese_double_salami = std::make_unique<CheesePizza>(std::move(double_cheese_double_salami)); // +4
	double_cheese_double_salami = std::make_unique<SalamiPizza>(std::move(double_cheese_double_salami)); // +6
	double_cheese_double_salami = std::make_unique<SalamiPizza>(std::move(double_cheese_double_salami)); // +6
	EXPECT_EQ(50, double_cheese_double_salami->GetPrice());
}
