
cc_test(
	name = "test_command",
	srcs = [
		"test_command.cpp"
	],
	deps = [
		"@googletest//:gtest",
		"@googletest//:gtest_main",
		"client_implementation",
		"restaurant_waiters_implementation",
		"waiter_implementation",
		"restaurant_kitchen_implementation",
		"cook_implementation"
	]
)

cc_library(
	name = "cook_implementation",
	srcs = [
		"cook.cpp"
	],
	deps = [
		"cook_interface"
	]
)

cc_library(
	name = "cook_interface",
	hdrs = [
		"cook.hpp"
	],
	deps = [
		"restaurant_kitchen_interface",
		"command_interface"
	]
)

cc_library(
	name = "client_implementation",
	srcs = [
		"client.cpp"
	],
	deps = [
		"client_interface",
		"command_implementation"
	]
)

cc_library(
	name = "client_interface",
	hdrs = [
		"client.hpp"
	],
	deps = [
		"restaurant_waiters_interface"
	]
)

cc_library(
	name = "restaurant_waiters_implementation",
	srcs = [
		"restaurant_waiters.cpp"
	],
	deps = [
		"restaurant_waiters_interface"
	]
)

cc_library(
	name = "restaurant_waiters_interface",
	hdrs = [
		"restaurant_waiters.hpp"
	],
	deps = [
		"waiter_interface"
	]
)

cc_library(
	name = "waiter_implementation",
	srcs = [
		"waiter.cpp"
	],
	deps = [
		"waiter_interface"
	]
)

cc_library(
	name = "waiter_interface",
	hdrs = [
		"waiter.hpp"
	],
	deps = [
		"command_interface",
		"restaurant_kitchen_interface"
	]
)

cc_library(
	name = "restaurant_kitchen_implementation",
	srcs = [
		"restaurant_kitchen.cpp"
	],
	deps = [
		"restaurant_kitchen_interface"
	]
)

cc_library(
	name = "restaurant_kitchen_interface",
	hdrs = [
		"restaurant_kitchen.hpp"
	],
	deps = [
		"pizza_interface",
		"command_interface"
	]
)

cc_library(
	name = "command_implementation",
	hdrs = [
		"margherita_command.hpp",
		"pepperoni_command.hpp"
	],
	deps = [
		"command_interface",
		"pizza_implementation"
	]
)

cc_library(
	name = "command_interface",
	hdrs = [
		"command.hpp"
	],
	deps = [
		"pizza_interface"
	]
)

cc_library(
	name = "pizza_implementation",
	hdrs = [
		"margherita_pizza.hpp",
		"pepperoni_pizza.hpp"
	],
	deps = [
		"pizza_interface"
	]
)

cc_library(
	name = "pizza_interface",
	hdrs = [
		"pizza.hpp"
	]
)