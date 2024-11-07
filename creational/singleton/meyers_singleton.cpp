
#include "creational/singleton/meyers_singleton.hpp"

MeyersSingleton& MeyersSingleton::GetInstance(){
	static MeyersSingleton instance_;
	return instance_;
}

void MeyersSingleton::SetValue(int value){
	value_ = value;
}
int MeyersSingleton::GetValue() const{
	return value_;
}