
#ifndef CREATIONAL_ABSTRACT_FACTORY_BODY_HPP
#define CREATIONAL_ABSTRACT_FACTORY_BODY_HPP

class Body{
	public:
	enum class Design{Beautiful, Standard};
	
	virtual std::float_t GetDragCoefficient() const = 0;
	virtual Design GetDesign() const = 0;
};

#endif // CREATIONAL_ABSTRACT_FACTORY_BODY_HPP
