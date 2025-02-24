
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
		"data_source.hpp",
		"string_data_source.hpp",
		"file_handler.hpp",
		"encrypter.hpp",
		"encoder.hpp"
	]
)
