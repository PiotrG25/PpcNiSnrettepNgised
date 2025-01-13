
cc_test(
	name = "test_bridge",
	srcs = [
		"test_bridge.cpp"
	],
	deps = [
		"//structural/bridge:bridge_library",
		"@googletest//:gtest",
		"@googletest//:gtest_main"
	]
)

cc_library(
	name = "bridge_library",
	hdrs = [
		"device.hpp",
		"remote.hpp",
		"radio.hpp",
		"television.hpp"
	],
	srcs = [
		"radio.cpp",
		"television.cpp"
	]
)
