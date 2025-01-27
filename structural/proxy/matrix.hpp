
#ifndef STRUCTURAL_PROXY_MATRIX_HPP
#define STRUCTURAL_PROXY_MATRIX_HPP

#include "matrix_interface.hpp"

template<std::size_t M, std::size_t N>
class Matrix : public MatrixInterface<M, N>{
	public:
	Matrix(ValuesType values) : values_(values) {}
	
	ValuesType GetValues() override {
		return values_;
	}
	
	private:
	ValuesType values_;
};

#endif // STRUCTURAL_PROXY_MATRIX_HPP