
#ifndef STRUCTURAL_ADAPTER_EUROPEAN_TO_AMERICAN_PLUG_ADAPTER_HPP
#define STRUCTURAL_ADAPTER_EUROPEAN_TO_AMERICAN_PLUG_ADAPTER_HPP

#include "european_plug_interface.hpp"
#include "american_plug.hpp"

class EuropeanToAmericanPlugAdapter : public AmericanPlug{
	public:
	EuropeanToAmericanPlugAdapter(const EuropeanPlugInterface& european_plug){
		const int european_voltage = european_plug.ConnectToEuropeanSocket();
		voltage_ = (european_voltage > 120 ? 120 : european_voltage);
	}
};

#endif // STRUCTURAL_ADAPTER_EUROPEAN_TO_AMERICAN_PLUG_ADAPTER_HPP
