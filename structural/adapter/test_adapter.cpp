
#include <gtest/gtest.h>
#include "european_to_american_plug_adapter.hpp"
#include "american_to_european_plug_adapter.hpp"

TEST(AdapterTest, ExpectAmericanToEuropeanPlugAdapterReturnAmericanPlugId){
	AmericanPlug plug(12);
	AmericanToEuropeanPlugAdapter adapter(plug);
	EXPECT_EQ(adapter.ConnectToEuropeanSocket(), 12);
}

TEST(AdapterTest, ExpectEuropeanToAmericanPlugAdapterReturnEuropeanPlugId){
	EuropeanPlug plug(34);
	EuropeanToAmericanPlugAdapter adapter(plug);
	EXPECT_EQ(adapter.ConnectToAmericanSocket(), 34);
}
