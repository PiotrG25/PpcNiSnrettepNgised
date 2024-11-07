
#include "pizza_cook.hpp"

Pizza PizzaCook::CookMargherita(Pizza::Size size, Pizza::Dough dough){
return PizzaBuilder().SetSize(size).SetDough(dough)
					 .SetSauce(Pizza::Sauce::Tomato)
					 .AddCheese(Pizza::Cheese::Mozzarella)
					 .AddTopping(Pizza::Topping::Basil)
					 .AddTopping(Pizza::Topping::OliveOil)
					 .build();
}

Pizza PizzaCook::CookDiavola(Pizza::Size size, Pizza::Dough dough){
return PizzaBuilder().SetSize(size).SetDough(dough)
					 .SetSauce(Pizza::Sauce::Tomato)
					 .AddCheese(Pizza::Cheese::Mozzarella)
					 .AddTopping(Pizza::Topping::SpicySalami)
					 .AddTopping(Pizza::Topping::RedChiliFlakes)
					 .AddTopping(Pizza::Topping::BlackOlives)
					 .build();
}

Pizza PizzaCook::CookNapoli(Pizza::Size size, Pizza::Dough dough){
return PizzaBuilder().SetSize(size).SetDough(dough)
					 .SetSauce(Pizza::Sauce::Tomato)
					 .AddCheese(Pizza::Cheese::Mozzarella)
					 .AddTopping(Pizza::Topping::Anchovies)
					 .AddTopping(Pizza::Topping::Capers)
					 .AddTopping(Pizza::Topping::BlackOlives)
					 .AddTopping(Pizza::Topping::Oregano)
					 .build();
}

Pizza PizzaCook::CookVeggie(Pizza::Size size, Pizza::Dough dough){
return PizzaBuilder().SetSize(size).SetDough(dough)
					 .SetSauce(Pizza::Sauce::SpicyArrabbiataSauce)
					 .AddCheese(Pizza::Cheese::VeganCheese)
					 .AddTopping(Pizza::Topping::Jalapenos)
					 .AddTopping(Pizza::Topping::RedOnion)
					 .AddTopping(Pizza::Topping::BlackOlives)
					 .AddTopping(Pizza::Topping::RoastedGarlic)
					 .SetIsGlutenFree(true)
					 .SetIsVegan(true)
					 .build();
}
