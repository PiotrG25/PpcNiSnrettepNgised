
#ifndef STRUCTURAL_PROXY_DATABASE_PROXY_HPP
#define STRUCTURAL_PROXY_DATABASE_PROXY_HPP

#include "database.hpp"
#include <memory>
#include <boost/optional.hpp>

class DatabaseProxy : public DatabaseInterface{
public:
	explicit DatabaseProxy(std::unique_ptr<Database>&& service) : service_(std::move(service)) {}
	
	virtual std::vector<User> GetUsers() override {
		if(not users_){
			users_ = service_->GetUsers();
		}
		return users_.value();
	}
	virtual std::vector<User> GetAdultUsers() override {
		if(not adult_users_){
			adult_users_ = service_->GetAdultUsers();
		}
		return adult_users_.value();
	}
	virtual std::vector<User> GetJuvenileUsers() override {
		if(not juvenile_users_){
			juvenile_users_ = service_->GetJuvenileUsers();
		}
		return juvenile_users_.value();
	}
	virtual void InsertUser(const User& user) override {
		users_.reset();
		adult_users_.reset();
		juvenile_users_.reset();
		service_->InsertUser(user);
	}
private:
	std::unique_ptr<Database> service_;
	boost::optional<std::vector<User>> users_;
	boost::optional<std::vector<User>> adult_users_;
	boost::optional<std::vector<User>> juvenile_users_;
};

#endif STRUCTURAL_PROXY_DATABASE_PROXY_HPP
