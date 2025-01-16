

#include "standard_car.hpp"

Car::FuelEfficiency StandardCar::GetFuelEfficiency() const {
	return FuelEfficiency::High;
}
Car::BodyDesign StandardCar::GetBodyDesign() const {
	return BodyDesign::Standard;
}
