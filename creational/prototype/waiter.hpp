
#ifndef CREATIONAL_PROTOTYPE_WAITER_HPP
#define CREATIONAL_PROTOTYPE_WAITER_HPP

#include "diavola.hpp"
#include "vege.hpp"
#include "undefined_pizza.hpp"
#include "prototype_pizza.hpp"
#include <list>

class Waiter{
	public:
	std::shared_ptr<PrototypePizza> OrderDiavola(){
		std::shared_ptr<Diavola> pizza = std::make_shared<Diavola>();
		orders_.push_back(pizza);
		return pizza;
	}
	
	std::shared_ptr<PrototypePizza> OrderVege(){
		std::shared_ptr<Vege> pizza = std::make_shared<Vege>();
		orders_.push_back(pizza);
		return pizza;
	}
	
	std::shared_ptr<PrototypePizza> OrderSameAsThePreviousPerson(){
		if(orders_.size() <= 0){
			return std::make_shared<UndefinedPizza>();
		}
		std::shared_ptr<PrototypePizza> pizza = (*orders_.rbegin())->clone();
		orders_.push_back(pizza);
		return pizza;
	}
	
	private:
	std::list<std::shared_ptr<PrototypePizza>> orders_{};
};

#endif // CREATIONAL_PROTOTYPE_WAITER_HPP
