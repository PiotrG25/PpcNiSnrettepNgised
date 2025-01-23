
#ifndef STRUCTURAL_FLYWEIGHT_HEAVYWEIGHT_PIZZA_HPP
#define STRUCTURAL_FLYWEIGHT_HEAVYWEIGHT_PIZZA_HPP

#include <vector>
#include "enums.hpp"

class HeavyweightPizza{
	public:
	HeavyweightPizza(enums::Size size, enums::Cheese cheese, int table_number) : size_(size), cheese_(cheese), table_number_(table_number) {}
	
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
	
	int GetTableNumber() const {
		return table_number_;
	}
	
	private:
	std::vector<enums::Topping> toppings_{};
	enums::Size size_;
	enums::Cheese cheese_;
	int table_number_;
};

#endif // STRUCTURAL_FLYWEIGHT_HEAVYWEIGHT_PIZZA_HPP