load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "piece_utilities",
    srcs = ["src/piece_utilities/piece_utilities.cpp"],
    hdrs = ["src/piece_utilities/piece_utilities.hpp"],
    strip_include_prefix = "",
)

cc_library(
    name = "piece",
    srcs = ["src/piece.hpp"],
    strip_include_prefix = "",
    deps = [":piece_utilities"],
)
