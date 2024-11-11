
#ifndef CREATIONAL_ABSTRACT_FACTORY_STANDARD_ENGINE_HPP
#define CREATIONAL_ABSTRACT_FACTORY_STANDARD_ENGINE_HPP

#include "engine.hpp"

class StandardEngine : public Engine{
	public:
	std::uint8_t GetHorsePower() const override{
		return 200;
	}
	std::uint8_t GetTopSpeed() const override{
		return 200;
	}
	FuelEfficiency GetFuelEfficiency() const override{
		return FuelEfficiency::High;
	}
};

#endif // CREATIONAL_ABSTRACT_FACTORY_STANDARD_ENGINE_HPP
