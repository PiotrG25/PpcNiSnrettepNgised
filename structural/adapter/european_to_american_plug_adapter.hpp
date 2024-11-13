
#ifndef STRUCTURAL_ADAPTER_EUROPEAN_TO_AMERICAN_PLUG_ADAPTER_HPP
#define STRUCTURAL_ADAPTER_EUROPEAN_TO_AMERICAN_PLUG_ADAPTER_HPP

#include "american_plug.hpp"
#include "european_plug.hpp"

class EuropeanToAmericanPlugAdapter : public AmericanPlug{
	public:
	EuropeanToAmericanPlugAdapter(const EuropeanPlug& european_plug) : AmericanPlug(european_plug.ConnectToEuropeanSocket()) {}
};

#endif // STRUCTURAL_ADAPTER_EUROPEAN_TO_AMERICAN_PLUG_ADAPTER_HPP
