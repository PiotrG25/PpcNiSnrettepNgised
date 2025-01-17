
cc_test(
	name = "test_composite",
	srcs = [
		"test_composite.cpp"
	],
	deps = [
		"printable_implementations",
		"@googletest//:gtest",
		"@googletest//:gtest_main"
	]
)

cc_library(
	name = "printable_implementations",
	hdrs = [
		"letter.hpp",
		"word.hpp",
		"whitespace.hpp",
		"paragraph.hpp"
	],
	deps = [
		"printable_interface"
	]
)

cc_library(
	name = "printable_interface",
	hdrs = [
		"printable.hpp"
	]
)
