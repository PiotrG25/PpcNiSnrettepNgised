
#include "pizza_builder.hpp"

PizzaBuilder::PizzaBuilder() : pizza_(std::make_unique<Pizza>()) {}

PizzaBuilder& PizzaBuilder::MakeBase(Pizza::Size size, Pizza::Dough dough){
	pizza_->SetSize(size);
	pizza_->SetDough(dough);
	return *this;
}

PizzaBuilder& PizzaBuilder::SetTraits(){
	return *this;
}

std::unique_ptr<Pizza> PizzaBuilder::build(){
	std::unique_ptr<Pizza> result = std::move(pizza_);
	pizza_ = std::make_unique<Pizza>();
	return result;
}
