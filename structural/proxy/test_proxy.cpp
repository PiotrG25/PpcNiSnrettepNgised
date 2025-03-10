
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "database_proxy.hpp"

namespace{
	std::vector<User> GetUsers(){
		return {
			{0U, "Adam", 10},
			{1U, "Bernard", 35},
			{2U, "Cicero", 63},
			{3U, "Daniel", 40},
			{4U, "Ezekiel", 16}
		};
	}
	
	std::vector<User> GetAdultUsers(){
		auto users = GetUsers();
		std::vector<User> adult_users;
		std::copy_if(users.cbegin(), users.cend(), std::back_inserter(adult_users), [](const User& user){ return user.age >= 18; });
		return adult_users;
	}
	
	std::vector<User> GetJuvenileUsers(){
		auto users = GetUsers();
		std::vector<User> juvenile_users; 
		std::copy_if(users.cbegin(), users.cend(), std::back_inserter(juvenile_users), [](const User& user){ return user.age < 18; });
		return juvenile_users;
	}
	
	std::unordered_map<unsigned int, User> GetUserMap(const std::vector<User>& users){
		std::unordered_map<unsigned int, User> mapping;
		for(const User& u : users){
			mapping.insert({u.id, u});
		}
		return mapping;
	}
	
	void ExpectUsers(const std::vector<User>& expected_users, const std::vector<User>& users){
		auto users_mapping = GetUserMap(expected_users);
		EXPECT_EQ(expected_users.size(), users.size());
		for(const auto& u : users){
			auto it = users_mapping.find(u.id);
			ASSERT_TRUE(it != users_mapping.cend());
			EXPECT_EQ(users_mapping.at(u.id).name, u.name);
			EXPECT_EQ(users_mapping.at(u.id).age, u.age);
		}
	}
	
	class DatabaseMock : public Database{
		public:
		MOCK_METHOD(std::vector<User>, GetUsers, (), (override));
		MOCK_METHOD(std::vector<User>, GetAdultUsers, (), (override));
		MOCK_METHOD(std::vector<User>, GetJuvenileUsers, (), (override));
		MOCK_METHOD(void, InsertUser, (const User& user), (override));
	};
}

TEST(TestProxy, ExpectSeviceToWorkCorrectly){
	Database db("db1.db");
	db.CreateTableIfNotExists();
	
	for(const auto& u : GetUsers()){
		db.InsertUser(u);
	}
	
	auto inserted_users = db.GetUsers();
	ExpectUsers(GetUsers(), inserted_users);
	
	auto inserted_adult_users = db.GetAdultUsers();
	ExpectUsers(GetAdultUsers(), inserted_adult_users);
	
	auto inserted_juvenile_users = db.GetJuvenileUsers();
	ExpectUsers(GetJuvenileUsers(), inserted_juvenile_users);
}

TEST(TestProxy, ExpectServiceMethodsToBeCalledOnce){
	std::unique_ptr<DatabaseMock> mock = std::make_unique<DatabaseMock>();
	EXPECT_CALL(*mock, GetUsers()).Times(1).WillOnce(::testing::Return(GetUsers()));
	EXPECT_CALL(*mock, GetAdultUsers()).Times(1).WillOnce(::testing::Return(GetAdultUsers()));
	EXPECT_CALL(*mock, GetJuvenileUsers()).Times(1).WillOnce(::testing::Return(GetJuvenileUsers()));
	
	DatabaseProxy proxy(std::move(mock));
	
	ExpectUsers(GetUsers(), proxy.GetUsers());
	ExpectUsers(GetUsers(), proxy.GetUsers());
	
	ExpectUsers(GetAdultUsers(), proxy.GetAdultUsers());
	ExpectUsers(GetAdultUsers(), proxy.GetAdultUsers());
	
	ExpectUsers(GetJuvenileUsers(), proxy.GetJuvenileUsers());
	ExpectUsers(GetJuvenileUsers(), proxy.GetJuvenileUsers());
}

TEST(TestProxy, ExpectProxyToCallServiceMethodsAfterUpdatingService){
	User new_user_1(5U, "Felix", 18);
	User new_user_2(6U, "Gilbert", 17);
	
	std::vector<User> more_users = GetUsers();
	more_users.push_back(new_user_1);
	more_users.push_back(new_user_2);
	
	std::vector<User> more_adult_users = GetAdultUsers();
	more_adult_users.push_back(new_user_1);
	
	std::vector<User> more_juvenile_users = GetAdultUsers();
	more_adult_users.push_back(new_user_2);
	
	std::unique_ptr<DatabaseMock> mock = std::make_unique<DatabaseMock>();
	EXPECT_CALL(*mock, GetUsers()).Times(2).WillOnce(::testing::Return(GetUsers())).WillOnce(::testing::Return(more_users));
	EXPECT_CALL(*mock, GetAdultUsers()).Times(2).WillOnce(::testing::Return(GetAdultUsers())).WillOnce(::testing::Return(more_adult_users));
	EXPECT_CALL(*mock, GetJuvenileUsers()).Times(2).WillOnce(::testing::Return(GetJuvenileUsers())).WillOnce(::testing::Return(more_juvenile_users));
	
	DatabaseProxy proxy(std::move(mock));
	
	ExpectUsers(GetUsers(), proxy.GetUsers());
	ExpectUsers(GetUsers(), proxy.GetUsers());
	
	ExpectUsers(GetAdultUsers(), proxy.GetAdultUsers());
	ExpectUsers(GetAdultUsers(), proxy.GetAdultUsers());
	
	ExpectUsers(GetJuvenileUsers(), proxy.GetJuvenileUsers());
	ExpectUsers(GetJuvenileUsers(), proxy.GetJuvenileUsers());
	
	proxy.InsertUser(new_user_1);
	proxy.InsertUser(new_user_2);
	
	ExpectUsers(more_users, proxy.GetUsers());
	ExpectUsers(more_users, proxy.GetUsers());
	
	ExpectUsers(more_adult_users, proxy.GetAdultUsers());
	ExpectUsers(more_adult_users, proxy.GetAdultUsers());
	
	ExpectUsers(more_juvenile_users, proxy.GetJuvenileUsers());
	ExpectUsers(more_juvenile_users, proxy.GetJuvenileUsers());
}
