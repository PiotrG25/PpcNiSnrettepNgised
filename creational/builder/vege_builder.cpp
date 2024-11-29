
#include "vege_builder.hpp"

PizzaBuilder& VegeBuilder::AddSauce(){
	pizza_->SetSauce(Pizza::Sauce::SpicyArrabbiataSauce);
	return *this;
}

PizzaBuilder& VegeBuilder::AddCheese(){
	pizza_->AddCheese(Pizza::Cheese::VeganCheese);
	return *this;
}

PizzaBuilder& VegeBuilder::AddToppings(){
	pizza_->AddTopping(Pizza::Topping::Jalapenos);
	pizza_->AddTopping(Pizza::Topping::RedOnion);
	pizza_->AddTopping(Pizza::Topping::BlackOlives);
	pizza_->AddTopping(Pizza::Topping::RoastedGarlic);
	return *this;
}

PizzaBuilder& VegeBuilder::SetTraits(){
	pizza_->SetIsGlutenFree(true);
	pizza_->SetIsVegan(true);
	return *this;
}
