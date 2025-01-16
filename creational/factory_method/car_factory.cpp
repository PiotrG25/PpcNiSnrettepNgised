
#include "car_factory.hpp"
#include "standard_car.hpp"
#include "super_car.hpp"

std::unique_ptr<Car> MakeCar(CarType type){
	switch(type){
		case CarType::StandardCar:
			return std::make_unique<StandardCar>();
		case CarType::SuperCar:
			return std::make_unique<SuperCar>();
		default:
			return nullptr;
	}
}
