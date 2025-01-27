
cc_test(
	name = "test_proxy",
	srcs = [
		"test_proxy.cpp"
	],
	deps = [
		"matrix_library",
		"matrix_addition_library",
		"@googletest//:gtest",
		"@googletest//:gtest_main"
	]
)

cc_library(
	name = "matrix_addition_library",
	hdrs = [
		"matrix_addition.hpp",
	],
	deps = [
		"matrix_interface"
	]
)

cc_library(
	name = "matrix_library",
	hdrs = [
		"matrix.hpp"
	],
	deps = [
		"matrix_interface"
	]
)

cc_library(
	name = "matrix_interface",
	hdrs = [
		"matrix_interface.hpp"
	]
)
