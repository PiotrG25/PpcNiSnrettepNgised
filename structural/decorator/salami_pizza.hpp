
#ifndef STRUCTURAL_DECORATOR_SALAMI_PIZZA_HPP
#define STRUCTURAL_DECORATOR_SALAMI_PIZZA_HPP

#include "custom_pizza.hpp"

class SalamiPizza : public CustomPizza {
	public:
	SalamiPizza(std::unique_ptr<Pizza>&& pizza) : CustomPizza(std::move(pizza)) {}
	
	virtual int GetPrice() override {
		return 6 + sub_pizza_->GetPrice();
	}
};

#endif // STRUCTURAL_DECORATOR_SALAMI_PIZZA_HPP
