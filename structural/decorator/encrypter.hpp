
#ifndef STRUCTURAL_DECORATOR_ENCRYPTER_HPP
#define STRUCTURAL_DECORATOR_ENCRYPTER_HPP

#include "file_handler.hpp"

class Encrypter : public FileHandler{
	public:
	Encrypter(std::unique_ptr<DataSource>&& data_source) : FileHandler(std::move(data_source)) {}
	
	virtual std::string Read() override{
		std::string data = data_source_->Read();
		std::string result = "";
		for(char c : data){
			if('a' <= c && c <= 'z'){
				char cc = c - 3;
				if(cc < 'a'){
					cc = cc + 'z' - 'a' + 1;
				}
				result += cc;
			}else if('A' <= c && c <= 'Z'){
				char cc = c - 3;
				if(cc < 'A'){
					cc = cc + 'Z' - 'A' + 1;
				}
				result += cc;
			}else{
				result += c;
			}
		}
		return result;
	}
	
	virtual void Write(std::string data) override{
		std::string result = "";
		for(char c : data){
			if('a' <= c && c <= 'z'){
				char cc = c + 3;
				if(cc > 'z'){
					cc = cc - 'z' + 'a' - 1;
				}
				result += cc;
			}else if('A' <= c && c <= 'Z'){
				char cc = c + 3;
				if(cc > 'Z'){
					cc = cc - 'Z' + 'A' - 1;
				}
				result += cc;
			}else{
				result += c;
			}
		}
		data_source_->Write(result);
	}
};

#endif // STRUCTURAL_DECORATOR_ENCRYPTER_HPP
