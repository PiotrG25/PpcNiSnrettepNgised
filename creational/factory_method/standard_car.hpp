
#ifndef CREATIONAL_FATORY_METHOD_STANDARD_CAR_HPP
#define CREATIONAL_FATORY_METHOD_STANDARD_CAR_HPP

#include "car.hpp"

class StandardCar : public Car{
	public:
	virtual FuelEfficiency GetFuelEfficiency() const override;
	virtual BodyDesign GetBodyDesign() const override;
};

#endif // CREATIONAL_FATORY_METHOD_STANDARD_CAR_HPP
