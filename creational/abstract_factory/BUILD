
cc_test(
	name = "test_abstract_factory",
	srcs = [
		"test_abstract_factory.cpp"
	],
	deps = [
		"car_parts_factory_implementation",
		"@googletest//:gtest",
		"@googletest//:gtest_main"
	]
)

cc_library(
	name = "car_parts_factory_implementation",
	hdrs = [
		"super_car_parts_factory.hpp",
		"standard_car_parts_factory.hpp"
	],
	deps = [
		"car_parts_factory_interface",
		"engine_implementations",
		"body_implementations"
	]
)

cc_library(
	name = "car_parts_factory_interface",
	hdrs = [
		"car_parts_factory.hpp"
	],
	deps = [
		"engine_interface",
		"body_interface"
	]
)

cc_library(
	name = "engine_interface",
	hdrs = [
		"engine.hpp"
	]
)

cc_library(
	name = "engine_implementations",
	hdrs = [
		"standard_engine.hpp",
		"super_engine.hpp"
	],
	deps = [
		"engine_interface"
	]
)

cc_library(
	name = "body_interface",
	hdrs = [
		"body.hpp"
	]
)

cc_library(
	name = "body_implementations",
	hdrs = [
		"standard_body.hpp",
		"super_body.hpp"
	],
	deps = [
		"body_interface"
	]
)
