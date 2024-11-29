
#ifndef CREATIONAL_PIZZA_COOK_HPP
#define CREATIONAL_PIZZA_COOK_HPP

#include "pizza_builder.hpp"

class PizzaCook{
	public:
	PizzaCook(std::unique_ptr<PizzaBuilder>&& builder);
	
	void SetBuilder(std::unique_ptr<PizzaBuilder>&& builder);
	
	std::unique_ptr<Pizza> MakePizza(Pizza::Size size, Pizza::Dough dough);
	std::unique_ptr<Pizza> MakeDoubleCheesePizza(Pizza::Size size, Pizza::Dough dough);
	std::unique_ptr<Pizza> MakeDoubleToppingsPizza(Pizza::Size size, Pizza::Dough dough);
	
	private:
	std::unique_ptr<PizzaBuilder> builder_;
};

#endif // CREATIONAL_PIZZA_COOK_HPP
