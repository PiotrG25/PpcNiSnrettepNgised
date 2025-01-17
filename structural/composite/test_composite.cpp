
#include <gtest/gtest.h>
#include "paragraph.hpp"
#include "word.hpp"
#include "whitespace.hpp"

TEST(CompositeTest, ExpectToReceiveACorrectStringComposedFromMultiplePrintableComponents){
	std::stringstream ss;
	Paragraph p;
	
	p.AddPrintable(std::make_unique<Letter>('A', 14));
	
	p.AddPrintable(std::make_unique<Whitespace>(Whitespace::WhitespaceType::SPACE));
	
	std::unique_ptr<Word> w = std::make_unique<Word>();
	w->AddLetter(std::make_unique<Letter>('C', 14));
	w->AddLetter(std::make_unique<Letter>('A', 14));
	w->AddLetter(std::make_unique<Letter>('T', 14));
	p.AddPrintable(std::move(w));
	
	p.AddPrintable(std::make_unique<Whitespace>(Whitespace::WhitespaceType::SPACE));
	
	w = std::make_unique<Word>();
	w->AddLetter(std::make_unique<Letter>('A', 8));
	w->AddLetter(std::make_unique<Letter>('N', 8));
	w->AddLetter(std::make_unique<Letter>('D', 8));
	p.AddPrintable(std::move(w));
	
	p.AddPrintable(std::make_unique<Whitespace>(Whitespace::WhitespaceType::NEW_LINE));
	
	p.AddPrintable(std::make_unique<Letter>('A', 10));
	
	p.AddPrintable(std::make_unique<Whitespace>(Whitespace::WhitespaceType::TAB));
	
	w = std::make_unique<Word>();
	w->AddLetter(std::make_unique<Letter>('D', 20));
	w->AddLetter(std::make_unique<Letter>('O', 20));
	w->AddLetter(std::make_unique<Letter>('G', 20));
	p.AddPrintable(std::move(w));
	
	p.EncodeForPrinter(ss);
	std::string expected_result = "A14 C14A14T14 A8N8D8\nA10    D20O20G20";
	EXPECT_EQ(expected_result, ss.str());
}
