
#ifndef CREATIONAL_PIZZA_BUILDER_HPP
#define CREATIONAL_PIZZA_BUILDER_HPP

#include "pizza.hpp"

class PizzaBuilder{
	public:
	Pizza build() const{
		return Pizza(size_, dough_, sauce_, cheeses_, toppings_, is_gluten_free_, is_vegan_);
	}
	
	PizzaBuilder& SetSize(Pizza::Size size){
		size_ = size;
		return *this;
	}
	PizzaBuilder& SetDough(Pizza::Dough dough){
		dough_ = dough;
		return *this;
	}
	PizzaBuilder& SetSauce(Pizza::Sauce sauce){
		sauce_ = sauce;
		return *this;
	}
	PizzaBuilder& AddCheese(Pizza::Cheese cheese){
		cheeses_.push_back(cheese);
		return *this;
	}
	PizzaBuilder& AddTopping(Pizza::Topping topping){
		toppings_.push_back(topping);
		return *this;
	}
	PizzaBuilder& SetIsGlutenFree(bool is_gluten_free){
		is_gluten_free_ = is_gluten_free;
		return *this;
	}
	PizzaBuilder& SetIsVegan(bool is_vegan){
		is_vegan_ = is_vegan;
		return *this;
	}
	
	private:
	Pizza::Size size_{};
	Pizza::Dough dough_{};
	Pizza::Sauce sauce_{};
	std::vector<Pizza::Cheese> cheeses_{};
	std::vector<Pizza::Topping> toppings_{};
	bool is_gluten_free_{};
	bool is_vegan_{};
};


#endif // CREATIONAL_PIZZA_BUILDER_HPP
