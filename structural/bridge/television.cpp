
#include "television.hpp"

void Television::TurnOn(){
	is_turned_on_ = true;
}
void Television::TurnOff(){
	is_turned_on_ = false;
}
bool Television::IsTurnedOn() const {
	return is_turned_on_;
}

void Television::VolumeUp(){
	++volume_;
}
void Television::VolumeDown(){
	--volume_;
}
int Television::GetVolume() const {
	return volume_;
}

void Television::BrightnessUp() {
	++brightness_;
}
void Television::BrightnessDown() {
	--brightness_;
}
int Television::GetBrightness() const {
	return brightness_;
}
