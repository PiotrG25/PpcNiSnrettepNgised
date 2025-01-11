
#ifndef CREATIONAL_FATORY_METHOD_CAR_FACTORY_HPP
#define CREATIONAL_FATORY_METHOD_CAR_FACTORY_HPP

#include "standard_car.hpp"
#include "super_car.hpp"

enum class CarType{SuperCar, StandardCar};

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
	
#endif // CREATIONAL_FATORY_METHOD_CAR_FACTORY_HPP
