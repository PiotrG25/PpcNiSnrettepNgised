
#include "diavola_builder.hpp"

PizzaBuilder& DiavolaBuilder::AddSauce(){
	pizza_->SetSauce(Pizza::Sauce::Tomato);
	return *this;
}

PizzaBuilder& DiavolaBuilder::AddCheese(){
	pizza_->AddCheese(Pizza::Cheese::Mozzarella);
	return *this;
}

PizzaBuilder& DiavolaBuilder::AddToppings(){
	pizza_->AddTopping(Pizza::Topping::SpicySalami);
	pizza_->AddTopping(Pizza::Topping::RedChiliFlakes);
	pizza_->AddTopping(Pizza::Topping::BlackOlives);
	return *this;
}
