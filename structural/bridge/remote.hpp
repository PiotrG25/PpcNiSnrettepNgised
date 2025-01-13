
#ifndef STRUCTURAL_BRIDGE_REMOTE_HPP
#define STRUCTURAL_BRIDGE_REMOTE_HPP

#include "device.hpp"
#include <memory>

class Remote{
	public:
	Remote(const std::shared_ptr<Device>& device) : device_(device) {}
	
	void SwitchPower(){
		if(device_->IsTurnedOn()){
			device_->TurnOff();
		}else{
			device_->TurnOn();
		}
	}
	
	void VolumeUp(){
		device_->VolumeUp();
	}
	
	void VolumeDown(){
		device_->VolumeDown();
	}
	
	void BrightnessUp(){
		device_->BrightnessUp();
	}
	
	void BrightnessDown(){
		device_->BrightnessDown();
	}
	
	private:
	std::shared_ptr<Device> device_;
};

#endif // STRUCTURAL_BRIDGE_REMOTE_HPP
