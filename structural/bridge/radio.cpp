
#include "radio.hpp"

void Radio::TurnOn(){
	is_turned_on_ = true;
}
void Radio::TurnOff(){
	is_turned_on_ = false;
}
bool Radio::IsTurnedOn() const {
	return is_turned_on_;
}

void Radio::VolumeUp(){
	++volume_;
}
void Radio::VolumeDown(){
	--volume_;
}
int Radio::GetVolume() const {
	return volume_;
}
