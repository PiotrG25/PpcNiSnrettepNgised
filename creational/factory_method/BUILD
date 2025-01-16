
cc_test(
	name = "test_factory_method",
	srcs = [
		"test_factory_method.cpp"
	],
	deps = [
		"car_factory_implementation",
		"@googletest//:gtest",
		"@googletest//:gtest_main"
   ]
)

cc_library(
	name = "car_factory_implementation",
	srcs = [
		"car_factory.cpp"
	],
	deps = [
		"car_factory_interface",
		"car_implementations"
	]
)

cc_library(
	name = "car_factory_interface",
	hdrs = [
		"car_factory.hpp",
	],
	deps = [
		"car_interface"
	]
)

cc_library(
	name = "car_implementations",
	hdrs = [
		"standard_car.hpp",
		"super_car.hpp"
	],
	srcs = [
		"standard_car.cpp",
		"super_car.cpp"
	],
	deps = [
		"car_interface"
	]
)

cc_library(
	name = "car_interface",
	hdrs = [
		"car.hpp"
	]
)
