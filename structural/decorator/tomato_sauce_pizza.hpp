
#ifndef STRUCTURAL_DECORATOR_TOMATO_SAUCE_PIZZA_HPP
#define STRUCTURAL_DECORATOR_TOMATO_SAUCE_PIZZA_HPP

#include "custom_pizza.hpp"

class TomatoSaucePizza : public CustomPizza {
	public:
	TomatoSaucePizza(std::unique_ptr<Pizza>&& pizza) : CustomPizza(std::move(pizza)) {}
	
	virtual int GetPrice() override {
		return 10 + sub_pizza_->GetPrice();
	}
};

#endif // STRUCTURAL_DECORATOR_TOMATO_SAUCE_PIZZA_HPP
