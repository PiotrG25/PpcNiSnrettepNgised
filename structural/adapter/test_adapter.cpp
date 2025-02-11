
#include <gtest/gtest.h>
#include "european_to_american_plug_adapter.hpp"
#include "american_to_european_plug_adapter.hpp"

TEST(AdapterTest, ExpectAmericanToEuropeanPlugAdapterReturnCorrectVoltage){
	AmericanPlug plug(120);
	AmericanToEuropeanPlugAdapter adapter(plug);
	EXPECT_EQ(adapter.ConnectToEuropeanSocket(), 120);
}

TEST(AdapterTest, ExpectEuropeanToAmericanPlugAdapterReturnCorrectVoltage){
	EuropeanPlug plug1(100);
	EuropeanToAmericanPlugAdapter adapter1(plug1);
	EXPECT_EQ(adapter1.ConnectToAmericanSocket(), 100);
	
	EuropeanPlug plug2(200);
	EuropeanToAmericanPlugAdapter adapter2(plug2);
	EXPECT_EQ(adapter2.ConnectToAmericanSocket(), 120);
}
