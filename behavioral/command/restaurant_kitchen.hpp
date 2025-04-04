
#ifndef BEHAVIORAL_COMMAND_RESTAURANT_KITCHEN_HPP
#define BEHAVIORAL_COMMAND_RESTAURANT_KITCHEN_HPP

#include <memory>
#include <deque>
#include "command.hpp"
#include "pizza.hpp"

class RestaurantKitchen{
	public:
	void AddOrder(const std::shared_ptr<Command>& order);
	void AddPizza(const std::shared_ptr<Pizza>& pizza);

	std::shared_ptr<Command> GetOrder();
	std::shared_ptr<Pizza> GetPizza();

	bool HasOrders();
	bool HasPizzas();

	// todo
	// private:
	std::deque<std::shared_ptr<Command>> orders_{};
	std::deque<std::shared_ptr<Pizza>> pizzas_{};
};

#endif // BEHAVIORAL_COMMAND_RESTAURANT_KITCHEN_HPP
