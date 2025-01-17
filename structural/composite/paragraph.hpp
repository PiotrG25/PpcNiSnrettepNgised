
#ifndef STRUCTURAL_COMPOSITE_PARAGRAPH_HPP
#define STRUCTURAL_COMPOSITE_PARAGRAPH_HPP

#include "printable.hpp"
#include <vector>

class Paragraph : public Printable{
	public:
	virtual void EncodeForPrinter(std::stringstream& ss) const override{
		for(const auto& p : printables_){
			p->EncodeForPrinter(ss);
		}
	}
	
	void AddPrintable(std::unique_ptr<Printable>&& printable){
		printables_.push_back(std::move(printable));
	}
	
	private:
	std::vector<std::unique_ptr<Printable>> printables_{};
};

#endif // STRUCTURAL_COMPOSITE_PARAGRAPH_HPP
