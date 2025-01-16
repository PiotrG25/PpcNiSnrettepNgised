
#ifndef CREATIONAL_PROTOTYPE_CLIENT_HPP
#define CREATIONAL_PROTOTYPE_CLIENT_HPP

#include "waiter.hpp"
#include "prototype_pizza.hpp"

class Client{
	public:
	void OrderDiavola(Waiter& waiter);
	void OrderVege(Waiter& waiter);
	void OrderSameAsThePreviousPerson(Waiter& waiter);
	bool IsSatisfied() const;
	
	private:
	std::shared_ptr<PrototypePizza> pizza_{nullptr};
};

#endif // CREATIONAL_PROTOTYPE_CLIENT_HPP
