
#include "restaurant_waiters.hpp"
#include <stdexcept>

std::shared_ptr<Waiter> RestaurantWaiters::WaveForWaiter(){
	if(waiters_.empty()){
		throw std::runtime_error("RestaurantWaiters::WaveForWaiter called when no waiters registered");
	}

	std::shared_ptr<Waiter> waiter = waiters_.at(next_waiter_);

	++next_waiter_;
	if(next_waiter_ >= waiters_.size()){
		next_waiter_ = 0;
	}

	return waiter;
}

void RestaurantWaiters::RegisterWaiter(const std::shared_ptr<Waiter>& waiter){
	waiters_.push_back(waiter);
}
