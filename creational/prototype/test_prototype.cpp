
#include <gtest/gtest.h>
#include "test_prototype.hpp"

TEST(TestCopyConstructor, ExpectCopyOfMembers){
	A* a = new A(1);
	A* aa = new A(*a);
	
	EXPECT_EQ(1, a->i_);
	EXPECT_EQ(1, aa->i_);
	
	a->i_ = 2;
	EXPECT_EQ(2, a->i_);
	EXPECT_EQ(1, aa->i_);
	
	delete a;
	delete aa;
}

TEST(TestCopyConstructor, ExpectCopyOfMembersWorkWithPolymorphism){
	A* ab1 = new B(1, 2);
	B* bb1 = static_cast<B*>(ab1);
	
	A* ab2 = new B(*bb1);
	B* bb2 = static_cast<B*>(ab2);
	
	EXPECT_EQ(1, ab1->i_);
	// EXPECT_EQ(2, ab1->j_); // no j_ in class A
	EXPECT_EQ(1, ab2->i_);
	// EXPECT_EQ(2, ab2->j_); // no j_ in class A
	
	EXPECT_EQ(1, bb1->i_);
	EXPECT_EQ(2, bb1->j_);
	EXPECT_EQ(1, bb2->i_);
	EXPECT_EQ(2, bb2->j_);
	
	ab1->i_ = 3;
	
	EXPECT_EQ(3, ab1->i_);
	// EXPECT_EQ(2, ab1->j_); // no j_ in class A
	EXPECT_EQ(1, ab2->i_);
	// EXPECT_EQ(2, ab2->j_); // no j_ in class A
	
	EXPECT_EQ(3, bb1->i_);
	EXPECT_EQ(2, bb1->j_);
	EXPECT_EQ(1, bb2->i_);
	EXPECT_EQ(2, bb2->j_);
	
	delete ab1;
	delete ab2;
}

TEST(TestPrototype, ExpectCopyOfMembersWorkWithPolymorphism){
	Prototype* pb1 = new B(1, 2);
	Prototype* pb2 = pb1->clone();
	
	B* bb1 = static_cast<B*>(pb1);
	B* bb2 = static_cast<B*>(pb2);

	EXPECT_EQ(1, bb1->i_);
	EXPECT_EQ(2, bb1->j_);
	EXPECT_EQ(1, bb2->i_);
	EXPECT_EQ(2, bb2->j_);
	
	bb1->i_ = 3;
	
	EXPECT_EQ(3, bb1->i_);
	EXPECT_EQ(2, bb1->j_);
	EXPECT_EQ(1, bb2->i_);
	EXPECT_EQ(2, bb2->j_);
	
	delete pb1;
	delete pb2;
}
