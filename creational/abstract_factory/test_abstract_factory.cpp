
#include <gtest/gtest.h>

#include "super_car_parts_factory.hpp"
#include "standard_car_parts_factory.hpp"

TEST(TestAbstractFactory, ExpectSuperEngineCharacteristicsFromSuperCarPartsFactory){
	std::unique_ptr<CarPartsFactory> factory = std::make_unique<SuperCarPartsFactory>();
	auto engine = factory->MakeEngine();
	
	EXPECT_EQ(engine->GetFuelEfficiency(), Engine::FuelEfficiency::Low);	
	EXPECT_EQ(engine->GetHorsePower(), static_cast<std::uint8_t>(800));	
	EXPECT_EQ(engine->GetTopSpeed(), static_cast<std::uint8_t>(400));	
}

TEST(TestAbstractFactory, ExpectSuperBodyCharacteristicsFromSuperCarPartsFactory){
	std::unique_ptr<CarPartsFactory> factory = std::make_unique<SuperCarPartsFactory>();
	auto body = factory->MakeBody();
	
	EXPECT_FLOAT_EQ(body->GetDragCoefficient(), 0.28F);	
	EXPECT_EQ(body->GetDesign(), Body::Design::Beautiful);	
}

TEST(TestAbstractFactory, ExpectStandardEngineCharacteristicsFromStandardCarPartsFactory){
	std::unique_ptr<CarPartsFactory> factory = std::make_unique<StandardCarPartsFactory>();
	auto engine = factory->MakeEngine();
	
	EXPECT_EQ(engine->GetFuelEfficiency(), Engine::FuelEfficiency::High);	
	EXPECT_EQ(engine->GetHorsePower(), static_cast<std::uint8_t>(200));	
	EXPECT_EQ(engine->GetTopSpeed(), static_cast<std::uint8_t>(200));	
}

TEST(TestAbstractFactory, ExpectStandardBodyCharacteristicsFromStandardCarPartsFactory){
	std::unique_ptr<CarPartsFactory> factory = std::make_unique<StandardCarPartsFactory>();
	auto body = factory->MakeBody();
	
	EXPECT_FLOAT_EQ(body->GetDragCoefficient(), 0.40F);	
	EXPECT_EQ(body->GetDesign(), Body::Design::Standard);	
}