cc_library(
    name = "date_interface",
    srcs = [
    ],
    hdrs = [
        "src/date/idate.hpp",
    ],
    strip_include_prefix = "",
)

cc_library(
    name = "date",
    srcs = [
        "src/date/date.cpp",
    ],
    hdrs = [
        "src/date/date.hpp",
    ],
    strip_include_prefix = "",
    deps = [":date_interface"],
)

cc_test(
    name = "date_test",
    srcs = ["test/date/date_test.cpp"],
    deps = [
        ":date",
        "@googletest//:gtest_main",
    ],
)
