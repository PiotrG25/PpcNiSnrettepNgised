
#ifndef STRUCTURAL_FLYWEIGHT_PIZZA_TYPE_HPP
#define STRUCTURAL_FLYWEIGHT_PIZZA_TYPE_HPP

#include <vector>
#include "enums.hpp"

class PizzaType{
	public:
	PizzaType(enums::Size size, enums::Cheese cheese) : size_(size), cheese_(cheese) {}
	
	void AddTopping(enums::Topping topping){
		toppings_.push_back(topping);
	}
	
	enums::Size GetSize() const {
		return size_;
	}
	
	enums::Cheese GetCheese() const {
		return cheese_;
	}
	
	const std::vector<enums::Topping>& GetToppings() const {
		return toppings_;
	}
	
	private:
	std::vector<enums::Topping> toppings_{};
	enums::Size size_;
	enums::Cheese cheese_;
};

#endif // STRUCTURAL_FLYWEIGHT_PIZZA_TYPE_HPP