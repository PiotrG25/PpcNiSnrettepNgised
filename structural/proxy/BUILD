
cc_test(
	name = "test_proxy",
	srcs = [
		"test_proxy.cpp"
	],
	deps = [
		"proxy_implementation",
		"@googletest//:gtest",
		"@googletest//:gtest_main"
	]
)

cc_library(
	name = "proxy_implementation",
	hdrs = [
		"database_proxy.hpp",
		"database.hpp"
	],
	deps = [
		"database_interface",
		"@sqlite3//:sqlite3",
		"@boost.optional"
	]
)

cc_library(
	name = "database_interface",
	hdrs = [
		"user.hpp",
		"database_interface.hpp"
	]
)
