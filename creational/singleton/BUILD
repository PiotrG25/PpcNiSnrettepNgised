
cc_test(
	name = "test_singleton",
	srcs = [
		"test_singleton.cpp"
	],
	deps = [
		"//creational/singleton:pointer_singleton",
		"//creational/singleton:meyers_singleton",
		"@googletest//:gtest",
		"@googletest//:gtest_main"
   ]
)

cc_library(
	name = "pointer_singleton",
	hdrs = [
		"pointer_singleton.hpp"
	],
	srcs = [
		"pointer_singleton.cpp"
	]
)

cc_library(
	name = "meyers_singleton",
	hdrs = [
		"meyers_singleton.hpp"
	],
	srcs = [
		"meyers_singleton.cpp"
	]
)
