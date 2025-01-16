
#ifndef CREATIONAL_FATORY_METHOD_CAR_FACTORY_HPP
#define CREATIONAL_FATORY_METHOD_CAR_FACTORY_HPP

#include "car.hpp"
#include <memory>

enum class CarType{SuperCar, StandardCar};

std::unique_ptr<Car> MakeCar(CarType type);
	
#endif // CREATIONAL_FATORY_METHOD_CAR_FACTORY_HPP
