
#include "cook.hpp"
#include <stdexcept>

void Cook::MakeNext(){
	if(not kitchen_.HasOrders()){
		throw std::runtime_error("No Orders for kitchen");
	}
	auto order = kitchen_.GetOrder();
	auto pizza = order->Execute();
	kitchen_.AddPizza(pizza);
}
