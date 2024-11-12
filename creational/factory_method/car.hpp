
#ifndef CREATIONAL_FATORY_METHOD_CAR_HPP
#define CREATIONAL_FATORY_METHOD_CAR_HPP

#include "creational/abstract_factory/car_parts_factory.hpp"

class Car{
	public:
	Car(const CarPartsFactory& factory)
	: engine_(factory.MakeEngine()), body_(factory.MakeBody())
	{}
	
	const std::unique_ptr<Engine>& GetEngine() const{
		return engine_;
	}
	const std::unique_ptr<Body>& GetBody() const{
		return body_;
	}
	private:
	std::unique_ptr<Engine> engine_;
	std::unique_ptr<Body> body_;
};

#endif // CREATIONAL_FATORY_METHOD_CAR_HPP
