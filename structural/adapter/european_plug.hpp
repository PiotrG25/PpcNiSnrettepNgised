
#ifndef STRUCTURAL_ADAPTER_EUROPEAN_PLUG_HPP
#define STRUCTURAL_ADAPTER_EUROPEAN_PLUG_HPP

#include "european_plug_interface.hpp"

class EuropeanPlug : public EuropeanPlugInterface{
	public:
	EuropeanPlug(int id) : id_(id) {}
	virtual int ConnectToEuropeanSocket() const override {
		return id_;
	}
	private:
	int id_;
};

#endif // STRUCTURAL_ADAPTER_EUROPEAN_PLUG_HPP
