
#include "creational/singleton/pointer_singleton.hpp"

std::unique_ptr<PointerSingleton> PointerSingleton::instance_ = nullptr;
std::once_flag PointerSingleton::initialization_flag_;

std::unique_ptr<PointerSingleton>& PointerSingleton::GetInstance(){
	std::call_once(initialization_flag_, [](){
		instance_ = std::unique_ptr<PointerSingleton>(new PointerSingleton());
	});
	return instance_;
}
const std::unique_ptr<PointerSingleton>& PointerSingleton::GetConstInstance(){
	std::call_once(initialization_flag_, [](){
		instance_ = std::unique_ptr<PointerSingleton>(new PointerSingleton());
	});
	return instance_;
}
void PointerSingleton::SetValue(int value){
	value_ = value;
}
int PointerSingleton::GetValue() const{
	return value_;
}