cc_library(
    name = "chessboard_interface",
    srcs = [
    ],
    hdrs = [
        "src/ichessboard.hpp",
    ],
    strip_include_prefix = "",
    deps = [
        "//common:move",
        "//piece:piece_interface",
    ],
)

cc_library(
    name = "chessboard",
    srcs = [
        "src/chessboard/chessboard.cpp",
    ],
    hdrs = [
        "src/chessboard/chessboard.hpp",
    ],
    strip_include_prefix = "",
    deps = [
        ":chessboard_interface",
        "//piece:piece_factory",
    ],
)

cc_test(
    name = "chessboard_test",
    srcs = ["test/chessboard/chessboard_test.cpp"],
    deps = [
        ":chessboard",
        "@googletest//:gtest_main",
    ],
)

cc_library(
    name = "chessboard_mock",
    testonly = True,
    hdrs = [
        "mock/chessboard_mock.hpp",
    ],
    strip_include_prefix = "",
    deps = [
        "chessboard_interface",
        "@googletest//:gtest_main",
    ],
)
