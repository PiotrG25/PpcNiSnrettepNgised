
#include "waiter.hpp"
#include "diavola.hpp"
#include "vege.hpp"
#include "undefined_pizza.hpp"

std::shared_ptr<PrototypePizza> Waiter::OrderDiavola(){
	std::shared_ptr<Diavola> pizza = std::make_shared<Diavola>();
	orders_.push_back(pizza);
	return pizza;
}

std::shared_ptr<PrototypePizza> Waiter::OrderVege(){
	std::shared_ptr<Vege> pizza = std::make_shared<Vege>();
	orders_.push_back(pizza);
	return pizza;
}

std::shared_ptr<PrototypePizza> Waiter::OrderSameAsThePreviousPerson(){
	if(orders_.size() <= 0){
		return std::make_shared<UndefinedPizza>();
	}
	std::shared_ptr<PrototypePizza> pizza = (*orders_.rbegin())->clone();
	orders_.push_back(pizza);
	return pizza;
}
