
cc_test(
	name = "test_adapter",
	srcs = [
		"test_adapter.cpp"
	],
	deps = [
		"//structural/adapter:adapter_library",
		"@googletest//:gtest",
		"@googletest//:gtest_main"
	]
)

cc_library(
	name = "adapter_library",
	hdrs = [
		"american_plug.hpp",
		"european_plug.hpp",
		"american_to_european_plug_adapter.hpp",
		"european_to_american_plug_adapter.hpp"
	]
)
