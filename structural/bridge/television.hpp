
#ifndef STRUCTURAL_BRIDGE_TELEVISION_HPP
#define STRUCTURAL_BRIDGE_TELEVISION_HPP

#include "device.hpp"

class Television : public Device{
	public:
	virtual void TurnOn() override;
	virtual void TurnOff() override;
	virtual bool IsTurnedOn() const override;
	
	virtual void VolumeUp() override;
	virtual void VolumeDown() override;
	virtual int GetVolume() const override;
	
	private:
	bool is_turned_on_{false};
	int volume_{20};
	int brightness_{80};
};

#endif // STRUCTURAL_BRIDGE_TELEVISION_HPP
