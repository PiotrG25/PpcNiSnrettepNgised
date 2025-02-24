
#ifndef STRUCTURAL_DECORATOR_DATA_SOURCE
#define STRUCTURAL_DECORATOR_DATA_SOURCE

#include <string>

class DataSource{
	public:
	virtual std::string Read() = 0;
	virtual void Write(std::string data) = 0;
};

#endif // STRUCTURAL_DECORATOR_DATA_SOURCE
