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
        "src/chessboard.cpp",
    ],
    hdrs = [
        "src/chessboard.hpp",
    ],
    strip_include_prefix = "",
    deps = [
        ":chessboard_interface",
        "//piece:piece_factory",
    ],
)