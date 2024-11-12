
cc_test(
	name = "test_abstract_factory",
	srcs = [
		"test_abstract_factory.cpp"
	],
	deps = [
		"//creational/abstract_factory:car_parts_factories",
		"@googletest//:gtest",
		"@googletest//:gtest_main"
	]
)

cc_library(
	name = "car_parts_factories",
	hdrs = [
		"car_parts_factory.hpp",
		"super_car_parts_factory.hpp",
		"standard_car_parts_factory.hpp"
	],
	deps = [
		"//creational/abstract_factory:engines",
		"//creational/abstract_factory:bodies"
	],
	visibility = ["//visibility:public"]
)

cc_library(
	name = "engines",
	hdrs = [
		"engine.hpp",
		"standard_engine.hpp",
		"super_engine.hpp"
	]
)

cc_library(
	name = "bodies",
	hdrs = [
		"body.hpp",
		"standard_body.hpp",
		"super_body.hpp"
	]
)
