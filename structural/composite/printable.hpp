
#ifndef STRUCTURAL_COMPOSITE_PRINTABLE_HPP
#define STRUCTURAL_COMPOSITE_PRINTABLE_HPP

#include <sstream>

class Printable{
	public:
	virtual void EncodeForPrinter(std::stringstream&) const = 0;
};

#endif // STRUCTURAL_COMPOSITE_PRINTABLE_HPP
