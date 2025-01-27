
#include <gtest/gtest.h>
#include "matrix.hpp"
#include "matrix_addition.hpp"

TEST(TestProxy, ExpectMatrixAdditionToReturnCorrectValuesAfterAddition){
	std::array<int, 2> a1 = {1, 2}, a2 = {3, 4}, a3 = {5, 6};
	std::array<std::array<int, 2>, 3> aa = {a1, a2, a3};
	
	std::shared_ptr<MatrixInterface<3, 2>> m1 = std::make_shared<Matrix<3, 2>>(aa);
	std::shared_ptr<MatrixInterface<3, 2>> m2 = std::make_shared<Matrix<3, 2>>(aa);
	
	std::shared_ptr<MatrixInterface<3, 2>> mm = m1 + m2;
	auto values = mm->GetValues();
	
	EXPECT_EQ(2, values.at(0).at(0));
	EXPECT_EQ(4, values.at(0).at(1));
	EXPECT_EQ(6, values.at(1).at(0));
	EXPECT_EQ(8, values.at(1).at(1));
	EXPECT_EQ(10, values.at(2).at(0));
	EXPECT_EQ(12, values.at(2).at(1));
}
