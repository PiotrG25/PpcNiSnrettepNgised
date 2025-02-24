
#include <gtest/gtest.h>
#include <iostream>
#include "string_data_source.hpp"
#include "encrypter.hpp"
#include "encoder.hpp"

TEST(DecoratorTest, GivenEncodedStringExpectItToBeDecodedCorrectly){
	std::shared_ptr<std::string> data = std::make_unique<std::string>("A3B2C1D3F15");
	std::unique_ptr<StringDataSource> string_data_source = std::make_unique<StringDataSource>(data);
	std::unique_ptr<Encoder> encoder = std::make_unique<Encoder>(std::move(string_data_source));
	
	EXPECT_EQ("AAABBCDDDFFFFFFFFFFFFFFF", encoder->Read());
}

TEST(DecoratorTest, GivenStringExpectEncodingToBeCorrect){
	std::shared_ptr<std::string> data = std::make_unique<std::string>("");
	std::unique_ptr<StringDataSource> string_data_source = std::make_unique<StringDataSource>(data);
	std::unique_ptr<Encoder> encoder = std::make_unique<Encoder>(std::move(string_data_source));
	encoder->Write("AAABBCDDDFFFFFFFFFFFFFFF");
	
	EXPECT_EQ("A3B2C1D3F15", *data);
}

TEST(DecoratorTest, GivenStringExpectItToBeDecryptedCorrectly){
	std::shared_ptr<std::string> data = std::make_unique<std::string>("DdEeFfAaBbCc");
	std::unique_ptr<StringDataSource> string_data_source = std::make_unique<StringDataSource>(data);
	std::unique_ptr<Encrypter> encrypter = std::make_unique<Encrypter>(std::move(string_data_source));
	
	EXPECT_EQ("AaBbCcXxYyZz", encrypter->Read());
}

TEST(DecoratorTest, GivenStringExpectEncryptionToBeCorrect){
	std::shared_ptr<std::string> data = std::make_unique<std::string>("");
	std::unique_ptr<StringDataSource> string_data_source = std::make_unique<StringDataSource>(data);
	std::unique_ptr<Encrypter> encrypter = std::make_unique<Encrypter>(std::move(string_data_source));
	encrypter->Write("AaBbCcXxYyZz");
	
	EXPECT_EQ("DdEeFfAaBbCc", *data);
}

TEST(DecoratorTest, GivenStringExpectDecoratorToEncodeAndEncryptCorrectly){
	std::shared_ptr<std::string> data = std::make_unique<std::string>("");
	std::unique_ptr<StringDataSource> string_data_source = std::make_unique<StringDataSource>(data);
	std::unique_ptr<Encrypter> encrypter = std::make_unique<Encrypter>(std::move(string_data_source));
	std::unique_ptr<Encoder> encoder = std::make_unique<Encoder>(std::move(encrypter));
	encoder->Write("AAAaYYyyyyyyyyyyZ");
	
	EXPECT_EQ("D3d1B2b10C1", *data);
	EXPECT_EQ("AAAaYYyyyyyyyyyyZ", encoder->Read());
}
