
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
		"pizza_builder.hpp",
		"margherita_builder.hpp",
		"diavola_builder.hpp",
		"pizza_cook.hpp"
	],
	srcs = [
		"pizza_builder.cpp",
		"margherita_builder.cpp",
		"diavola_builder.cpp",
		"pizza_cook.cpp"
	]
)
