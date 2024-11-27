
#include <gtest/gtest.h>
#include <algorithm>
#include "creational/builder/pizza_cook.hpp"
#include "creational/builder/margherita_builder.hpp"
#include "creational/builder/diavola_builder.hpp"

TEST(TestPizza, ExpectMargheritaIngredientsInMargherita){
	std::unique_ptr<MargheritaBuilder> builder = std::make_unique<MargheritaBuilder>();
	PizzaCook pc(std::move(builder));
	std::unique_ptr<Pizza> margherita = pc.build(Pizza::Size::Large, Pizza::Dough::Thin);
	
	EXPECT_EQ(margherita->GetSauce(), Pizza::Sauce::Tomato);
	EXPECT_EQ(margherita->GetCheeses().at(0), Pizza::Cheese::Mozzarella);
	EXPECT_EQ(margherita->GetToppings().at(0), Pizza::Topping::Basil);
	EXPECT_EQ(margherita->GetToppings().at(1), Pizza::Topping::OliveOil);
}

TEST(TestPizza, ExpectDiavolaIngredientsInDiavola){
	std::unique_ptr<DiavolaBuilder> builder = std::make_unique<DiavolaBuilder>();
	PizzaCook pc(std::move(builder));
	std::unique_ptr<Pizza> margherita = pc.build(Pizza::Size::Large, Pizza::Dough::Thin);
	
	EXPECT_EQ(margherita->GetSauce(), Pizza::Sauce::Tomato);
	EXPECT_EQ(margherita->GetCheeses().at(0), Pizza::Cheese::Mozzarella);
	EXPECT_EQ(margherita->GetToppings().at(0), Pizza::Topping::SpicySalami);
	EXPECT_EQ(margherita->GetToppings().at(1), Pizza::Topping::RedChiliFlakes);
	EXPECT_EQ(margherita->GetToppings().at(2), Pizza::Topping::BlackOlives);
}
