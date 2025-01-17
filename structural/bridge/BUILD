
cc_test(
	name = "test_bridge",
	srcs = [
		"test_bridge.cpp"
	],
	deps = [
		"device_implementations",
		"remote_implementation",
		"@googletest//:gtest",
		"@googletest//:gtest_main"
	]
)

cc_library(
	name = "device_implementations",
	hdrs = [
		"radio.hpp",
		"television.hpp"
	],
	srcs = [
		"radio.cpp",
		"television.cpp"
	],
	deps = [
		"device_interface"
	]
)

cc_library(
	name = "remote_implementation",
	hdrs = [
		"remote.hpp"
	],
	deps = [
		"device_interface"
	]
)

cc_library(
	name = "device_interface",
	hdrs = [
		"device.hpp"
	]
)
