
#include <gtest/gtest.h>
#include "creational/singleton/pointer_singleton.hpp"
#include "creational/singleton/meyers_singleton.hpp"

TEST(TestPointerSingleton, InstanceIsSame) {
	const std::unique_ptr<PointerSingleton>& instance1 = PointerSingleton::GetConstInstance();
	const std::unique_ptr<PointerSingleton>& instance2 = PointerSingleton::GetConstInstance();
	EXPECT_EQ(instance1.get(), instance2.get());
}

TEST(TestPointerSingleton, TwoInstancePointersWorkOnTheSameResource) {
	std::unique_ptr<PointerSingleton>& instance1 = PointerSingleton::GetInstance();
	int expected_value = 4;
	instance1->SetValue(expected_value);
	std::unique_ptr<PointerSingleton>& instance2 = PointerSingleton::GetInstance();
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