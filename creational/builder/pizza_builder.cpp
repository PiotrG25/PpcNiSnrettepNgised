
#include "pizza_builder.hpp"

PizzaBuilder::PizzaBuilder() : pizza_(std::make_unique<Pizza>()) {}

void PizzaBuilder::MakeBase(Pizza::Size size, Pizza::Dough dough){
	pizza_->SetSize(size);
	pizza_->SetDough(dough);
}
	
std::unique_ptr<Pizza> PizzaBuilder::build(Pizza::Size size, Pizza::Dough dough){
	MakeBase(size, dough);
	MakePizza();
	
	std::unique_ptr<Pizza> result = std::move(pizza_);
	pizza_ = std::make_unique<Pizza>();
	return result;
}
