
#include "client.hpp"

void Client::OrderDiavola(Waiter& waiter){
	pizza_ = waiter.OrderDiavola();
}
void Client::OrderVege(Waiter& waiter){
	pizza_ = waiter.OrderVege();
}
void Client::OrderSameAsThePreviousPerson(Waiter& waiter){
	pizza_ = waiter.OrderSameAsThePreviousPerson();
	if(pizza_->GetTaste() == PrototypePizza::Taste::No){
		OrderDiavola(waiter); // always good
	}
}

bool Client::IsSatisfied() const{
	return pizza_->GetTaste() == PrototypePizza::Taste::Good;
}
