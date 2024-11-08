
#ifndef CREATIONAL_PROTOTYPE_TEST_PROTOTYPE_HPP
#define CREATIONAL_PROTOTYPE_TEST_PROTOTYPE_HPP

class Prototype{
	public:
	virtual Prototype* clone() const = 0;
};

class A: public Prototype{
	public:
	Prototype* clone() const override{
		return new A(*this); 
	}
	A(int i) : i_(i) {}
	int i_;
};

class B : public A{
	public:
	Prototype* clone() const override{
		return new B(*this);
	}
	B(int i, int j) : A(i), j_(j) {}
	int j_;
};

#endif CREATIONAL_PROTOTYPE_TEST_PROTOTYPE_HPP
