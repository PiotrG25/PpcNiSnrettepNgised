
#ifndef STRUCTURAL_DECORATOR_CHEESE_PIZZA_HPP
#define STRUCTURAL_DECORATOR_CHEESE_PIZZA_HPP

#include "custom_pizza.hpp"

class CheesePizza : public CustomPizza {
	public:
	CheesePizza(std::unique_ptr<Pizza>&& pizza) : CustomPizza(std::move(pizza)) {}
	
	virtual int GetPrice() override {
		return 4 + sub_pizza_->GetPrice();
	}
};

#endif // STRUCTURAL_DECORATOR_CHEESE_PIZZA_HPP
