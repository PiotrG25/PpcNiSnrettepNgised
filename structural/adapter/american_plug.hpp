
#ifndef STRUCTURAL_ADAPTER_AMERICAN_PLUG_HPP
#define STRUCTURAL_ADAPTER_AMERICAN_PLUG_HPP

#include "american_plug_interface.hpp"

class AmericanPlug : public AmericanPlugInterface{
	public:
	AmericanPlug(int id) : id_(id) {}
	virtual int ConnectToAmericanSocket() const override{
		return id_;
	}
	private:
	int id_;
};

#endif // STRUCTURAL_ADAPTER_AMERICAN_PLUG_HPP
