
#include "client.hpp"
#include "margherita_command.hpp"
#include "pepperoni_command.hpp"

void Client::OrderMargherita(){
	auto waiter = waiters_.WaveForWaiter();
	std::shared_ptr<Command> command = std::make_shared<MargheritaCommand>();
	waiter->TakeOrder(command);
}

void Client::OrderPepperoni(){
	auto waiter = waiters_.WaveForWaiter();
	std::shared_ptr<Command> command = std::make_shared<PepperoniCommand>();
	waiter->TakeOrder(command);
}

void Client::ExpectPizza(){
	auto waiter = waiters_.WaveForWaiter();
	pizza_ = waiter->BringPizza();
}

std::shared_ptr<Pizza> Client::GetPizza(){
	return pizza_;
}
