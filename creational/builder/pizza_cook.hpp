
#ifndef CREATIONAL_PIZZA_COOK_HPP
#define CREATIONAL_PIZZA_COOK_HPP

#include "pizza_builder.hpp"

// PizzaBuilderDirector
class PizzaCook{
	public:
	Pizza CookMargherita(Pizza::Size size, Pizza::Dough dough);
	Pizza CookDiavola(Pizza::Size size, Pizza::Dough dough);
	Pizza CookNapoli(Pizza::Size size, Pizza::Dough dough);
	Pizza CookVeggie(Pizza::Size size, Pizza::Dough dough);
};

#endif // CREATIONAL_PIZZA_COOK_HPP
