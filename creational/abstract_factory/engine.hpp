
#ifndef CREATIONAL_ABSTRACT_FACTORY_ENGINE_HPP
#define CREATIONAL_ABSTRACT_FACTORY_ENGINE_HPP

class Engine{
	public:
	enum class FuelEfficiency{Low, High};
	
	virtual std::uint8_t GetHorsePower() const = 0;
	virtual std::uint8_t GetTopSpeed() const = 0;
	virtual FuelEfficiency GetFuelEfficiency() const = 0;
};

#endif // CREATIONAL_ABSTRACT_FACTORY_ENGINE_HPP
