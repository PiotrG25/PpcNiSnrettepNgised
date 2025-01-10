
#include <gtest/gtest.h>
#include "waiter.hpp"
#include "client.hpp"

TEST(TestPrototype, ExpectClientSatisfied){
	Waiter w;
	Client c1, c2, c3;
	
	c1.OrderVege(w);
	c2.OrderDiavola(w);
	c3.OrderSameAsThePreviousPerson(w);
	EXPECT_TRUE(c3.IsSatisfied());
}

TEST(TestPrototype, ExpectClientDissatisfied){
	Waiter w;
	Client c1, c2, c3;
	
	c1.OrderDiavola(w);
	c2.OrderVege(w);
	c3.OrderSameAsThePreviousPerson(w);
	EXPECT_FALSE(c3.IsSatisfied());
}
