
#ifndef CREATIONAL_ABSTRACT_FACTORY_CAR_PARTS_FACTORY_HPP
#define CREATIONAL_ABSTRACT_FACTORY_CAR_PARTS_FACTORY_HPP

#include "engine.hpp"
#include "body.hpp"

class CarPartsFactory{
	public:
	virtual std::unique_ptr<Engine> MakeEngine() const = 0;
	virtual std::unique_ptr<Body> MakeBody() const = 0;
};

#endif // CREATIONAL_ABSTRACT_FACTORY_CAR_PARTS_FACTORY_HPP
