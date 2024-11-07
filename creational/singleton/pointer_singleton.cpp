
#include "creational/singleton/pointer_singleton.hpp"

PointerSingleton* PointerSingleton::instance_ = nullptr;

PointerSingleton* const PointerSingleton::GetInstance(){
	if(instance_ == nullptr){
		instance_ = new PointerSingleton();
	}
	return instance_;
}
void PointerSingleton::SetValue(int value){
	value_ = value;
}
int PointerSingleton::GetValue() const{
	return value_;
}