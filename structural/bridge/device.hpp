
#ifndef STRUCTURAL_BRIDGE_DEVICE_HPP
#define STRUCTURAL_BRIDGE_DEVICE_HPP

class Device{
	public:
	virtual void TurnOn() = 0;
	virtual void TurnOff() = 0;
	virtual bool IsTurnedOn() const = 0;
	
	virtual void VolumeUp() = 0;
	virtual void VolumeDown() = 0;
	virtual int GetVolume() const = 0;
};

#endif // STRUCTURAL_BRIDGE_DEVICE_HPP
