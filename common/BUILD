load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "position",
    srcs = ["src/position/position.cpp"],
    hdrs = ["src/position/position.hpp"],
    strip_include_prefix = "",
    visibility = ["//piece:__subpackages__"],
)

cc_library(
    name = "color",
    srcs = ["src/color/color.cpp"],
    hdrs = ["src/color/color.hpp"],
    strip_include_prefix = "",
    visibility = ["//piece:__subpackages__"],
)

cc_library(
    name = "move",
    srcs = ["src/move/move.cpp"],
    hdrs = ["src/move/move.hpp"],
    strip_include_prefix = "",
    visibility = ["//piece:__subpackages__"],
    deps = [
        ":color",
        ":position",
    ],
)

cc_test(
    name = "position_test",
    srcs = ["test/position/position_test.cpp"],
    deps = [
        ":position",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "color_test",
    srcs = ["test/color/color_test.cpp"],
    deps = [
        ":color",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "move_test",
    srcs = ["test/move/move_test.cpp"],
    deps = [
        ":move",
        "@googletest//:gtest_main",
    ],
)
