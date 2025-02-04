
#ifndef STRUCTURAL_BRIDGE_RADIO_HPP
#define STRUCTURAL_BRIDGE_RADIO_HPP

#include "device.hpp"

class Radio : public Device{
	public:
	virtual void TurnOn() override;
	virtual void TurnOff() override;
	virtual bool IsTurnedOn() const override;
	
	virtual void VolumeUp() override;
	virtual void VolumeDown() override;
	virtual int GetVolume() const override;
	
	private:
	bool is_turned_on_{false};
	int volume_{10};
};

#endif // STRUCTURAL_BRIDGE_RADIO_HPP
