
#ifndef STRUCTURAL_PROXY_MATRIX_INTERFACE_HPP
#define STRUCTURAL_PROXY_MATRIX_INTERFACE_HPP

#include <cmath>
#include <array>

template<std::size_t M, std::size_t N>
class MatrixInterface{
	public:
	using ValuesType = std::array<std::array<int, N>, M>;
	
	virtual ValuesType GetValues() = 0;
	
	std::size_t GetRows(){
		return M;
	}
	
	std::size_t GetColumns(){
		return N;
	}
};

#endif // STRUCTURAL_PROXY_MATRIX_INTERFACE_HPP