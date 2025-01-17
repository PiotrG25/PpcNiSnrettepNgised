
#ifndef STRUCTURAL_COMPOSITE_WORD_HPP
#define STRUCTURAL_COMPOSITE_WORD_HPP

#include "letter.hpp"
#include <vector>

class Word : public Printable{
	public:
	virtual void EncodeForPrinter(std::stringstream& ss) const override{
		for(const auto& l : letters_){
			l->EncodeForPrinter(ss);
		}
	}
	
	void AddLetter(std::unique_ptr<Letter>&& letter){
		letters_.push_back(std::move(letter));
	}
	
	private:
	std::vector<std::unique_ptr<Letter>> letters_{};
};

#endif // STRUCTURAL_COMPOSITE_WORD_HPP
