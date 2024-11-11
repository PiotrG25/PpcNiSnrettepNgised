
#ifndef CREATIONAL_ABSTRACT_FACTORY_SUPER_CAR_PARTS_FACTORY_HPP
#define CREATIONAL_ABSTRACT_FACTORY_SUPER_CAR_PARTS_FACTORY_HPP

#include "car_parts_factory.hpp"
#include "super_engine.hpp"
#include "super_body.hpp"

class SuperCarPartsFactory : public CarPartsFactory{
	public:
	std::unique_ptr<Engine> MakeEngine() const override{
		return std::make_unique<SuperEngine>();
	}
	std::unique_ptr<Body> MakeBody() const override{
		return std::make_unique<SuperBody>();
	}
};

#endif // CREATIONAL_ABSTRACT_FACTORY_SUPER_CAR_PARTS_FACTORY_HPP
