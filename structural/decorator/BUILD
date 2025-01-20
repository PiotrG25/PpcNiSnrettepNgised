
cc_test(
	name = "test_decorator",
	srcs = [
		"test_decorator.cpp"
	],
	deps = [
		"decorator_library",
		"@googletest//:gtest",
		"@googletest//:gtest_main"
	]
)

cc_library(
	name = "decorator_library",
	hdrs = [
		"pizza.hpp",
		"pizza_base.hpp",
		"custom_pizza.hpp",
		"tomato_sauce_pizza.hpp",
		"cheese_pizza.hpp",
		"salami_pizza.hpp"
	]
)
