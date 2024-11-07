
#ifndef CREATIONAL_PIZZA_HPP
#define CREATIONAL_PIZZA_HPP

#include <vector>

class Pizza{
	public:
	enum class Size{Small, Medium, Large};
	enum class Dough{Thin, Fluffy};
	enum class Sauce{Tomato, SpicyArrabbiataSauce};
	enum class Cheese{Mozzarella, Parmesan, Gouda, VeganCheese};
	enum class Topping{Basil, OliveOil, SpicySalami, RedChiliFlakes, BlackOlives, Anchovies, Capers, Oregano, Jalapenos, RedOnion, RoastedGarlic};
	
	Pizza(Size size,
		  Dough dough,
		  Sauce sauce,
		  const std::vector<Cheese>& cheeses,
		  const std::vector<Topping>& toppings,
		  bool is_gluten_free,
		  bool is_vegan)
	: size_(size),
	  dough_(dough),
	  sauce_(sauce),
	  cheeses_(cheeses),
	  toppings_(toppings),
	  is_gluten_free_(is_gluten_free),
	  is_vegan_(is_vegan) {}

	Size GetSize(){
		return size_;
	}
	Dough GetDough(){
		return dough_;
	}
	Sauce GetSauce(){
		return sauce_;
	}
	const std::vector<Cheese>& GetCheeses(){
		return cheeses_;
	}
	const std::vector<Topping>& GetToppings(){
		return toppings_;
	}
	bool IsGlutenFree(){
		return is_gluten_free_;
	}
	bool IsVegan(){
		return is_vegan_;
	}
	
	private:
	Size size_;
	Dough dough_;
	Sauce sauce_;
	std::vector<Cheese> cheeses_;
	std::vector<Topping> toppings_;
	bool is_gluten_free_;
	bool is_vegan_;
};

#endif // CREATIONAL_PIZZA_HPP
