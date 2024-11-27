
#include "pizza_cook.hpp"

PizzaCook::PizzaCook(std::unique_ptr<PizzaBuilder>&& builder) : builder_(std::move(builder)) {}

void PizzaCook::SetBuilder(std::unique_ptr<PizzaBuilder>&& builder){
	builder_ = std::move(builder);
}

std::unique_ptr<Pizza> PizzaCook::build(Pizza::Size size, Pizza::Dough dough){
	return builder_->build(size, dough);
}
