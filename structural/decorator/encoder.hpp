
#ifndef STRUCTURAL_DECORATOR_ENCODER_HPP
#define STRUCTURAL_DECORATOR_ENCODER_HPP

#include "file_handler.hpp"
#include <regex>

class Encoder : public FileHandler{
	public:
	Encoder(std::unique_ptr<DataSource>&& data_source) : FileHandler(std::move(data_source)) {}

	virtual std::string Read() override{
		std::string data = data_source_->Read();
		if(data.size() <= 0){
			return "";
		}
		std::string result = "";
		std::regex pattern(R"((\w)(\d+))");
		
		for (auto it = std::sregex_iterator(data.begin(), data.end(), pattern); it != std::sregex_iterator(); ++it) {
			std::smatch match = *it;
			char c = match[1].str().at(0);
        	std::size_t number = std::stoull(match[2].str());
			result += std::string(number, c);
		}
		
		return result;
	}
	
	virtual void Write(std::string data) override{
		if(data.size() <= 0){
			data_source_->Write("");
			return;
		}
		
		std::string result = "";
		char c = data.at(0);
		size_t count = 1;
		
		for(size_t i = 1; i < data.size(); ++i){
			if(data.at(i) == c){
				++count;
			}else{
				result.push_back(c);
				result += std::to_string(count);
				c = data.at(i);
				count = 1;
			}
		}
		result.push_back(c);
		result += std::to_string(count);

		data_source_->Write(result);
	}
};

#endif // STRUCTURAL_DECORATOR_ENCODER_HPP
