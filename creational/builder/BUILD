
cc_test(
	name = "test_builder",
	srcs = [
		"test_builder.cpp"
	],
	deps = [
		"//creational/builder:pizza_library",
		"@googletest//:gtest",
		"@googletest//:gtest_main"
   ]
)

cc_library(
	name = "pizza_library",
	hdrs = [
		"pizza.hpp",
		"pizza_cook.hpp",
		"pizza_builder.hpp"
	],
	srcs = [
		"pizza_cook.cpp"
	]
)
