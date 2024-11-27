
#include "margherita_builder.hpp"

void MargheritaBuilder::MakePizza(){
	pizza_->SetSauce(Pizza::Sauce::Tomato);
	pizza_->AddCheese(Pizza::Cheese::Mozzarella);
	pizza_->AddTopping(Pizza::Topping::Basil);
	pizza_->AddTopping(Pizza::Topping::OliveOil);
}
