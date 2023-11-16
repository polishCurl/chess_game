load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "position",
    srcs = ["src/piece_utilities/position.cpp"],
    hdrs = ["src/piece_utilities/position.hpp"],
    strip_include_prefix = "",
)

cc_library(
    name = "move",
    srcs = ["src/piece_utilities/move.cpp"],
    hdrs = ["src/piece_utilities/move.hpp"],
    strip_include_prefix = "",
    deps = [":position"],
)

cc_test(
    name = "position_test",
    srcs = ["test/piece_utilities/position_test.cpp"],
    deps = [
        ":position",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "move_test",
    srcs = ["test/piece_utilities/move_test.cpp"],
    deps = [
        ":move",
        "@googletest//:gtest_main",
    ],
)

cc_library(
    name = "piece",
    srcs = [
        "src/piece.cpp",
    ],
    hdrs = [
        "src/ipiece.hpp",
        "src/piece.hpp",
    ],
    strip_include_prefix = "",
    deps = [":move"],
)
