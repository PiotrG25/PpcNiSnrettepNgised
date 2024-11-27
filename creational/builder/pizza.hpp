
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
	
	Pizza() = default;
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

	void SetSize(Pizza::Size size){
		size_ = size;
	}
	Size GetSize(){
		return size_;
	}
	
	void SetDough(Pizza::Dough dough){
		dough_ = dough;
	}
	Dough GetDough(){
		return dough_;
	}
	
	void SetSauce(Pizza::Sauce sauce){
		sauce_ = sauce;
	}
	Sauce GetSauce(){
		return sauce_;
	}
	
	void AddCheese(Pizza::Cheese cheese){
		cheeses_.push_back(cheese);
	}
	const std::vector<Cheese>& GetCheeses(){
		return cheeses_;
	}
	
	void AddTopping(Pizza::Topping topping){
		toppings_.push_back(topping);
	}
	const std::vector<Topping>& GetToppings(){
		return toppings_;
	}
	
	void SetIsGlutenFree(bool is_gluten_free){
		is_gluten_free_ = is_gluten_free;
	}
	bool IsGlutenFree(){
		return is_gluten_free_;
	}
	
	void SetIsVegan(bool is_vegan){
		is_vegan_ = is_vegan;
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
