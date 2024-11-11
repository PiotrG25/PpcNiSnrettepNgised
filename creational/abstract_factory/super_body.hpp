
#ifndef CREATIONAL_ABSTRACT_FACTORY_SUPER_BODY_HPP
#define CREATIONAL_ABSTRACT_FACTORY_SUPER_BODY_HPP

#include "body.hpp"

class SuperBody : public Body{
	public:
	std::float_t GetDragCoefficient() const override{
		return 0.28F;
	}
	Design GetDesign() const override{
		return Design::Beautiful;
	}
};

#endif // CREATIONAL_ABSTRACT_FACTORY_SUPER_BODY_HPP
