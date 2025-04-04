
#ifndef BEHAVIORAL_COMMAND_WAITER_HPP
#define BEHAVIORAL_COMMAND_WAITER_HPP

#include <memory>
#include "command.hpp"
#include "restaurant_kitchen.hpp"

class Waiter{
	public:
	Waiter(RestaurantKitchen& kitchen) : kitchen_(kitchen) {}
	void TakeOrder(const std::shared_ptr<Command>& order);
	void PassOrderToKitchen();
	std::shared_ptr<Pizza> BringPizza();

	private:
	RestaurantKitchen kitchen_;
	std::shared_ptr<Command> command_{nullptr};
};

#endif // BEHAVIORAL_COMMAND_WAITER_HPP