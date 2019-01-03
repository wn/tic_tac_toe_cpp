cc_library(
    name = "Game",
    srcs = ["Game.cc"],
    hdrs = ["Game.h", "Cell.h", "Player.h"],
)

cc_library(
    name = "Cell",
    srcs = ["Cell.cc"],
    hdrs = ["Cell.h", "Player.h"],
)

cc_binary(
    name = "tic_tac_toe",
    srcs = ["tic_tac_toe.cpp"],
    deps = [
        ":Game", ":Cell"
    ],
)
