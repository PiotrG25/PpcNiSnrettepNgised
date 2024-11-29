
#include "napoli_builder.hpp"

PizzaBuilder& NapoliBuilder::AddSauce(){
	pizza_->SetSauce(Pizza::Sauce::Tomato);
	return *this;
}

PizzaBuilder& NapoliBuilder::AddCheese(){
	pizza_->AddCheese(Pizza::Cheese::Mozzarella);
	return *this;
}
PizzaBuilder& NapoliBuilder::AddToppings(){
	pizza_->AddTopping(Pizza::Topping::Anchovies);
	pizza_->AddTopping(Pizza::Topping::Capers);
	pizza_->AddTopping(Pizza::Topping::BlackOlives);
	pizza_->AddTopping(Pizza::Topping::Oregano);
	return *this;
}
