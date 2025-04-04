
#ifndef BEHAVIORAL_COMMAND_RESTAURANT_WAITERS_HPP
#define BEHAVIORAL_COMMAND_RESTAURANT_WAITERS_HPP

#include <memory>
#include <vector>
#include "waiter.hpp"

class RestaurantWaiters{
	public:
	std::shared_ptr<Waiter> WaveForWaiter();
	void RegisterWaiter(const std::shared_ptr<Waiter>& waiter);

	private:
	std::vector<std::shared_ptr<Waiter>> waiters_{};
	unsigned int next_waiter_{0};
};

#endif // BEHAVIORAL_COMMAND_RESTAURANT_WAITERS_HPP
