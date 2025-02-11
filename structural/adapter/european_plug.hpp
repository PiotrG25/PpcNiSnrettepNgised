
#ifndef STRUCTURAL_ADAPTER_EUROPEAN_PLUG_HPP
#define STRUCTURAL_ADAPTER_EUROPEAN_PLUG_HPP

#include "european_plug_interface.hpp"

class EuropeanPlug : public EuropeanPlugInterface{
	public:
	EuropeanPlug() = default;
	EuropeanPlug(int voltage) : voltage_(voltage) {}
	virtual int ConnectToEuropeanSocket() const override {
		return voltage_;
	}
	protected:
	int voltage_;
};

#endif // STRUCTURAL_ADAPTER_EUROPEAN_PLUG_HPP
