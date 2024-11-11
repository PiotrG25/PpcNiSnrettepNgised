
#ifndef CREATIONAL_ABSTRACT_FACTORY_SUPER_ENGINE_HPP
#define CREATIONAL_ABSTRACT_FACTORY_SUPER_ENGINE_HPP

#include "engine.hpp"

class SuperEngine : public Engine{
	public:
	std::uint8_t GetHorsePower() const override{
		return 800;
	}
	std::uint8_t GetTopSpeed() const override{
		return 400;
	}
	FuelEfficiency GetFuelEfficiency() const override{
		return FuelEfficiency::Low;
	}
};

#endif // CREATIONAL_ABSTRACT_FACTORY_SUPER_ENGINE_HPP
