
#ifndef STRUCTURAL_COMPOSITE_LETTER_HPP
#define STRUCTURAL_COMPOSITE_LETTER_HPP

#include "printable.hpp"

class Letter : public Printable{
	public:
	Letter(char c, int size): c_(c), size_(size) {}
	
	virtual void EncodeForPrinter(std::stringstream& ss) const override{
		ss << c_ << size_;
	}
	
	private:
	char c_;
	int size_;
};

#endif // STRUCTURAL_COMPOSITE_LETTER_HPP
