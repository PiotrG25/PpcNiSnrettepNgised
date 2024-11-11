
#ifndef CREATIONAL_ABSTRACT_FACTORY_STANDARD_CAR_PARTS_FACTORY_HPP
#define CREATIONAL_ABSTRACT_FACTORY_STANDARD_CAR_PARTS_FACTORY_HPP

#include "car_parts_factory.hpp"
#include "standard_engine.hpp"
#include "standard_body.hpp"

class StandardCarPartsFactory : public CarPartsFactory{
	public:
	std::unique_ptr<Engine> MakeEngine() const override{
		return std::make_unique<StandardEngine>();
	}
	std::unique_ptr<Body> MakeBody() const override{
		return std::make_unique<StandardBody>();
	}
};

#endif // CREATIONAL_ABSTRACT_FACTORY_STANDARD_CAR_PARTS_FACTORY_HPP
