
#ifndef CREATIONAL_ABSTRACT_FACTORY_STANDARD_BODY_HPP
#define CREATIONAL_ABSTRACT_FACTORY_STANDARD_BODY_HPP

#include "body.hpp"

class StandardBody : public Body{
	public:
	std::float_t GetDragCoefficient() const override{
		return 0.40F;
	}
	Design GetDesign() const override{
		return Design::Standard;
	}
};

#endif // CREATIONAL_ABSTRACT_FACTORY_STANDARD_BODY_HPP
