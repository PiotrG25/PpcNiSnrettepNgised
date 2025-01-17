
cc_test(
	name = "test_adapter",
	srcs = [
		"test_adapter.cpp"
	],
	deps = [
		"european_plug_implementations",
		"american_plug_implementations",
		"@googletest//:gtest",
		"@googletest//:gtest_main"
	]
)

cc_library(
	name = "european_plug_implementations",
	hdrs = [
		"european_plug.hpp",
		"american_to_european_plug_adapter.hpp"
	],
	deps = [
		"european_plug_interface",
		"american_plug_interface"
	]
)

cc_library(
	name = "american_plug_implementations",
	hdrs = [
		"american_plug.hpp",
		"european_to_american_plug_adapter.hpp"
	],
	deps = [
		"european_plug_interface",
		"american_plug_interface"
	]
)

cc_library(
	name = "european_plug_interface",
	hdrs = [
		"european_plug_interface.hpp"
	]
)

cc_library(
	name = "american_plug_interface",
	hdrs = [
		"american_plug_interface.hpp"
	]
)
