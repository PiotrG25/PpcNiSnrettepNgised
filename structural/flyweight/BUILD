
cc_test(
	name = "test_flyweight",
	srcs = [
		"test_flyweight.cpp"
	],
	deps = [
		"flyweight_pizza",
		"heavyweight_pizza",
		"@googletest//:gtest",
		"@googletest//:gtest_main"
	]
)

cc_library(
	name = "flyweight_pizza",
	hdrs = [
		"pizza_type.hpp",
		"pizza.hpp"
	],
	deps = [
		"enums"
	]
)

cc_library(
	name = "heavyweight_pizza",
	hdrs = [
		"heavyweight_pizza.hpp"
	],
	deps = [
		"enums"
	]
)

cc_library(
	name = "enums",
	hdrs = [
		"enums.hpp"
	]
)
