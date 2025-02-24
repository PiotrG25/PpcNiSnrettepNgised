
#ifndef STRUCTURAL_DECORATOR_STRING_DATA_SOURCE
#define STRUCTURAL_DECORATOR_STRING_DATA_SOURCE

#include "data_source.hpp"
#include <memory>

class StringDataSource : public DataSource{
	public:
	StringDataSource(const std::shared_ptr<std::string>& data) : data_(data) {}
	
	virtual std::string Read() override {
		return *data_;
	}
	
	virtual void Write(std::string data) override {
		*data_ = data;
	}
	
	private:
	std::shared_ptr<std::string> data_{};
};

#endif // STRUCTURAL_DECORATOR_STRING_DATA_SOURCE
