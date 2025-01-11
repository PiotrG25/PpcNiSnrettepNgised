
#ifndef CREATIONAL_FATORY_METHOD_STANDARD_CAR_HPP
#define CREATIONAL_FATORY_METHOD_STANDARD_CAR_HPP

#include "car.hpp"

class StandardCar : public Car{
	public:
	virtual FuelEfficiency GetFuelEfficiency() const override {
		return FuelEfficiency::High;
	}
	virtual BodyDesign GetBodyDesign() const override {
		return BodyDesign::Standard;
	}
};

#endif // CREATIONAL_FATORY_METHOD_STANDARD_CAR_HPP
