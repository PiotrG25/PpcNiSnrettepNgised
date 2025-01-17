
#ifndef STRUCTURAL_COMPOSITE_WHITESPACE_HPP
#define STRUCTURAL_COMPOSITE_WHITESPACE_HPP

#include "printable.hpp"

class Whitespace : public Printable{
	public:
	enum class WhitespaceType {SPACE, NEW_LINE, TAB};
	
	Whitespace(WhitespaceType type) : type_(type){}
	
	virtual void EncodeForPrinter(std::stringstream& ss) const override{
		if(type_ == WhitespaceType::SPACE){
			ss << " ";
		}else if(type_ == WhitespaceType::NEW_LINE){
			ss << "\n";
		}else if(type_ == WhitespaceType::TAB){
			ss << "    ";
		}
	}
	private:
	WhitespaceType type_;
};

#endif // STRUCTURAL_COMPOSITE_WHITESPACE_HPP
