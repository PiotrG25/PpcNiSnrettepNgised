
#include <gtest/gtest.h>
#include "creational/builder/pizza_cook.hpp"

TEST(TestPizza, ExpectMargheritaWithTomatoSauce){
	PizzaCook pc;
	Pizza margherita = pc.CookMargherita(Pizza::Size::Medium, Pizza::Dough::Fluffy);
	EXPECT_EQ(margherita.GetSauce(), Pizza::Sauce::Tomato);
}

TEST(TestPizza, ExpectMargheritaWithGlutenAndNotVegan){
	PizzaCook pc;
	Pizza margherita = pc.CookMargherita(Pizza::Size::Medium, Pizza::Dough::Fluffy);
	EXPECT_EQ(margherita.IsGlutenFree(), false);
	EXPECT_EQ(margherita.IsVegan(), false);
}

TEST(TestPizza, ExpectDiavolaToBeSpicy){
	PizzaCook pc;
	Pizza diavola = pc.CookDiavola(Pizza::Size::Medium, Pizza::Dough::Fluffy);
	const auto& toppings = diavola.GetToppings();
	
	auto toppings_iterator = find(toppings.cbegin(), toppings.cend(), Pizza::Topping::SpicySalami);
	EXPECT_NE(toppings_iterator, toppings.cend());
}

TEST(TestPizza, ExpectVeggieGlutenFreeAndVegan){
	PizzaCook pc;
	Pizza veggie = pc.CookVeggie(Pizza::Size::Medium, Pizza::Dough::Fluffy);
	EXPECT_EQ(veggie.IsGlutenFree(), true);
	EXPECT_EQ(veggie.IsVegan(), true);
}
