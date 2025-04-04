
#include "restaurant_kitchen.hpp"
#include <iostream>

void RestaurantKitchen::AddOrder(const std::shared_ptr<Command>& order){
	std::cout << "kitchen add order" << std::endl;
    std::cout << "orders: " << orders_.size() << std::endl;
    std::cout << "pizzas: " << pizzas_.size() << std::endl;
	orders_.push_back(order);
	std::cout << "kitchen add order after push" << std::endl;
    std::cout << "orders: " << orders_.size() << std::endl;
    std::cout << "pizzas: " << pizzas_.size() << std::endl;
}

void RestaurantKitchen::AddPizza(const std::shared_ptr<Pizza>& pizza){
	pizzas_.push_back(pizza);
}

std::shared_ptr<Command> RestaurantKitchen::GetOrder(){
	auto order = orders_.front();
	orders_.pop_front();
	return order;
}

std::shared_ptr<Pizza> RestaurantKitchen::GetPizza(){
	auto pizza = pizzas_.front();
	pizzas_.pop_front();
	return pizza;
}

bool RestaurantKitchen::HasOrders(){
	return not orders_.empty();
}

bool RestaurantKitchen::HasPizzas(){
	return not pizzas_.empty();
}
