
#ifndef CREATIONAL_PROTOTYPE_CLIENT_HPP
#define CREATIONAL_PROTOTYPE_CLIENT_HPP

#include "waiter.hpp"
#include "prototype_pizza.hpp"

class Client{
	public:
	void OrderDiavola(Waiter& waiter){
		pizza_ = waiter.OrderDiavola();
	}
	void OrderVege(Waiter& waiter){
		pizza_ = waiter.OrderVege();
	}
	void OrderSameAsThePreviousPerson(Waiter& waiter){
		pizza_ = waiter.OrderSameAsThePreviousPerson();
		if(pizza_->GetTaste() == PrototypePizza::Taste::No){
			OrderDiavola(waiter); // always good
		}
	}
	
	bool IsSatisfied() const{
		return pizza_->GetTaste() == PrototypePizza::Taste::Good;
	}
	
	private:
	std::shared_ptr<PrototypePizza> pizza_{nullptr};
};

#endif // CREATIONAL_PROTOTYPE_CLIENT_HPP
