
cc_test(
	name = "test_factory_method",
	srcs = [
		"test_factory_method.cpp"
	],
	deps = [
		"//creational/factory_method:car_factory",
		"@googletest//:gtest",
		"@googletest//:gtest_main"
   ]
)

cc_library(
	name = "car_factory",
	hdrs = [
		"car_factory.hpp",
		"car.hpp",
		"standard_car.hpp",
		"super_car.hpp"
	]
)
