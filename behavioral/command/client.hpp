
#ifndef BEHAVIORAL_COMMAND_CLIENT_HPP
#define BEHAVIORAL_COMMAND_CLIENT_HPP

#include "restaurant_waiters.hpp"

class Client{
	public:
	Client(RestaurantWaiters& waiters) : waiters_(waiters) {}

	void OrderMargherita();
	void OrderPepperoni();

	void ExpectPizza();

	std::shared_ptr<Pizza> GetPizza();

	private:
	RestaurantWaiters& waiters_;
	std::shared_ptr<Pizza> pizza_{};
};

#endif // BEHAVIORAL_COMMAND_CLIENT_HPP