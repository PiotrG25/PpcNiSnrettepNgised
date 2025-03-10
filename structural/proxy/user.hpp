
#ifndef STRUCTURAL_PROXY_USER_HPP
#define STRUCTURAL_PROXY_USER_HPP

struct User{
	User() = default;
	User(unsigned int id_, const std::string& name_, unsigned int age_): id(id_), name(name_), age(age_) {}
	User(const std::string& name_, unsigned int age_): name(name_), age(age_) {}
	
	unsigned int id;
	std::string name;
	unsigned int age;
};

#endif STRUCTURAL_PROXY_USER_HPP
