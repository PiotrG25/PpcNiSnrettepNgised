
cc_test(
	name = "test_chain_of_responsibility",
	srcs = [
		"test_chain_of_responsibility.cpp"
	],
	deps = [
		"@googletest//:gtest",
		"@googletest//:gtest_main",
		"login_finder_implementation",
		"password_verifier_implementation"
	]
)


cc_library(
	name = "password_verifier_implementation",
	hdrs = [
		"password_verifier.hpp"
	],
	srcs = [
		"password_verifier.cpp"
	],
	deps = [
		"handler_base_implementation",
		"user_database",
		"//third_party/libbcrypt:bcrypt"
	]
)

cc_library(
	name = "login_finder_implementation",
	hdrs = [
		"login_finder.hpp"
	],
	srcs = [
		"login_finder.cpp"
	],
	deps = [
		"handler_base_implementation",
		"user_database"
	]
)

cc_library(
	name = "user_database",
	hdrs = [
		"user_database.hpp"
	],
	srcs = [
		"user_database.cpp"
	]
)

cc_library(
	name = "handler_base_implementation",
	hdrs = [
		"handler.hpp"
	],
	deps = [
		"handler_interface"
	]
)

cc_library(
	name = "handler_interface",
	hdrs = [
		"handler_interface.hpp",
		"response_code.hpp",
		"request.hpp"
	]
)
