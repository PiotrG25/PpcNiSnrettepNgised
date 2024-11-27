
#include "diavola_builder.hpp"

void DiavolaBuilder::MakePizza(){
	pizza_->SetSauce(Pizza::Sauce::Tomato);
	pizza_->AddCheese(Pizza::Cheese::Mozzarella);
	pizza_->AddTopping(Pizza::Topping::SpicySalami);
	pizza_->AddTopping(Pizza::Topping::RedChiliFlakes);
	pizza_->AddTopping(Pizza::Topping::BlackOlives);
}
