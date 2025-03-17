
#include <gtest/gtest.h>
#include "login_finder.hpp"
#include "password_verifier.hpp"

TEST(TestChainOfResponsibility, ExpectLoginFinderWorksCorrectly){
	std::unique_ptr<HandlerInterface> handler = std::make_unique<LoginFinder>();

	ResponseCode result;

	Request r1("login1", "password1");
	result = handler->handle(r1);
	EXPECT_EQ(ResponseCode::SUCCESS, result);

	Request r2("login2", "password2");
	result = handler->handle(r2);
	EXPECT_EQ(ResponseCode::SUCCESS, result);

	Request r3("login3", "password3");
	result = handler->handle(r3);
	EXPECT_EQ(ResponseCode::BAD_LOGIN, result);
}

TEST(TestChainOfResponsibility, ExpectPasswordVerifierWorksCorrectly){
	std::unique_ptr<HandlerInterface> handler = std::make_unique<PasswordVerifier>();

	ResponseCode result;

	Request r1("login1", "password1");
	result = handler->handle(r1);
	EXPECT_EQ(ResponseCode::SUCCESS, result);

	Request r2("login2", "password2");
	result = handler->handle(r2);
	EXPECT_EQ(ResponseCode::SUCCESS, result);

	Request r3("login2", "password3");
	result = handler->handle(r3);
	EXPECT_EQ(ResponseCode::BAD_PASSWORD, result);
}

TEST(TestChainOfResponsibility, ExpectChainOfResponsibilityReturnsCorrectResults){
	std::unique_ptr<HandlerInterface> handler = std::make_unique<LoginFinder>();
	std::unique_ptr<HandlerInterface> verifier = std::make_unique<PasswordVerifier>();
	handler->setNext(std::move(verifier));

	ResponseCode result;

	Request r1("login1", "password1");
	result = handler->handle(r1);
	EXPECT_EQ(ResponseCode::SUCCESS, result);

	Request r2("login2", "password1");
	result = handler->handle(r2);
	EXPECT_EQ(ResponseCode::BAD_PASSWORD, result);

	Request r3("login3", "password3");
	result = handler->handle(r3);
	EXPECT_EQ(ResponseCode::BAD_LOGIN, result);
}

