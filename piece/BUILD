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
    name = "piece_interface",
    srcs = [
    ],
    hdrs = [
        "src/ipiece.hpp",
    ],
    strip_include_prefix = "",
    deps = [":move"],
)

cc_library(
    name = "piece",
    srcs = [
        "src/piece.cpp",
    ],
    hdrs = [
        "src/piece.hpp",
    ],
    strip_include_prefix = "",
    deps = [":piece_interface"],
)

cc_library(
    name = "piece_mock",
    testonly = True,
    hdrs = [
        "mock/piece_mock.hpp",
    ],
    strip_include_prefix = "",
    deps = [
        "piece_interface",
        "@googletest//:gtest_main",
    ],
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

cc_library(
    name = "rook",
    srcs = [
        "src/rook/rook.cpp",
    ],
    hdrs = [
        "src/rook/rook.hpp",
    ],
    strip_include_prefix = "",
    deps = [":piece"],
)

cc_test(
    name = "rook_test",
    srcs = ["test/rook/rook_test.cpp"],
    deps = [
        ":rook",
        "@googletest//:gtest_main",
    ],
)

cc_library(
    name = "bishop",
    srcs = [
        "src/bishop/bishop.cpp",
    ],
    hdrs = [
        "src/bishop/bishop.hpp",
    ],
    strip_include_prefix = "",
    deps = [":piece"],
)

cc_test(
    name = "bishop_test",
    srcs = ["test/bishop/bishop_test.cpp"],
    deps = [
        ":bishop",
        "@googletest//:gtest_main",
    ],
)

cc_library(
    name = "knight",
    srcs = [
        "src/knight/knight.cpp",
    ],
    hdrs = [
        "src/knight/knight.hpp",
    ],
    strip_include_prefix = "",
    deps = [":piece"],
)

cc_test(
    name = "knight_test",
    srcs = ["test/knight/knight_test.cpp"],
    deps = [
        ":knight",
        "@googletest//:gtest_main",
    ],
)

cc_library(
    name = "pawn",
    srcs = [
        "src/pawn/pawn.cpp",
    ],
    hdrs = [
        "src/pawn/pawn.hpp",
    ],
    strip_include_prefix = "",
    deps = [":piece"],
)

cc_test(
    name = "pawn_test",
    srcs = ["test/pawn/pawn_test.cpp"],
    deps = [
        ":pawn",
        "@googletest//:gtest_main",
    ],
)

cc_library(
    name = "piece_factory",
    srcs = [
        "src/piece_factory/piece_factory.cpp",
    ],
    hdrs = [
        "src/piece_factory/ipiece_factory.hpp",
        "src/piece_factory/piece_factory.hpp",
    ],
    strip_include_prefix = "",
    deps = [
        ":bishop",
        ":king",
        ":knight",
        ":pawn",
        ":piece",
        ":queen",
        ":rook",
    ],
)

cc_test(
    name = "piece_factory_test",
    srcs = ["test/piece_factory/piece_factory_test.cpp"],
    deps = [
        ":piece_factory",
        "@googletest//:gtest_main",
    ],
)
