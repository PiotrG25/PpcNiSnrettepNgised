
#ifndef STRUCTURAL_ADAPTER_AMERICAN_TO_EUROPEAN_PLUG_ADAPTER_HPP
#define STRUCTURAL_ADAPTER_AMERICAN_TO_EUROPEAN_PLUG_ADAPTER_HPP

#include "european_plug.hpp"
#include "american_plug_interface.hpp"

class AmericanToEuropeanPlugAdapter : public EuropeanPlug{
	public:
	AmericanToEuropeanPlugAdapter(const AmericanPlugInterface& american_plug) : EuropeanPlug(american_plug.ConnectToAmericanSocket()) {}
};

#endif // STRUCTURAL_ADAPTER_AMERICAN_TO_EUROPEAN_PLUG_ADAPTER_HPP
