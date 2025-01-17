
#ifndef STRUCTURAL_ADAPTER_EUROPEAN_TO_AMERICAN_PLUG_ADAPTER_HPP
#define STRUCTURAL_ADAPTER_EUROPEAN_TO_AMERICAN_PLUG_ADAPTER_HPP

#include "european_plug_interface.hpp"
#include "american_plug.hpp"

class EuropeanToAmericanPlugAdapter : public AmericanPlug{
	public:
	EuropeanToAmericanPlugAdapter(const EuropeanPlugInterface& european_plug) : AmericanPlug(european_plug.ConnectToEuropeanSocket()) {}
};

#endif // STRUCTURAL_ADAPTER_EUROPEAN_TO_AMERICAN_PLUG_ADAPTER_HPP
