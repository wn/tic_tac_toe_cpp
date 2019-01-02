# Tic-tac-toe CLI Game

A tic-tac-toe CLI game written in C++. To compile the game, use bazel or make. If you are using bazel, please install bazel by following the guide [here](https://docs.bazel.build/versions/master/install.html).

### Build project using bazel
```
bazel build //main:tic_tac_toe

// Run game
bazel-bin/main/tic_tac_toe

// To clean build files
bazel clean
```

### Build project using make
```
// Change directory to folder containing cpp file
cd tic_tac_toe_cpp/main/

// Create compiled file
make
// Play game
./ttt

// Clean up folder
make clean
```
