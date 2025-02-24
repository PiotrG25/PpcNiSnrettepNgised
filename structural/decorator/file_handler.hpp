
#ifndef STRUCTURAL_DECORATOR_FILE_HANDLER_HPP
#define STRUCTURAL_DECORATOR_FILE_HANDLER_HPP

#include "data_source.hpp"
#include <memory>

class FileHandler : public DataSource{
	public:
	FileHandler(std::unique_ptr<DataSource>&& data_source) : data_source_(std::move(data_source)) {}
	
	protected:
	std::unique_ptr<DataSource> data_source_{nullptr};
};

#endif // STRUCTURAL_DECORATOR_FILE_HANDLER_HPP
