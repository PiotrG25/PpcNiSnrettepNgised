
#ifndef BEHAVIORAL_COMMAND_COOK_HPP
#define BEHAVIORAL_COMMAND_COOK_HPP

#include "command.hpp"
#include "restaurant_kitchen.hpp"
#include <memory>

class Cook{
	public:
	Cook(RestaurantKitchen& kitchen): kitchen_(kitchen) {}
	void MakeNext();

	private:
	RestaurantKitchen& kitchen_;	
};

#endif // BEHAVIORAL_COMMAND_COOK_HPP