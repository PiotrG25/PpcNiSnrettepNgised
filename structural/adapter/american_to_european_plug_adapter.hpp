
#ifndef STRUCTURAL_ADAPTER_AMERICAN_TO_EUROPEAN_PLUG_ADAPTER_HPP
#define STRUCTURAL_ADAPTER_AMERICAN_TO_EUROPEAN_PLUG_ADAPTER_HPP

#include "european_plug.hpp"
#include "american_plug_interface.hpp"

class AmericanToEuropeanPlugAdapter : public EuropeanPlug{
	public:
	AmericanToEuropeanPlugAdapter(const AmericanPlugInterface& american_plug){
		const int american_voltage = american_plug.ConnectToAmericanSocket();
		voltage_ = (american_voltage > 230 ? 230 : american_voltage);
	}
};

#endif // STRUCTURAL_ADAPTER_AMERICAN_TO_EUROPEAN_PLUG_ADAPTER_HPP
