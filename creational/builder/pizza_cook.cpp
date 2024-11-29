
#include "pizza_cook.hpp"

PizzaCook::PizzaCook(std::unique_ptr<PizzaBuilder>&& builder) : builder_(std::move(builder)) {}

void PizzaCook::SetBuilder(std::unique_ptr<PizzaBuilder>&& builder){
	builder_ = std::move(builder);
}

std::unique_ptr<Pizza> PizzaCook::MakePizza(Pizza::Size size, Pizza::Dough dough){
	return builder_->MakeBase(size, dough).AddSauce().AddCheese().AddToppings().SetTraits().build();
}

std::unique_ptr<Pizza> PizzaCook::MakeDoubleCheesePizza(Pizza::Size size, Pizza::Dough dough){
	return builder_->MakeBase(size, dough).AddSauce().AddCheese().AddCheese().AddToppings().SetTraits().build();
}

std::unique_ptr<Pizza> PizzaCook::MakeDoubleToppingsPizza(Pizza::Size size, Pizza::Dough dough){
	return builder_->MakeBase(size, dough).AddSauce().AddCheese().AddToppings().AddToppings().SetTraits().build();
}
