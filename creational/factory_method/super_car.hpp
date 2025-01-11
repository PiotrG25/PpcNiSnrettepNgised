
#ifndef CREATIONAL_FATORY_METHOD_SUPER_CAR_HPP
#define CREATIONAL_FATORY_METHOD_SUPER_CAR_HPP

#include "car.hpp"

class SuperCar : public Car{
	public:
	virtual FuelEfficiency GetFuelEfficiency() const override {
		return FuelEfficiency::Low;
	}
	virtual BodyDesign GetBodyDesign() const override {
		return BodyDesign::Beautiful;
	}
};

#endif // CREATIONAL_FATORY_METHOD_SUPER_CAR_HPP
