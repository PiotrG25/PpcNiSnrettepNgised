
#ifndef CREATIONAL_FATORY_METHOD_CAR_FACTORY_HPP
#define CREATIONAL_FATORY_METHOD_CAR_FACTORY_HPP

#include "creational/abstract_factory/super_car_parts_factory.hpp"
#include "creational/abstract_factory/standard_car_parts_factory.hpp"
#include "car.hpp"

class CarFactory{
	public:
	enum class CarType{SuperCar, StandardCar};
	std::unique_ptr<Car> MakeCar(CarType type) const{
		switch(type){
			case CarType::SuperCar:
				return std::make_unique<Car>(super_factory_);
			case CarType::StandardCar:
				return std::make_unique<Car>(standard_factory_);
			default:
				return nullptr;
		}
	}
	
	private:
	SuperCarPartsFactory super_factory_;
	StandardCarPartsFactory standard_factory_;
};

#endif // CREATIONAL_FATORY_METHOD_CAR_FACTORY_HPP
