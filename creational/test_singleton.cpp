
#include <gtest/gtest.h>
#include <iostream>
#include "pointer_singleton.hpp"
#include "meyers_singleton.hpp"

TEST(TestPointerSingleton, InstanceIsSame) {
	PointerSingleton* const instance1 = PointerSingleton::GetInstance();
	PointerSingleton* const instance2 = PointerSingleton::GetInstance();
	EXPECT_EQ(instance1, instance2);
}

TEST(TestPointerSingleton, TwoInstancePointersWorkOnTheSameResource) {
	PointerSingleton* const instance1 = PointerSingleton::GetInstance();
	int expected_value = 4;
	instance1->SetValue(expected_value);
	PointerSingleton* const instance2 = PointerSingleton::GetInstance();
	EXPECT_EQ(expected_value, instance2->GetValue());
}

TEST(TestMeyersSingleton, InstanceIsSame) {
	const MeyersSingleton& instance1 = MeyersSingleton::GetInstance();
	const MeyersSingleton& instance2 = MeyersSingleton::GetInstance();
	EXPECT_EQ(&instance1, &instance2);
}

TEST(TestMeyersSingleton, TwoInstancePointersWorkOnTheSameResource) {
	MeyersSingleton& instance1 = MeyersSingleton::GetInstance();
	int expected_value = 4;
	instance1.SetValue(expected_value);
	MeyersSingleton& instance2 = MeyersSingleton::GetInstance();
	EXPECT_EQ(expected_value, instance2.GetValue());
}