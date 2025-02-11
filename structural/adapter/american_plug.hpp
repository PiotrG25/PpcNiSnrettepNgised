
#ifndef STRUCTURAL_ADAPTER_AMERICAN_PLUG_HPP
#define STRUCTURAL_ADAPTER_AMERICAN_PLUG_HPP

#include "american_plug_interface.hpp"

class AmericanPlug : public AmericanPlugInterface{
	public:
	AmericanPlug() = default;
	AmericanPlug(int voltage) : voltage_(voltage) {}
	virtual int ConnectToAmericanSocket() const override{
		return voltage_;
	}
	protected:
	int voltage_;
};

#endif // STRUCTURAL_ADAPTER_AMERICAN_PLUG_HPP
