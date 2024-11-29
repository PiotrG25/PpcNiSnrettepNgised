
#include "margherita_builder.hpp"

PizzaBuilder& MargheritaBuilder::AddSauce(){
	pizza_->SetSauce(Pizza::Sauce::Tomato);
	return *this;
}

PizzaBuilder& MargheritaBuilder::AddCheese(){
	pizza_->AddCheese(Pizza::Cheese::Mozzarella);
	return *this;
}

PizzaBuilder& MargheritaBuilder::AddToppings(){
	pizza_->AddTopping(Pizza::Topping::Basil);
	pizza_->AddTopping(Pizza::Topping::OliveOil);
	return *this;
}
