
#ifndef STRUCTURAL_ADAPTER_AMERICAN_TO_EUROPEAN_PLUG_ADAPTER_HPP
#define STRUCTURAL_ADAPTER_AMERICAN_TO_EUROPEAN_PLUG_ADAPTER_HPP

#include "american_plug.hpp"
#include "european_plug.hpp"

class AmericanToEuropeanPlugAdapter : public EuropeanPlug{
	public:
	AmericanToEuropeanPlugAdapter(const AmericanPlug& american_plug) : EuropeanPlug(american_plug.ConnectToAmericanSocket()) {}
};

#endif // STRUCTURAL_ADAPTER_AMERICAN_TO_EUROPEAN_PLUG_ADAPTER_HPP
