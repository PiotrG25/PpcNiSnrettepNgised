
#ifndef BEHAVIORAL_COMMAND_PIZZA_HPP
#define BEHAVIORAL_COMMAND_PIZZA_HPP

#include <vector>

class Pizza{
	public:
	enum class Topping{Basil, OliveOil, SpicySalami, RedChiliFlakes, BlackOlives};

	const std::vector<Topping>& GetToppings() const { return toppings_; }

	protected:
	std::vector<Topping> toppings_{};
};

#endif // BEHAVIORAL_COMMAND_PIZZA_HPP
