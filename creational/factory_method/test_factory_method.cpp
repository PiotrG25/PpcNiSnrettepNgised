
#include <gtest/gtest.h>
#include "car_factory.hpp"

TEST(TestFactoryMethod, ExpectSuperPartsInSuperCarFromCarFactory){
	CarFactory factory;
	auto car = factory.MakeCar(CarFactory::CarType::SuperCar);
	
	const auto& engine = car->GetEngine();
	EXPECT_EQ(engine->GetFuelEfficiency(), Engine::FuelEfficiency::Low);
	EXPECT_EQ(engine->GetHorsePower(), static_cast<std::uint8_t>(800));
	EXPECT_EQ(engine->GetTopSpeed(), static_cast<std::uint8_t>(400));
	
	const auto& body = car->GetBody();
	
	EXPECT_FLOAT_EQ(body->GetDragCoefficient(), 0.28F);	
	EXPECT_EQ(body->GetDesign(), Body::Design::Beautiful);	
}

TEST(TestFactoryMethod, ExpectStandardPartsInStandardCarFromCarFactory){
	CarFactory factory;
	auto car = factory.MakeCar(CarFactory::CarType::StandardCar);
	
	const auto& engine = car->GetEngine();
	EXPECT_EQ(engine->GetFuelEfficiency(), Engine::FuelEfficiency::High);
	EXPECT_EQ(engine->GetHorsePower(), static_cast<std::uint8_t>(200));
	EXPECT_EQ(engine->GetTopSpeed(), static_cast<std::uint8_t>(200));
	
	const auto& body = car->GetBody();
	
	EXPECT_FLOAT_EQ(body->GetDragCoefficient(), 0.40F);	
	EXPECT_EQ(body->GetDesign(), Body::Design::Standard);	
}
