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

cc_library(
    name = "king",
    srcs = [
        "src/king/king.cpp",
    ],
    hdrs = [
        "src/king/king.hpp",
    ],
    strip_include_prefix = "",
    deps = [":piece"],
)

cc_test(
    name = "king_test",
    srcs = ["test/king/king_test.cpp"],
    deps = [
        ":king",
        "@googletest//:gtest_main",
    ],
)

cc_library(
    name = "queen",
    srcs = [
        "src/queen/queen.cpp",
    ],
    hdrs = [
        "src/queen/queen.hpp",
    ],
    strip_include_prefix = "",
    deps = [":piece"],
)

cc_test(
    name = "queen_test",
    srcs = ["test/queen/queen_test.cpp"],
    deps = [
        ":queen",
        "@googletest//:gtest_main",
    ],
)
