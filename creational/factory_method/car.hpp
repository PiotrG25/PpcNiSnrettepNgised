
#ifndef CREATIONAL_FATORY_METHOD_CAR_HPP
#define CREATIONAL_FATORY_METHOD_CAR_HPP

class Car{
	public:
	enum class BodyDesign{Beautiful, Standard};
	enum class FuelEfficiency{Low, High};
	
	virtual FuelEfficiency GetFuelEfficiency() const = 0;
	virtual BodyDesign GetBodyDesign() const = 0;
};

#endif // CREATIONAL_FATORY_METHOD_CAR_HPP
