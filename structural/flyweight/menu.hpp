
#ifndef STRUCTURAL_FLYWEIGHT_MENU_HPP
#define STRUCTURAL_FLYWEIGHT_MENU_HPP

#include <vector>
#include <memory>
#include <stdexcept>
#include "pizza.hpp"
#include "pizza_type.hpp"

class Menu{
	public:
	Menu(){
		pizzas_.emplace_back(std::make_shared<PizzaType>(enums::Size::Large, enums::Cheese::Mozzarella));
		pizzas_.at(0)->AddTopping(enums::Topping::SpicySalami);
		pizzas_.at(0)->AddTopping(enums::Topping::Jalapenos);
	}
	
	std::size_t GetMenuSize(){
		return pizzas_.size();
	}
	
	Pizza OrderPizza(std::size_t pizza_id, int table_number){
		if(pizza_id >= pizzas_.size()){
			throw std::runtime_error("pizza_id too large: " + std::to_string(pizza_id) + " >= " + std::to_string(pizzas_.size()));
		}
		return Pizza(pizzas_.at(pizza_id), table_number);
	}
	
	const PizzaType& GetPizzaType(std::size_t pizza_id){
		if(pizza_id >= pizzas_.size()){
			throw std::runtime_error("pizza_id too large: " + std::to_string(pizza_id) + " >= " + std::to_string(pizzas_.size()));
		}
		return * pizzas_.at(pizza_id);
	}
	
	private:
	std::vector<std::shared_ptr<PizzaType>> pizzas_{};
};

#endif // STRUCTURAL_FLYWEIGHT_MENU_HPP