
#include "waiter.hpp"
#include <stdexcept>

void Waiter::TakeOrder(const std::shared_ptr<Command>& order){
	command_ = order;
}
#include <iostream>

void Waiter::PassOrderToKitchen(){
	std::cout << "waiter before add" << std::endl;
    std::cout << "has orders: " << kitchen_.HasOrders() << std::endl;
    std::cout << "has pizzas: " << kitchen_.HasPizzas() << std::endl;
	kitchen_.AddOrder(command_);
	std::cout << "waiter after add" << std::endl;
    std::cout << "has orders: " << kitchen_.HasOrders() << std::endl;
    std::cout << "has pizzas: " << kitchen_.HasPizzas() << std::endl;
	command_ = nullptr;
    std::cout << "has orders: " << kitchen_.HasOrders() << std::endl;
    std::cout << "has pizzas: " << kitchen_.HasPizzas() << std::endl;
}

std::shared_ptr<Pizza> Waiter::BringPizza(){
	if(not kitchen_.HasPizzas()){
		throw std::runtime_error("No Pizzas ready for Client");
	}
	return kitchen_.GetPizza();
}
