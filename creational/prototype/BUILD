
cc_test(
	name = "test_prototype",
	srcs = [
		"test_prototype.cpp"
	],
	deps = [
		"client_implementation",
		"waiter_implementation",
		"@googletest//:gtest",
		"@googletest//:gtest_main"
   ]
)

cc_library(
	name = "client_implementation",
	srcs = [
		"client.cpp"
	],
	deps = [
		"client_interface",
		"prototype_pizza_implementations"
	]
)

cc_library(
	name = "client_interface",
	hdrs = [
		"client.hpp"
	],
	deps = [
		"prototype_pizza_interface",
		"waiter_interface"
	]
)

cc_library(
	name = "waiter_implementation",
	srcs = [
		"waiter.cpp"
	],
	deps = [
		"waiter_interface",
		"prototype_pizza_implementations"
	]
)

cc_library(
	name = "waiter_interface",
	hdrs = [
		"waiter.hpp"
	],
	deps = [
		"prototype_pizza_interface"
	]
)

cc_library(
	name = "prototype_pizza_implementations",
	hdrs = [
		"diavola.hpp",
		"vege.hpp",
		"undefined_pizza.hpp"
	],
	deps = [
		"prototype_pizza_interface"
	]
)

cc_library(
	name = "prototype_pizza_interface",
	hdrs = [
		"prototype_pizza.hpp"
	]
)
