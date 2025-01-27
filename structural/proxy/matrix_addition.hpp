
#ifndef STRUCTURAL_PROXY_MATRIX_ADDITION_HPP
#define STRUCTURAL_PROXY_MATRIX_ADDITION_HPP

#include "matrix_interface.hpp"
#include <memory>

template<std::size_t M, std::size_t N>
class MatrixAddition : public MatrixInterface<M, N>{
	public:
	MatrixAddition(const std::shared_ptr<MatrixInterface<M, N>>& a) : a_(a) {}
	MatrixAddition(const std::shared_ptr<MatrixInterface<M, N>>& a, const std::shared_ptr<MatrixInterface<M, N>>& b) : a_(a), b_(b) {}
	
	virtual ValuesType GetValues() override {
		if(values_ != nullptr){
			return *values_;
		}
		
		if(b_ == nullptr){
			values_ = std::make_unique<ValuesType>(a_->GetValues());
			a_ = nullptr;
			return *values_;
		}
		
		auto a_values = a_->GetValues();
		auto b_values = b_->GetValues();
		values_ = std::make_unique<ValuesType>();
		
		for(std::size_t i = 0; i < GetRows(); ++i){
			for(std::size_t j = 0; j < GetColumns(); ++j){
				values_->at(i).at(j) = a_values.at(i).at(j) + b_values.at(i).at(j);
			}
		}
		
		a_ = nullptr;
		b_ = nullptr;
		return *values_;
	}
	
	private:
	std::shared_ptr<MatrixInterface> a_{nullptr};
	std::shared_ptr<MatrixInterface> b_{nullptr};
	std::unique_ptr<ValuesType> values_{nullptr};
};

template<std::size_t M, std::size_t N>
std::shared_ptr<MatrixAddition<M, N>> operator+ (
	const std::shared_ptr<MatrixInterface<M, N>>& a,
	const std::shared_ptr<MatrixInterface<M, N>>& b){
	return std::make_shared<MatrixAddition<M, N>>(a, b);
}

#endif // STRUCTURAL_PROXY_MATRIX_ADDITION_HPP