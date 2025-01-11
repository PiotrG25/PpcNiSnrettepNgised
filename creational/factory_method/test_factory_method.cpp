
#include <gtest/gtest.h>
#include "car_factory.hpp"

TEST(TestFactoryMethod, ExpectSuperPartsInSuperCarFromCarFactory){
	auto car = MakeCar(CarType::SuperCar);
	
	EXPECT_EQ(car->GetFuelEfficiency(), Car::FuelEfficiency::Low);
	EXPECT_EQ(car->GetBodyDesign(), Car::BodyDesign::Beautiful);
}

TEST(TestFactoryMethod, ExpectStandardPartsInStandardCarFromCarFactory){
	auto car = MakeCar(CarType::StandardCar);
	
	EXPECT_EQ(car->GetFuelEfficiency(), Car::FuelEfficiency::High);
	EXPECT_EQ(car->GetBodyDesign(), Car::BodyDesign::Standard);
}
