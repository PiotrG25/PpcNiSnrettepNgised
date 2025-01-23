
#ifndef STRUCTURAL_FLYWEIGHT_PIZZA_HPP
#define STRUCTURAL_FLYWEIGHT_PIZZA_HPP

#include "pizza_type.hpp"
#include <memory>

class Pizza{
	public:
	Pizza(const std::shared_ptr<PizzaType>& pizza_type, int table_number) : pizza_type_(pizza_type), table_number_(table_number) {}
	
	std::shared_ptr<PizzaType> GetPizzaType() const {
		return pizza_type_;
	}
	
	int GetTableNumber() const {
		return table_number_;
	}
	
	private:
	std::shared_ptr<PizzaType> pizza_type_;
	int table_number_;
};

#endif // STRUCTURAL_FLYWEIGHT_PIZZA_HPP